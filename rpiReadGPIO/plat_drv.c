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
//Interrupt rutine
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/sched.h>
//License===================================================
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hallal");
MODULE_DESCRIPTION("Hot-pluggable device driver");
// Variables==================================================
#define MINOR_NBR 255
#define nbr_devices 1
static dev_t devno;
const int minor_no = 0;
int gpio_devs_cnt = 0;
//sleep function ===========================================
static int flag = 0;
static DECLARE_WAIT_QUEUE_HEAD(waitQueue);

//ISR rutine implementering
#define IRQF_TRIGGER_NONE 0x00000000
#define IRQF_TRIGGER_RISING 0x00000001
#define IRQF_TRIGGER_FALLING 0x00000002
#define IRQF_TRIGGER_HIGH 0x00000004
#define IRQF_TRIGGER_LOW 0x00000008
static unsigned int irq_no = 0;
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
static struct cdev plat_drv_cdev;
struct device *my_device;
static const struct of_device_id my_plat_drv [] ={
  { .compatible = "ase, plat_drv",}, {},
};
static struct platform_driver plat_drv_platform_driver ={
  .probe = platDriver_probe ,
  .remove = platDriver_remove,
  .driver = {
  .name = "plat_drv",
  .of_match_table = my_plat_drv,
  .owner = THIS_MODULE,
  },
};
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

//interrupt rutine
static irqreturn_t sonarinputDriver_isr(int irq, void *dev_id)
{
  printk("irq event at irq line: %i\n", irq_no);
  printk("Process %i (%s) awakening the readers...\n", current->pid, current->comm);
  flag = 1;
  wake_up_interruptible(&waitQueue);
  return IRQ_HANDLED;
}
//Implementering=======================================
//Init function ========================================
static int platDriver_init(void){
  int err = 0;
  err = alloc_chrdev_region(&devno, 0, 255, "plat_drv");
  if(err<0)
  {
    goto err_exit;
  }

  cdev_init(&plat_drv_cdev, &plat_drv_fops);
  err = cdev_add(&plat_drv_cdev, devno, 255);
  if (err < 0) // Register driver with kernel
    {
      goto err_dev_unregister;
    }

  plat_drv_class = class_create(THIS_MODULE, "plat_drv_class");
  if (err<0)
  {
    goto err_cleanup_cdev;
  }

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
    my_device = device_create(plat_drv_class, NULL, MKDEV(MAJOR(devno), i), NULL, "gpio%d", gpio_devs[i].no);
    printk("Created /dev/gpio%d with major number: %d and minor number: %d \n", gpio_devs[i].no, MAJOR(devno), i);
    gpio_devs_cnt++;
  }

  //interrupt er forbundet til GPIO

  irq_no = gpio_to_irq(gpio_devs[0].no);
  if (irq_no < 0)
  {
      goto gpioToIrqError;
  }
  //Anmoder om interrupt
  err = request_irq(irq_no, sonarinputDriver_isr, IRQF_TRIGGER_RISING, NULL, NULL);
  if (err != 0)
    {
      goto requestIrqError;
    }
  printk("irq assigned: %d\n", irq_no);

  return 0; //success

  requestIrqError:
		printk("irq request error\n");

	gpioToIrqError:
		printk("irq to GPIO error\n");

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
  int minor = iminor(filep -> f_inode);

  //Tilføjet interrupt rutine
  wait_event_interruptible(waitQueue, flag != 0);
  flag = 0;

  int value = gpio_get_value(gpio_devs[minor].no);
  char buff[32];
  sprintf(buff, "%d", value);
  len = strlen(buff)+1;
  if(len > count){
    len = count;
  }
  err = copy_to_user(buf, buff, len);
  if(err < 0){
     printk("Error in copy to user\n");
  }
  *f_pos += len;
  return len;
}
//write function ===================================================
ssize_t platDriver_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos){
    int minor, err, value;
    char buf[32];
    minor = iminor(filep -> f_inode);
    printk(KERN_ALERT "Writing to plat_drv minor: %i \n", minor);
    err = copy_from_user(buf, ubuf, count);
    if(err < 0){
        printk("Error in copy from user\n");
        return err;
    }
    sscanf(buf, "%d", &value);
    gpio_set_value(gpio_devs[minor].no, value);

    *f_pos += count;
    return count;
}
////remove() function ================================================
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
static void platDriver_exit(void){
  //frigør interrupt
  free_irq(irq_no, NULL);
  cdev_del(&plat_drv_cdev);
  class_destroy(plat_drv_class);
  platform_driver_unregister(&plat_drv_platform_driver);
  unregister_chrdev_region(devno, nbr_devices);
  printk(KERN_ALERT "Module exit\n");
}

 module_init(platDriver_init);
 module_exit(platDriver_exit);
