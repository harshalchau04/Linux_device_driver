#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("Dual BSD/GPL");

int var=10;

static int my_notify(const char *val, const struct kernel_param *kp)
{
	int res=param_set_int(val,kp);
	if(res==0)
	{
		printk(KERN_ALERT "callback function called");
		printk(KERN_ALERT "NEW VALUE =%s",val);
	}
	return 0;
}

static int my_param_val(char *buffer, const struct kernel_param *kp)
{
	int ge=param_get_int(buffer,kp);
	printk(KERN_ALERT "BUFFER=%d\n",ge);
	return 0;
}

const struct kernel_param_ops my_param_ops=
{
	.set = &my_notify, //used to set the value
	.get = &my_param_val //stander getter function provided by kernel
};

module_param_cb(var,&my_param_ops,&var,S_IWUSR | S_IRUSR);


static int callback_init(void)
{
	printk(KERN_ALERT "callback value=%d\n",var);
	return 0;
}

void callback_exit(void)
{
	printk(KERN_ALERT "callback exit");
}

module_init(callback_init);
module_exit(callback_exit);





