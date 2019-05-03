TARGET_MODULE:=simple-module

$(TARGET_MODULE)-objs := hello_world.o device_file.o
obj-m := $(TARGET_MODULE).o

all :
# run kernel build system to make module
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
# run kernel build system to clean up current directory
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

load:
# call from build directory with 'make load'
	insmod ./$(TARGET_MODULE).ko

unload:
	rmmod ./$(TARGET_MODULE).ko
