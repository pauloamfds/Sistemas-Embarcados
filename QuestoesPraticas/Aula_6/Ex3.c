#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  pid_t pid_filho;
  char lista[argc][100];
  lista[0][100] = "NULL";
  pid_filho = fork();
  int i;
  for (i = 1; i < argc; i++){
    strcpy(lista[i], argv[i]);
    /*printf("%s\n", lista[i]);
    printf("%d", i);*/
  }

if (pid_filho == 0){
  execvp(lista[0], lista);
}
else
  printf("Esse eh o processo pai\n");

  return 0;
}
