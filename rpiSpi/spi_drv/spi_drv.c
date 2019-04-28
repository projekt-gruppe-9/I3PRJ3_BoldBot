#include <linux/cdev.h>   // cdev_add, cdev_init
#include <linux/uaccess.h>  // copy_to_user
#include <linux/module.h> // module_init, GPL
#include <linux/spi/spi.h> // spi_sync,
//License===================================================
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hallal");
MODULE_DESCRIPTION("Spi driver");
// Variables==================================================
#define MAXLEN 32
#define MODULE_DEBUG 1 // Enable/disable debug messages
//Char Driver globals
static struct class *spi_drv_class;
static dev_t devno;
static struct cdev spi_drv_cdev;
//Definition of SPI devices
struct Myspi {
  struct spi_device *spi; // Pointer to SPI device
  int channel;            // channel, ex. adc ch 0
};
/* Array of SPI devices */
/* Minor used to index array */
struct Myspi spi_devs[4];
const int spi_devs_len = 4;  // Max nbr of devices
static int spi_devs_cnt = 0; // Nbr devices present
//Prototypes============================================
static int spiDriver_init(void);
static void spiDriver_exit(void);
ssize_t spiDriver_read(struct file *filep, char __user *ubuf, size_t count, loff_t *f_pos);
ssize_t spiDriver_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos);
static int spiDriver_probe (struct spi_device *sdev);
static int spiDriver_remove(struct spi_device *sdev);
//Spi driver structs
static const struct of_device_id of_spi_drv_spi_device_match [] ={
  { .compatible = "ase, spi_drv",}, {},
};
static struct spi_driver spi_drv_spi_driver ={
  .probe = spiDriver_probe,
  .remove = spiDriver_remove,
  .driver = {
  .name = "spi_drv",
  .bus = &spi_bus_type,
  .of_match_table = of_spi_drv_spi_device_match,
  .owner = THIS_MODULE,
  },
};
struct file_operations spi_drv_fops = {
    .owner = THIS_MODULE,
    .read = spiDriver_read,
    .write = spiDriver_write,
};
/* Macro to handle Errors */
#define ERRGOTO(label, ...)                     \
  {                                             \
    printk (__VA_ARGS__);                       \
    goto label;                                 \
  } while(0)
