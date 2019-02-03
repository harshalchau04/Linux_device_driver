#include<linux/init.h>
#include<linux/module.h>

void first_interface_exit(void)
{
	printk(KERN_ALERT "Inside the %s function",__FUNCTION__);
}
module_exit(first_interface_exit);
