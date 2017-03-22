#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int main(int argc, char **argv)
{
  char conteudo[100];
  char tmp[20];
  char pala[20];
  int count = 0;
  int j, k;
  le_arq_texto(argv[2], conteudo); //armazenado o nome do arquivo em argv1
  strcpy(pala,argv[1]);
  for(int k = 0; pala[k]; k++)
  //  printf("%c\n",pala[k] );
    strcpy(tmp, pala);
  for(int i = 0; conteudo[i]; i++){
      for(j=i, k=0;tmp[k]!='\0' && conteudo[j]==tmp[k];j++,k++){//sai do for quando uma das duas confiçoes deixam de ser verdade
      tmp[k] = conteudo[j];
      //printf("%c", tmp[k]);


    }
    if(tmp[k]== '\0' && strcmp(tmp,pala) == 0){
      count++;
      }
  }

  printf("'%s' ocorre %d vezes no arquivo '%s'\n", pala, count, argv[2]);

  return 0;
}
