 // Access from ARM Running Linux
#include "gpio_dev_mem.h"

//Compile junto com o arquivo gpio_dev_mem.c
int main(int argc, char **argv)
{
	// Set up gpi pointer for direct register access
	setup_io();
	INP_GPIO(22);
	OUT_GPIO(17);
	OUT_GPIO(4);
	GPIO_SET = 0<<22;
	GPIO_SET = 1<<4;
	usleep(500000);
	GPIO_CLR = 1<<4;
	return 0;
} // main
