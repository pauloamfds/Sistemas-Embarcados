#include <stdio.h>
#include <stdlib.h>

int main(int argc, int **argv)
{
  printf ("Ola %s\n", argv[1]);
  printf("Numero de entrada: %d\n", argc);

  return 0;
}
