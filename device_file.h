/*
 * Author: Sarah Chastanet
 * Date: January 2019
 * Description: Following a tutorial to make a simple kernel
 * module.
 */

#ifndef DEVICE_FILE_H
#define DEVICE_FILE_H
#include <linux/compiler.h>

/*
 * Description: Register a device
 */
__must_check int register_device(void);

/*
 * Description: Unregister a device
 */
void unregister_device(void);

#endif //DEVICE_FILE_H
