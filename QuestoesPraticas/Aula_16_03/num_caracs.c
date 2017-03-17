#include <stdio.h>

#include "num_caracs.h"

int Num_Caracs(char *string)
{
  int i;
  int sum = 0;
  //faz a contagem do numero de caracteres, termina quando fof \0
  for (i = 0; string[i] != '\0'; i++)
    sum++;

  return sum;
}
