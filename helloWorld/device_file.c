/*
 * Author: Sarah Chastanet
 * Date: January 2019
 * Description: Following a tutorial to make a simple kernel
 * module.
 */

#include "device_file.h"
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/uaccess.h>

static const char g_s_hello_world_string[] = "Hello world from kernel mode!\n\0";
static const ssize_t g_s_hello_world_size = sizeof(g_s_hello_world_string);

static ssize_t device_file_read(struct file *file_ptr,
								char __user *user_buffer,
								size_t count,
								loff_t *position)
{
	printk(KERN_NOTICE "Simple-driver: Device file is read at offset = %i, read bytes count = %u", (int)*position, (unsigned int) count);

	if(*position >= g_s_hello_world_size) {
		return 0;
	}

	if(*position + count > g_s_hello_world_size) {
		count = g_s_hello_world_size - *position;
	}

	if(copy_to_user(user_buffer, g_s_hello_world_string + *position, count) != 0) {
		return -EFAULT;
	}

	*position += count;
	return count;
}

// Register a character  device
int register_chrdev(unsigned int major,
					const char * name,
					const struct fops);
					file_operations *

// Device file operations (read, write, save) are processsed by
// the function pointers stored within the file_operations structure.
// As we are ensuring the operation of only a single type of
// device with our Linux driver, our file_operations structure
// is global and static.
static struct file_operations simple_driver_fops =
{
	.owner = THIS_MODULE,
	.read = device_file_read,
};

static int device_file_major_number = 0;
static const char device_name[] = "Simple-driver";
//*********************************************************************

// register the device
int register_device(void)
{
	int result = 0;
	printk(KERN_NOTICE "Simple-driver: register_device() is called.");

	result = register_chrdev(0, device_name, &simple_driver_fops);
	if(result < 0) {
		printk(KERN_WARNING "Simple-driver: can\'t register character device with errorcode = %i", result);
		return result;
	}

	device_file_major_number = result;
	printk(KERN_NOTICE "Simple-driver: registered character device with major number = %i and minor numbers 0...255", device_file_major_number);

	return 0;
}
//**********************************************************************

// unregister device
void unregister_device(void)
{
	printk(KERN_NOTICE "Simple-driver: unregister_device() is called");
	if(device_file_major_number != 0) {
		unregister_chrdev(device_file_major_number, device_name);
	}
}
//***********************************************************************