//Implementering=======================================
//Init function ========================================
static int spiDriver_init(void){
  int err=0;

  printk("spi_drv driver initializing\n");

  /* Allocate major number and register fops*/
  err = alloc_chrdev_region(&devno, 0, 255, "spi_drv driver");
  if(MAJOR(devno) <= 0)
    ERRGOTO(err_no_cleanup, "Failed to register chardev\n");
  printk(KERN_ALERT "Assigned major no: %i\n", MAJOR(devno));

  cdev_init(&spi_drv_cdev, &spi_drv_fops);
  err = cdev_add(&spi_drv_cdev, devno, 255);
  if (err)
    ERRGOTO(err_cleanup_chrdev, "Failed to create class");

  /* Polulate sysfs entries */
  spi_drv_class = class_create(THIS_MODULE, "spi_drv_class");
  if (IS_ERR(spi_drv_class))
    ERRGOTO(err_cleanup_cdev, "Failed to create class");

  /* Register SPI Driver */
  /* THIS WILL INVOKE PROBE, IF DEVICE IS PRESENT!!! */
  err = spi_register_driver(&spi_drv_spi_driver);
  if(err)
    ERRGOTO(err_cleanup_class, "Failed SPI Registration\n");

  /* Success */
  return 0;

  /* Errors during Initialization */
 err_cleanup_class:
  class_destroy(spi_drv_class);

 err_cleanup_cdev:
  cdev_del(&spi_drv_cdev);

 err_cleanup_chrdev:
  unregister_chrdev_region(devno, 255);

 err_no_cleanup:
  return err;
}
//Exit function ===================================================
static void spiDriver_exit(void){
  spi_unregister_driver(&spi_drv_spi_driver);
  class_destroy(spi_drv_class);
  cdev_del(&spi_drv_cdev);
  unregister_chrdev_region(devno, 255);
  printk(KERN_ALERT "Module exit\n");
}
//Read function ==================================================
ssize_t spiDriver_read(struct file *filep, char __user *ubuf, size_t count, loff_t *f_pos){
  int minor, len;
  char resultBuf[MAXLEN];
  u8 result;
  minor = iminor(filep->f_inode);

  //Provide a result to write to user space
  struct spi_transfer t[1];
  struct spi_message m;

  memset(t,0,sizeof(t));
  spi_message_init(&m);
  m.spi = spi_devs[0].spi;

  //Configure tx/rx buffers
  t[0].tx_buf = NULL;
  t[0].rx_buf = &result;
  t[0].len = 1;
  t[0].delay_usecs = 60;
  spi_message_add_tail(&t[0], &m);

  /*t[0].tx_buf = NULL;
  //result = *((int *)t[0].rx_buf);
  t[0].rx_buf = result;
  t[0].len = 1;
  spi_message_add_tail(&t[0], &m);*/

  int err = spi_sync(m.spi,&m);
  if(err < 0){
    printk("SPI sync error");
  }

  if(MODULE_DEBUG)
    printk(KERN_ALERT "%s-%i read: %i\n",
           spi_devs[minor].spi->modalias, spi_devs[minor].channel, result);

  /* Convert integer to string limited to "count" size. Returns
   * length excluding NULL termination */
  len = snprintf(resultBuf, count, "%d\n", result);

  /* Append Length of NULL termination */
  len++;

  /* Copy data to user space */
  if(copy_to_user(ubuf, resultBuf, len))
    return -EFAULT;

  /* Move fileptr */
  *f_pos += len;

  return len;
}
//write function ===================================================
ssize_t spiDriver_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos){
  int minor, len;
  char kbuf[MAXLEN];
  int value;

  minor = iminor(filep->f_inode);

  printk(KERN_ALERT "Writing to spi_drv [Minor] %i \n", minor);

  /* Limit copy length to MAXLEN allocated andCopy from user */
  len = count < MAXLEN ? count : MAXLEN;
  if(copy_from_user(kbuf, ubuf, len))
    return -EFAULT;

  /* Pad null termination to string */
  kbuf[len] = '\0';

  if(MODULE_DEBUG)
    printk("string from user: %s\n", kbuf);

  /* Convert sting to int */
  sscanf(kbuf,"%i", &value);
  if(MODULE_DEBUG)
    printk("value %i\n", value);

  struct spi_transfer t[2];
  struct spi_message m;

  memset(t,0,sizeof(t));
  spi_message_init(&m);
  m.spi = spi_devs[0].spi;

  t[0].tx_buf = &value;
  t[0].rx_buf = NULL;
  t[0].len = 1;
  spi_message_add_tail(&t[0], &m);

  int err = spi_sync(m.spi,&m);
  if(err < 0){
  printk("SPI sync error");
}

  /* Legacy file ptr f_pos. Used to support
 * random access but in char drv we dont!
 * Move it the length actually  written
 * for compability */
 *f_pos += len;

 /* return length actually written */
  return len;
}
//probe() funktion ===================================================
static int spiDriver_probe (struct spi_device *sdev){
  int err = 0;
  struct device *spi_drv_device;

  printk(KERN_DEBUG "New SPI device: %s using chip select: %i\n", sdev->modalias, sdev->chip_select);

  /* Check we are not creating more
   devices than we have space for */
  if (spi_devs_cnt > spi_devs_len) {
    printk(KERN_ERR "Too many SPI devices for driver\n");
    return -ENODEV;
  }

  /* Configure bits_per_word, always 8-bit for RPI!!! */
  sdev->bits_per_word = 8;
  spi_setup(sdev);

  //Added
  //spi = sdev;

  /* Create devices, populate sysfs and
   active udev to create devices in /dev */

  /* We map spi_devs index to minor number here */
  spi_drv_device = device_create(spi_drv_class, NULL, MKDEV(MAJOR(devno), spi_devs_cnt), NULL, "spi_drv%d", spi_devs_cnt);

  if (IS_ERR(spi_drv_device)){
    printk(KERN_ALERT "FAILED TO CREATE DEVICE\n");
  }

  else {
  printk(KERN_ALERT "Using spi_devs%i on major:%i, minor:%i\n", spi_devs_cnt, MAJOR(devno), spi_devs_cnt);
}

/* Update local array of SPI devices */
spi_devs[spi_devs_cnt].spi = sdev;
spi_devs[spi_devs_cnt].channel = 0x00; // channel address
++spi_devs_cnt;

return err;
}
////remove() function ================================================
static int spiDriver_remove(struct spi_device *sdev){
  int its_minor = 0;
  /* Destroy devices created in probe() */
  device_destroy(spi_drv_class, MKDEV(MAJOR(devno), its_minor));
  printk(KERN_ALERT"All devices has been removed\n");
  return 0;
}

module_init(spiDriver_init);
module_exit(spiDriver_exit);
