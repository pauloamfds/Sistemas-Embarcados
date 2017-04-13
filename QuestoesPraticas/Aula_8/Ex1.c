#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

void *thread_function(void *arg)
{
	int i;
	printf("*****************************\n");
	printf("* Função thread executando. *\n");
	printf("*****************************\n");
	for (i = 1; i <= 10; i++)
	{
		printf("%2d \n", i);
		sleep(1);
	}
	pthread_exit(0);
}

int main()
{
  pthread_t a_thread;

  pthread_create(&a_thread, NULL, thread_function, NULL);
	sleep(11);
  puts("Final da execucao");
  return 0;
}
