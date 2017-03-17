#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char  **argv)
{
  int sum = 0;
  for (int i = 0; i < argc; i++)
    sum = sum + Num_Caracs(argv[i]);

  printf("Total de caracteres de entrada: %d\n\n", sum);

  return 0;
}
