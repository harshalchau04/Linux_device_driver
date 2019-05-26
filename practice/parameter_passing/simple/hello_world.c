#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int var;
int arr[4];
int i;
char *str;
int hacb=0;

module_param(str,charp,S_IWUSR | S_IRUSR);
module_param(var,int,S_IWUSR|S_IRUSR);
module_param_array(arr, int, NULL,S_IWUSR|S_IRUSR);

int notify_param(const char *val,const struct kernel_param *kp)
{
	int res= param_set_int(val,kp);
	if(res==0)
	{
		printk(KERN_INFO "Call back function called....\n");
		printk(KERN_INFO "Nw value of cb_fucion %d\n",hacb);
		return 0;
	}
	return -1;
}

const struct kernel_param_ops icando=
{
	.set= &notify_param,
	.get= &param_get_int,
};

module_param_cb(hacb,&icando,&hacb,S_IRUGO| S_IWUSR);

static int __init hello_world_init(void)
{
    	printk(KERN_INFO "Valu of Var=%d\n",var);
	for(i=0;i<4;i++)
	{
		printk(KERN_INFO "value of [%d]=%d",i,arr[i]);
	}
	printk(KERN_INFO "Charcter pointer value=%s\n",str);
        printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
    	return 0;
}

void __exit hello_world_exit(void)
{
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("HARSHAL CHAUDHARI");
MODULE_DESCRIPTION("A simple hello world driver");
MODULE_VERSION("1");
