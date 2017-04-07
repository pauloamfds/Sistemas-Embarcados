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

  if(pid_filho != 0) //processo pai
  {
    sleep(2);
    if(getpid() == pid_pai)
    {
      pid_pai = fork();

      if (pid_pai == 0)
      {
        
        strcpy(mensagem, "FILHO2: Nao, eh o vento que se move.");
        if(write(fd[1], mensagem, sizeof(mensagem)) < 0)
          printf("Erro na abertura do pipe\n");
        else{
          if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
            printf("Erro na abertura do pipe\n");
          else
            printf("%s\n", mensagem);

            sleep(1);

      }
    }}
    sleep(4);
    strcpy(mensagem, "PAI: Os dois se enganam. Eh a mente dos senhores que se move.");
    if(write(fd[1], mensagem, sizeof(mensagem)) < 0)
      printf("Erro na abertura do pipe\n");
    else{
      if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
        printf("Erro na abertura do pipe\n");
      else
        printf("%s\n", mensagem);

        sleep(1);

  }}
  else
  {
    strcpy(mensagem, "FILHO1: Quando o vento passa, eh a bandeira que se move.");
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
