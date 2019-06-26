#include <linux/gpio.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of_gpio.h>
#include <linux/string.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_irq.h>
//License===================================================
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Projektgruppe 9");
MODULE_DESCRIPTION("Driver til read/write på gpio port");
// Variables==================================================
#define MINOR_NBR 255
#define nbr_devices 1
//globalt device nummer
static dev_t devno;
const int minor_no = 0;
int gpio_devs_cnt = 0;
//sleep function ===========================================
static DECLARE_WAIT_QUEUE_HEAD(waitQueue);
#define IRQF_TRIGGER_RISING 0x00000001
#define IRQF_TRIGGER_FALLING 0x00000002
void* dev_id = NULL;
//Prototypes============================================
static int platDriver_init(void);
static int platDriver_probe (struct platform_device *pdev);
int platDriver_open(struct inode *inode, struct file *filep);
int platDriver_release(struct inode *inode, struct file *filep);
ssize_t platDriver_read(struct file *filep, char __user *buf, size_t count, loff_t *f_pos);
ssize_t platDriver_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos);
static int platDriver_remove(struct platform_device *pdev);
static void platDriver_exit(void);
//Structs====================================================

static struct class *plat_drv_class;
//globalt character device struct
static struct cdev plat_drv_cdev;
struct device *my_device;
//Her angivet .compatible hvilke driver vores device er kompatible med
static const struct of_device_id my_plat_drv [] ={
  { .compatible = "ase, plat_drv",}, {},
};
//globalt platform driver der laves med platform_register. med vores probe og remobe funktioner. 
// altså hvad skal for en probe funktion skal den kalde når der er en driver og et device som er kompatible 
// hvad for en remove funktion skal den kalde, når den fjernes igen.
//.name er navnet på den device hvoraf vi skal fyre op for vores probe funktion. den ligger under driver {}.
// bruger of_match_table forskellige en liste af devices som passer til den samme driver
//call back funktioner med system states
static struct platform_driver plat_drv_platform_driver ={
  .probe = platDriver_probe ,
  .remove = platDriver_remove,
  .driver = {
  .name = "plat_drv",
  .of_match_table = my_plat_drv,
  .owner = THIS_MODULE,
  },
};
//globalt file operations struct 
struct file_operations plat_drv_fops = {
    .owner = THIS_MODULE,
    .read = platDriver_read,
    .write = platDriver_write,
    //.open = platDriver_open,
    //.release = platDriver_release,
};
struct gpio_dev {
  int no;   // GPIO number
  int dir; // 0: in, 1: out
  //char name[50]; //GPIO name
};
static struct gpio_dev gpio_devs[255] = {};
//Init function ========================================
static int platDriver_init(void){
  int err = 0;
  //allokere et majornumber og retunere et minor nummer (device nummer) starter ved minor nummer 0 og reservere 255 minor numre.
  // med navnet "plat_drv" device nummeret er lavet globalt altså &devno da det bruges i exit funktionen
  err = alloc_chrdev_region(&devno, 0, 255, "plat_drv");
  //vi fejlfinder 
  if(err<0)
  {
    goto err_exit;
  }
  //vi initialisere vores character driver struct med vores file operations struct, bliver først defineret efter vores read/write funktioner
  //cdev add adder vi vores character device struct, vores device nummer, 255 er antallet af device der kommer til at være. Hvilket 
  // giver os en binding mellem vores device nummer altså vore major minor nummer og vores character devicet og dermed også vores file operations
  cdev_init(&plat_drv_cdev, &plat_drv_fops);
  err = cdev_add(&plat_drv_cdev, devno, 255);
  //fejl håndtering hvis det ikke kan addes
  if (err < 0) // Register driver with kernel
    {
      goto err_dev_unregister;
    }
  //vi opretter en platform driver klasse med class_create, som taget det navn vi giver den "plat_drv_class". hvilket nu kommer under 
  // /sys/class. kommer nu en klasse med vores navn
  plat_drv_class = class_create(THIS_MODULE, "plat_drv_class");
  // igen fejl håndtering således vi sletter det allokerede data hvis det ikke er muligt
  if (err<0)
  {
    goto err_cleanup_cdev;
  }
// til sidst laves en platform_driver_register, fortæller vores system at den her driver er en platform driver. hvor vi angiver vores probe og remove funktioner
err = platform_driver_register(&plat_drv_platform_driver);
if (err < 0) {
  goto err_cleanup_class;
}
printk(KERN_ALERT "Add OK\n");

return 0; // Success!!!

err_dev_unregister:
    unregister_chrdev_region(devno, nbr_devices);
    printk(KERN_ALERT "Unregister chrdrev\n");

err_cleanup_cdev:
    cdev_del(&plat_drv_cdev);
    printk(KERN_ALERT "Delete c_dev\n");

err_cleanup_class:
    class_destroy(plat_drv_class);
    printk(KERN_ALERT "Destroy plat_drv_class\n");

  // Release resources which were acquired
  err_exit:
    return err;

return 0;
}
//probe() funktion ===================================================
//probe funktion bliver kaldt systemet finder en device og en driver med samme navn altså de er kompatible. probe lavet et nyt device.
//deamon i udev ser der er operette et nyt device i /sys/class hvilket den så vil oprettet et nyt device under /dev
//kan registerer en gpio med device_Create. 
static int platDriver_probe (struct platform_device *pdev){
  struct device *dev = &pdev -> dev; // Device ptr derived from current platform_device
  struct device_node *np = dev -> of_node; // Device tree node ptr
  enum gpio_flags {dir};
  int err = 0;
  int gpios_in_dts = of_gpio_count(np);
  //char new_name[50];
  for (size_t i = 0; i < gpios_in_dts; i++) {
    //Get GPIO #, direction from DT, and give name according to minor num
    gpio_devs[i].no = of_get_gpio(np,i);
    gpio_devs[i].dir = of_get_gpio_flags(np, i, dir);

    //sprintf(new_name, "gpio%d",gpio_devs[i].no);
    //strcpy(gpio_devs[i].name,new_name);
    //Request gpio

    err = gpio_request(gpio_devs[i].no, NULL);
    if (err < 0) {
      goto err_exit;
    }
    if (gpio_devs[i].dir == 0) {
      err = gpio_direction_output(gpio_devs[i].no, gpio_devs[i].dir);
    }
    else {
      err = gpio_direction_input(gpio_devs[i].no);
    }
    if (err < 0) {
      goto err_exit;
    }

    printk(KERN_INFO "gpio%d requested with GPIO number: %d and direction %d\n", gpio_devs[i].no, gpio_devs[i].no, gpio_devs[i].dir);
    //device create opretter vores device under vores klasse. deamon opretter nu vores node i /dev med samme navnet gpio, og gpio nummeret
    my_device = device_create(plat_drv_class, NULL, MKDEV(MAJOR(devno), i), NULL, "gpio%d", gpio_devs[i].no);
    printk("Created /dev/gpio%d with major number: %d and minor number: %d \n", gpio_devs[i].no, MAJOR(devno), i);
    gpio_devs_cnt++;
  }

  return 0; //success

  err_exit:
    //Free GPIO
    for (size_t i = 0; i < gpio_devs_cnt; i++){
      gpio_free(gpio_devs[i].no);
      printk(KERN_ALERT"GPIO %d released\n", gpio_devs[i].no);
    }

  return err;
  }
