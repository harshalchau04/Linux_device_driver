#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");

__init int example_simple_module_02_init(void)
{
	printk(KERN_ALERT "Inside the %s function",__FUNCTION__);
	return 0;
}

void example_simple_module_02_exit(void)
{
	printk(KERN_ALERT "Inside the %s function",__FUNCTION__);
}
module_init(example_simple_module_02_init);
module_exit(example_simple_module_02_exit);
