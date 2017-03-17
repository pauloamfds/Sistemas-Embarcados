#include <stdio.h>
#include "num_caracs.h"

int main()
{
  char nome[50];

  printf("Digite um nome: ");
  gets(nome);

  printf("Numero de caracteres: %d\n", Num_Caracs(nome));


  return 0;
}
