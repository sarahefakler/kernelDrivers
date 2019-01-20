TARGET_MODULE:=simple-module

# if we are running using the kernel build system
ifneq($(KERNELRELEASE),)
	$(TARGET_MODULE)-objs := hello_world.o device_file.o
	obj-m := $(TARGET_MODULE).o

# if we are running without kernel build system
else
	BUILDSYSTEM_DIR?=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)

all :
# run kernel build system to make module
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) modules

clean:
# run kernel build system to clean up current directory
	$(MAEK) -C $(BUILDSYSTEM_DIR) M=$(PWD) clean

load:
	insmod ./$(TARGET_MODULE).ko

unload:
	rmod ./$(TARGET_MODULE).ko

endif
