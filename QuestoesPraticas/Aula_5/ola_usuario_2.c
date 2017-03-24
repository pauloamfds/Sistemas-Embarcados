#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()

int main(int argc, char **argv)
{

  char nomearq[100];//para fazer o nome do arquivo
  char string[100];
  int i;
  strcpy(nomearq, argv[1]);//copia arg1 para nomearq

  int fp;

  strcat(nomearq, ".txt");

  fp = open(nomearq, O_RDWR | O_CREAT, S_IRWXU);//se arquivo inexistente cria, se existe apenas apre e sobreescreve
    if(fp==-1)
    {
        /* Arquivo ASCII, para escrita */
        printf( "Erro na abertura do arquivo");
        exit(-1);
    }

    strcpy(string, "Nome: ");
    strcat(string, argv[1]);

    for(i = 0; string[i]; i++)
      write(fp, &string[i], 1);

      write(fp, "\n", 1);

    strcpy(string, "Idade: ");
    strcat(string, argv[2]);

    for(i = 0; string[i]; i++)
      write(fp, &string[i], 1);

      write(fp, "\n", 1);

    close(fp);

    return 0;
}
