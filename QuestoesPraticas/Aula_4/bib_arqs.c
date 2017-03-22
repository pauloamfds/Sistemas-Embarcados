#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"


int tam_arq_texto(char *nome_arquivo)
{
  char c;
  int j = 0;
  FILE *fp;
  fp = fopen(nome_arquivo,"r");//apenas para le, nao vai modificar o arquivo
  if(!fp){
    printf("Arquivo impossivel de ser aberto");
    exit(0);
  }

  while ((c = getc(fp)) != EOF)
    j++;

  fclose(fp);
    return j;
}
void le_arq_texto(char *nome_arquivo, char *conteudo)
{
  int i = 0;
  char c;
  FILE *fp;
  //conteudo = malloc(100*sizeof(char));
  //conteudo = malloc(sizeof(char));
  fp = fopen(nome_arquivo,"r");
  if(!fp){
    printf("Arquivo impossivel de ser aberto");
    exit(0);
  }

  while((c = getc(fp)) != EOF){ //atribui a c o valro dos carac de fp, e vai incrementadndo ate o end of file

    conteudo[i] = c;//muda diretamente o valor da funcao do main
    i++;

    //printf("%c\n", c );

  }

  fclose(fp);
}
