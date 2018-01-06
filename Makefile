ifneq ($(KERNELRELEASE),)
	obj-m := async_demo.o
	obj-m += async_demo_i2c.o
else
	PWD := $(shell pwd)
	KERNELDIR ?= $(PWD)/../../linux-4.10.17
default:
	$(MAKE) -C $(KERNELDIR) ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- M=$(PWD) modules
	cp *.ko /nfsroot

clean:
	@rm -rf *.o *.mod.c *.mod.o *.ko *.order *.symvers .*.cmd .tmp_versions
endif
