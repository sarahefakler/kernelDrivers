===========================================================
Kernel Drivers
--------------------------
    Author: Sarah Chastanet, sarahfchastanet@gmail.com
===========================================================

Description
------------
 - This is intended to be a sandbox repository of any/all kernel drivers I
   decide to write. Most, if not all, of these drivers exist just for my
   enjoyment and learning. None of these are intended to have any real
   application.

Existing Drivers
----------
 HelloWorld - The simplest kernel driver, it uses printk() to output hello world messages to the user

How to build
-------------
To build, execute the following command from the console in the project root directory:

    make; make load

To remove, execute the following command from the console in the project root directory:

    make unload

To check that your module is running, run this command after loading:

    cat /proc/modules; # look for your driver name

To check that your module is registered, run this command:

    cat /proc/devices; # look for your driver name

To view the any printk() messages from your module, inspect this file:

    /var/log/kern.log
