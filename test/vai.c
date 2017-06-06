#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE *fp;
	FILE *fp1;
	char c ;
	int i = 0;
	float media = 0.0;
	fp = fopen("Corvette_pass.wav", "r");
	fp1 = fopen("out.wav", "w");
	
	if (!fp){ printf("deu ruim"); exit(0);}
	if(!fp1){printf("deu ruim"); exit(0);}
	while((c = fgetc(fp)) != EOF)
		
		putc(c, fp1);
		
		

	fclose(fp);
	fclose(fp1);

	return 0;

}
