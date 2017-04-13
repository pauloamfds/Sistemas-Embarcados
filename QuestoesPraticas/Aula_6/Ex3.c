#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
  pid_t pid_filho[argc];
  int i = 1;

  while(i <= argc){

    pid_filho[i] = fork();
    if(pid_filho[i] == 0){
      char *lista[] = {NULL, NULL};
      lista[0] = argv[i];
      execvp(argv[i], lista);
    }
    else
      sleep(1);  //faz funcionar na sequencia certa

      i++;
  }



}
