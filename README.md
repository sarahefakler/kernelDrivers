# kernelDrivers

HelloWorld - The simplest kernel driver. This driver just uses printk() to
             output hello world messages to the user.
             It can be made using:
             make; make load;
             It can be removed using:
             make unload;
             To check that your module is running, cat /proc/modules and look for 'simple_module'
             To view the messages from your module, inspect /var/log/kern.log
