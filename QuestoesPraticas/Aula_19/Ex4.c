 // Access from ARM Running Linux
#include "gpio_dev_mem.h"
#include <signal.h>

void ctrl_c(){
	printf("\nFechando o programa\n");

	GPIO_CLR = 1<<4;
		GPIO_CLR = 1<<22;
		GPIO_CLR = 1<<17;
	exit(1);
}
//Compile junto com o arquivo gpio_dev_mem.c
int main(int argc, char **argv)
{
	// Set up gpi pointer for direct register access
	setup_io();
	signal(SIGINT, ctrl_c);
	int pin1, pin2, pin3, i;
	while(1)
	{
		for (i = 0; i < 6; i++){
			if (i ==0)
				{	usleep(500000);
					pin1 = 4; pin2 = 17; pin3 = 22;}
			if (i ==1)
				{
					pin1 = 17; pin2 = 4; pin3 = 22;
					}
			if (i ==2)
				{	usleep(500000);
					pin1 = 17; pin2 = 22; pin3 = 4;
					}
			if (i ==3)
				{
					pin1 = 22; pin2 = 17; pin3 = 4;
					}
			if (i ==4)
				{	usleep(500000);
					pin1 = 22; pin2 = 4; pin3 = 17;}
			if (i ==5)
				{
					pin1 = 4; pin2 = 22; pin3 = 17;
					}
		INP_GPIO(pin3);
		OUT_GPIO(pin2);
		OUT_GPIO(pin1);
		GPIO_SET = 1<<pin1;
		usleep(5000);
		GPIO_CLR = 1<<pin1;
		GPIO_CLR = 1<<pin2;
		GPIO_CLR = 1<<pin3;
	}
	}
	return 0;
} // main
