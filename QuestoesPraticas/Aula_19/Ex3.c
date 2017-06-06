#include "gpio_sysfs.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
int pin3=4;
int pin1=17;
int pin2=22;

void ctrl_c(void)
{
        printf("\nFechando o programa\n");
        if(unsetGPIO(pin1))
                return 2;
	if(unsetGPIO(pin2))
                return 2;
	if(unsetGPIO(pin3))
                return 2;
        exit(-1);
}

//Compile junto com o arquivo gpio_sysfs.c
int main()
{
        signal(SIGINT, ctrl_c);
        int freq = 1;

        //printf("Digite uma frequencia: ");
        //scanf("%d", &freq);

        freq = 500000/freq;




        while(1){
	if(setGPIO_Out(pin1))
                return -1;
	if(setGPIO_Out(pin2))
                return -1;
	if(setGPIO_IN(pin3))
	if (GPIO_Write(pin2,0))
        if (GPIO_Write(pin1,1))
                return 1;
	usleep(freq);
        if (GPIO_Write(pin1,0))
                return 3;
        usleep(freq);

        }

        return 0;
}
