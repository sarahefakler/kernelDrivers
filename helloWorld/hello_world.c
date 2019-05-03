/*
 * Author: Sarah Chastanet
 * Date: January 2019
 * Description: Following a tutorial to make a simple kernel
 * module.
 */

#include "device_file.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

/*
 * Provide some basic information about the driver, and
 * define a license so that this module can be loaded
 */
#define DRIVER_AUTHOR "Sarah Chastanet"
#define DRIVER_DESC   "A sample driver"
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_SUPPORTED_DEVICE("testdevice");

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
