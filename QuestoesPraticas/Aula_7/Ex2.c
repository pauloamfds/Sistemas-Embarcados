#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int fd[2];
  pid_t pid_filho, pid_pai = getpid();
  char mensagem[100];
  pipe(fd);

  pid_filho = fork();

  if(getpid() == pid_pai) //processo pai
  {
    sleep(2);
    strcpy(mensagem, "PAI: Naofaçais nada violento, praticai somente aquilo que eh justo e equilibrado.");
    if(write(fd[1], mensagem, sizeof(mensagem)) < 0)
      printf("Erro na abertura do pipe\n");
    else{
      if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
        printf("Erro na abertura do pipe\n");
      else
        printf("%s\n", mensagem);

        sleep(1);
    }
    sleep(4);
    strcpy(mensagem, "PAI: Sim, mas eh uma coisa dificil de ser praticada ate mesmo por um velho como eu...");
    if(write(fd[1], mensagem, sizeof(mensagem)) < 0)
      printf("Erro na abertura do pipe\n");
    else{
      if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
        printf("Erro na abertura do pipe\n");
      else
        printf("%s\n", mensagem);

        sleep(1);
    }
  }

  else // processo filho
  {
    strcpy(mensagem, "FILHO: Pai, qual eh a verdadeira essencia da sabedoria?");
    if(write(fd[1], mensagem, sizeof(mensagem)) < 0)
      printf("Erro na abertura do pipe\n");
    else{
      if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
        printf("Erro na abertura do pipe\n");
      else
        printf("%s\n", mensagem);

        sleep(1);
    }
    sleep(3);
    strcpy(mensagem, "FILHO: Mas ate uma criança de tres anos sabe disso!");
    if(write(fd[1], mensagem, sizeof(mensagem)) < 0)
      printf("Erro na abertura do pipe\n");
    else{
      if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
        printf("Erro na abertura do pipe\n");
      else
        printf("%s\n", mensagem);

        sleep(1);
    }
  }

  return 0;
}
