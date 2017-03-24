#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()

int main(int argc, const char * argv[]) {
  int fp;
  char string1[100];
  char string2[100] = "Nome: ";
  char nomearq[20];
  char  id[4];
  int i;
  printf("Entre com o seu nome:");
  gets(string1);
  printf("Entre com a sua idade: ");
  gets(id);
  /*for(i=0; string[i]; i++)
    putc(string[i], fp); /* Grava a string, caractere a
                                          caractere */
    strcpy(nomearq, string1);
    strcat(nomearq, ".txt");
          fp = open(nomearq, O_RDWR | O_CREAT, S_IRWXU);
            if(fp == -1)
            {
                /* Arquivo ASCII, para escrita */
                printf( "Erro na abertura do arquivo");
                exit(-1);
            }

  strcat(string2, string1);

  for(i = 0; string2[i]; i++)
    write(fp, &(string2[i]), 1);

  write(fp, "\n", 1);

  strcpy(string1, "Idade: ");
  strcat(string1, id);

  for(i=0; string1[i]; i++)
    write(fp, &(string1[i]), 1);

    write(fp, "\n", 1);


  close(fp);
  return 0;
}
