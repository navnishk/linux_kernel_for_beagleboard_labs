// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>

//more include fiels needed
#include <linux/utsname.h>
#include <linux/timekeeping32.h>



/* Add your code here */
//parameter
static char* whom = "world";
module_param(whom, charp, 0);

extern struct uts_namespace init_uts_ns ;

unsigned long start_time = 0;
unsigned long end_time 	 = 0;
unsigned long time_spent = 0;

static int __init hello_init(void)
{
	pr_alert("Good morning %s, you are using linux version %s \n", whom, init_uts_ns.name.release);
	start_time = get_seconds();
	
	return 0;
}

static void __exit hello_exit(void)
{
	end_time = get_seconds();
	time_spent = end_time - start_time;
	pr_alert("start_time %lu, end_time %lu \n",start_time, end_time);
	pr_alert("Good Bye, time spent in this module is %lu \n", time_spent);
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("hello module");
MODULE_AUTHOR("navnish");


