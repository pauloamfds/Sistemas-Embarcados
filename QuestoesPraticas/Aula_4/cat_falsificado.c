#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(int argc, char **argv)
{
  char conteudo[100];

  le_arq_texto(argv[1], conteudo); //armazenado o nome do arquivo em argv1
  printf("%s", conteudo);

  return 0;
}