//Open function ==================================================
int platDriver_open(struct inode *inode, struct file *filep){
    int major, minor;
    major = MAJOR(inode->i_rdev);
    minor = MINOR(inode->i_rdev);
    printk("Opening MyGpio Device [major], [minor]: %i, %i\n", major, minor);
    return 0;
}
//Release function ================================================
int platDriver_release(struct inode *inode, struct file *filep){
    int minor, major;
    major = MAJOR(inode->i_rdev);
    minor = MINOR(inode->i_rdev);
    printk("Closing/Releasing MyGpio Device [major], [minor]: %i, %i\n", major, minor);
    return 0;
}
//Read function ==================================================
ssize_t platDriver_read(struct file *filep, char __user *buf, size_t count, loff_t *f_pos){

  int err, len;
  //udlæser minor nummertet
  int minor = iminor(filep -> f_inode);
  //tager vores value på vores gpio pind
  int value = gpio_get_value(gpio_devs[minor].no);
  char buff[32];
  //formater vores integer om til en string
  sprintf(buff, "%d", value);
  len = strlen(buff)+1;
  if(len > count){
    len = count;
  }
  //kopier vores strin til userspace, den kan anvendes hvad vi læser på vores hardware
  err = copy_to_user(buf, buff, len);
  if(err < 0){
     printk("Error in copy to user\n");
  }
  // opdater vores file pointer til at gå det givet længde vi har læst videre ind. 
  *f_pos += len;
  // retunere længden
  return len;
}
//write function ===================================================
//som vi kender. vi får noget data fra userspace. vi tjekker længden, kopier data fra userspace, hiver en inter ud af vores string
ssize_t platDriver_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos){
    int minor, err, value;
    char buf[32];
   //udlæser minor nummertet
    minor = iminor(filep -> f_inode);
    printk(KERN_ALERT "Writing to plat_drv minor: %i \n", minor);
    err = copy_from_user(buf, ubuf, count);
    if(err < 0){
        printk("Error in copy from user\n");
        return err;
    }
  // hiver en integer ud af vores string fra userspace
    sscanf(buf, "%d", &value);
  // sætter vores gpio værdi efter intergeren fra vores string i userpsace 
    gpio_set_value(gpio_devs[minor].no, value);

    *f_pos += count;
  // retuner de faktisk skrevet bytes
    return count;
}
////remove() function ================================================
// hvis devicet forsvinder igen altså når vi unloader vores driver. hvor vi device fjernes igen bruger vores platform klasse og device nummeret, hvor den så ser hvilket device det er.
static int platDriver_remove(struct platform_device *pdev){
  for (size_t i = 0; i < gpio_devs_cnt; i++) {
    device_destroy(plat_drv_class, MKDEV(MAJOR(devno), i));
    gpio_free(gpio_devs[i].no);
    printk(KERN_INFO"gpio%d destroyed, Major = %d, minor = %d and GPIO %d released\n", gpio_devs[i].no, MAJOR(devno), i, gpio_devs[i].no);
  }
  printk(KERN_ALERT"All devices has been removed\n");
  return 0;
}
//Exit function ===================================================
// gør det modsatte af vores init funktion hvor vi når vi rmmoder vores platform driver ryder vi op efter os selv
static void platDriver_exit(void) {
  cdev_del(&plat_drv_cdev);
  class_destroy(plat_drv_class);
  platform_driver_unregister(&plat_drv_platform_driver);
  unregister_chrdev_region(devno, nbr_devices);
  printk(KERN_ALERT "Module exit\n");
}
// fortæller hvornår init og vores exit funktioner skal kaldes, altså når vi indsætter vores device driver med insmod og rmmod. 
 module_init(platDriver_init);
 module_exit(platDriver_exit);
