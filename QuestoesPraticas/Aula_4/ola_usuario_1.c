#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
  FILE *fp;
  char string1[100];
  char string2[100] = "Nome: ";
  char nomearq[20];
  int id;

  printf("Entre com o seu nome:");
  gets(string1);
  printf("Entre com a sua idade: ");
  scanf("%d", &id);
  /*for(i=0; string[i]; i++)
    putc(string[i], fp); /* Grava a string, caractere a
                                          caractere */
    strcpy(nomearq, string1);
    strcat(nomearq, ".txt");
          fp = fopen(nomearq,"w");
            if(!fp)
            {
                /* Arquivo ASCII, para escrita */
                printf( "Erro na abertura do arquivo");
                exit(0);
            }

  strcat(string2, string1);
  fputs(string2,fp);
  putc('\n', fp);
  //fputs("Idade: ", fp);
  fprintf(fp, "Idade: %d anos",id);
  //fwrite(id, 4, 1, fp);
  //putc(id, fp);
  putc('\n', fp);
  fclose(fp);
  return 0;
}
