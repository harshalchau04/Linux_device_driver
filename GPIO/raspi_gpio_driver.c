#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#define NUM_GPIO_PINS 5
#define DEVICE_NAME "raspi-gpio"

static dev_t first;
static int __init

raspi_gpio_init(void)
{
	//printk(KERN_ALERT "INSIDE %s YES I CAN WRITE DRIVER",__FUNCTION__);

	if (alloc_chrdev_region(&first,0,NUM_GPIO_PINS,DEVICE_NAME) < 0)
	{
		printk(KERN_DEBUG "Cannot register device\n");
		return -1;
	}
	printk(KERN_INFO "<Major, Minor>: <%d, %d>\n", MAJOR(first), MINOR(first));
	return 0;
}


static void __exit
raspi_gpio_exit(void)
{
	// printk(KERN_ALERT "INSIDE %s YES I DONE IT!!!!!!",__FUNCTION__);
	 unregister_chrdev_region(first, NUM_GPIO_PINS);
	 printk(KERN_INFO "By Device unregisterd");
	 return 0;
}

module_init(raspi_gpio_init);
module_exit(raspi_gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("HARSHAL CHAUDHARI <harshalchau04@gmail.com>");
MODULE_DESCRIPTION("GPIO device driver for Raspberry Pi 3");
