#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
	int fp;
	int fp1;

	fp = open("test.wav", O_RDWR | O_CREAT, S_IRWXU);
	fp1 = open("audio.wav", O_RDWR | O_CREAT, S_IRWXU);
	if(fp==-1)
{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
	printf("\n");
	printf("Arquivo 'test.wav' criado. Detalhes: \n");
	system("ls -la test.wav");

	char audio[10], media = 0;
	float c;
	int i = 0;
	while(read(fp, &c, 1) !=0){
		write (fp1, &c, 1);
		
	 }
	printf("\n");
	close(fp);
	close(fp1);
	return 0;
} 
