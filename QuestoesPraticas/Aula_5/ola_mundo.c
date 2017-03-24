#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
int main(int argc, const char * argv[]) {
  int fp;

  fp = open("olamundo.txt", O_RDWR | O_CREAT, S_IRWXU); //sem  o S_IRWXU, da permissao negada
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
  /*for(i=0; string[i]; i++)
    putc(string[i], fp); /* Grava a string, caractere a
                                                caractere */
      write(fp, "Ola mundo", 10); // Grava a string, caractere a caractere
      write(fp, "\n", 1);
  close(fp);
  return 0;
}
