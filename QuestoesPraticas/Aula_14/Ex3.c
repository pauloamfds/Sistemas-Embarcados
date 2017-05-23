#include "gpio_sysfs.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
int pin=4;

void ctrl_c(void)
{
	printf("\nFechando o programa\n");
	if(unsetGPIO(pin))
		return 2;
	exit(-1);
}
//Compile junto com o arquivo gpio_sysfs.c
int main()
{
	signal(SIGINT, ctrl_c);
	int freq;

	printf("Digite uma frequencia: ");
	scanf("%d", &freq);

	freq = 500000/freq;

	if(setGPIO_Out(pin))
		return -1;
	while(1){
	if (GPIO_Write(pin,1))
		return 1;
	usleep(freq);
	if (GPIO_Write(pin,0))
		return 3;
	usleep(freq);
	}

	return 0;
}
