#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()

int tam_arq_texto(char *nome_arquivo)
{
  char c;
  int j = 0;
  int fp;
  fp = open(nome_arquivo, O_RDONLY | O_CREAT, S_IRWXU);//apenas para le, nao vai modificar o arquivo
  if(fp==-1){
    printf("Arquivo impossivel de ser aberto");
    exit(0);
  }

  while(read(fp, &c, 1) != 0)
    j++;

  close(fp);
    return j;
}
void le_arq_texto(char *nome_arquivo, char *conteudo)
{
  int i = 0;
  char c;
  int fp;
  //conteudo = malloc(100*sizeof(char));
  //conteudo = malloc(sizeof(char));
  fp = open(nome_arquivo, O_RDONLY | O_CREAT, S_IRWXU);
  if(fp==-1){
    printf("Arquivo impossivel de ser aberto");
    exit(0);
  }

  while(read(fp, &c, 1) != 0){ //atribui a c o valro dos carac de fp, e vai incrementadndo ate o end of file

    conteudo[i] = c;//muda diretamente o valor da funcao do main
    i++;
    //printf("%c\n", c );

  }
  

  close(fp);
}
