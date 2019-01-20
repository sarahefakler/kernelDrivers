/*
 * Author: Sarah Chastanet
 * Date: January 2019
 * Description: Following a tutorial to make a simple kernel
 * module.
 */

#include "device_file.h"
#include <linux/init.h>
#include <linux/module.h>

// load module
static int __init simple_init(void)
{
	int result = 0;

	// printk is special print for kernel modules
	printk(KERN_ALERT "Hello World! Simple-driver initializing...\n");

	result = register_device();
	return result;
}

// unload module
static void __exit simple_exit(void)
{
	printk(KERN_ALERT"Goodbye! Simple-driver exiting...\n");
	unregister_device();
}

// These macros notify the kernel about driver loading and unloading
// This is the 'glue' that makes the module work
module_init(simple_init);
module_exit(simple_exit);
