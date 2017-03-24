#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main()
{

  char conteudo_arquivo[100];//tem que ser definido aqui o tamanho da string

  printf("Tamanho do arquivo em bytes: %d\n", tam_arq_texto("Paulo.txt"));

  le_arq_texto("augusto.txt", conteudo_arquivo);

  printf("Conteudo do arquivo lido: \n%s\n", conteudo_arquivo );

  return 0;
}
