#include<linux/init.h>
#include<linux/module.h>
MODULE_LICENCE("GPL");

__init int example_simple_module_01(void)
{
	printk(KERN_ALERT "Inside the %s function",__FUNCTION__);
	return 0;
}

void example_simple_module_01(void)
{
	printk(KERN_ALERT "Inside the %s function",__FUNCTION__);
}
module_init(example_simple_module_01);
module_exit(example_simple_module_01);
