#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
  pid_t pid_filho;

  int fd[2];
  char nome[40];
  pipe(fd);
  int i;
  pid_filho = fork();

  if(pid_filho == 0)
  {
    printf("Escreva seu nome: ");
    scanf("%s", &nome);

    if(write(fd[1], nome, sizeof(nome)) < 0)//usar sizeof e não strlen
      printf("Erro na escrita do pipe\n");

      printf("Terminada execucao do filho\n");
  }
  else
  { sleep(4);
    if(read(fd[0], nome, sizeof(nome)) < 0)
      printf("Erro na leitura do nome\n");
    else
      printf("Nome: %s\n", nome);
  }


  return 0;
}
