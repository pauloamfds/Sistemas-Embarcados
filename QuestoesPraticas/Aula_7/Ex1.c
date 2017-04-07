#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int fd[2];
  int pid;
  int i;
  int num[11];

  pipe(fd);

  pid = fork();

  if(pid!=0){
      for (i = 0; i < 10; i++)
        num[i] = i + 1;

        if(write(fd[1], num, sizeof(num)) < 0)
          printf("Erro na leitura do pipe\n");
        else
        for(i = 0; i < 10; i ++){
          printf("Escrita no pipe: %d\n", num[i]);
        sleep(1);
      }
      printf("Terminou de escrever no pipe\n");
      sleep(1);
  }
  else{
    sleep(12);
    if(read(fd[0], num, sizeof(num)) < 0)//ja le tudo de uma vez,
      printf("Erro na leitura do pipe\n");
  		else
      for(i = 0; i < 10; i++){ //imprime um de cada vez
  			printf("Pipe lido: %d\n", num[i]);
        sleep(1);
    }

  }

  return 0;
}
