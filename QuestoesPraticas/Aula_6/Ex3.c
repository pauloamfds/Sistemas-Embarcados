#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  pid_t pid_filho;
  int i;
  for (i = 1; i < argc; i++)
  {
    pid_filho = fork();
    if(pid_filho == 0){
      execvp(argv[i], argv);}
    else
      printf("Esse eh o processo pai\n");
  }

  return 0;
}
