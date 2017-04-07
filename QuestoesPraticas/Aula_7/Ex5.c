#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void tratamento_alarme(int sig)
{
	system("ps -aux");
	// system("date +%s%3N");
	alarm(1);
}
void funcao_para_control_c()
{
	printf("\nQuem mandou voce pressionar CTRL-C?\n");
	printf("Vou ter de fechar o programa!\n");
	exit(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
  signal(SIGINT, funcao_para_control_c);
	while(1);
	return 0;
}
