#include<linux/init.h>
#include<linux/module.h>

int interface_init(void)
{
	printk(KERN_ALERT "Inside the %s function",__FUNCTION__);
	return 0;
}

void interface_exit(void)
{
	printk(KERN_ALERT "Inside the %s function",__FUNCTION__);
}
module_init(interface_init);
module_exit(interface_exit);
