#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char **argv)
{
  //vai pegar para cada item de entrada e colocar o numero de caracteres de cada
  for(int i = 0; i < argc; i++)
    printf("Argumento: %s / Numero de Caracteres: %d\n\n", argv[i], Num_Caracs(argv[i]));

  return 0;
}
