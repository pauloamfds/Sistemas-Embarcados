#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

  char nomearq[100];//para fazer o nome do arquivo


  strcpy(nomearq, argv[1]);//copia arg1 para nomearq

  FILE *fp;

  strcat(nomearq, ".txt");

  fp = fopen(nomearq,"w");//se arquivo inexistente cria, se existe apenas apre e sobreescreve
    if(!fp)
    {
        /* Arquivo ASCII, para escrita */
        printf( "Erro na abertura do arquivo");
        exit(0);
    }

    fprintf(fp, "Nome: %s", argv[1]);//funciona como printf normal, mesmo jeito de usar
    putc('\n',fp);//apenas para dar uma quebra de linha
    fprintf(fp, "Idade: %s anos", argv[2]);//argv e string, entao pra imprimir como string, poderia fazer int id = atoi(arg[2])
                                           //com que se transformasse num inteiro e imprimir como inteiro tambem
    putc('\n', fp);

    fclose(fp);

    return 0;
}
