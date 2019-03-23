#include<linux/module.h>
#include<linux/init.h>

static int __init
raspi_gpio_init(void)
{
	printk(KERN_ALERT "INSIDE %s YES I CAN WRITE DRIVER",__FUNCTION__);
	return 0;
}

static void __exit
raspi_gpio_exit(void)
{
	 printk(KERN_ALERT "INSIDE %s YES I DONE IT!!!!!!",__FUNCTION__);
	 return 0;
}

module_init(raspi_gpio_init);
module_exit(raspi_gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("HARSHAL CHAUDHARI <harshalchau04@gmail.com>");
MODULE_DESCRIPTION("GPIO device driver for Raspberry Pi 3");
