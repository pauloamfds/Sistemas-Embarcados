#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int v_global = 0;

void Incrementa_Variavel_Global(pid_t id_atual)
	{
		v_global++;
		printf("ID do processo que executou esta funcao = %d\n", id_atual);
		printf("v_global = %d\n", v_global);
	}

  int main()
  {
    pid_t id;
    int i = 0;

    while(i < 3)
    {
      id = fork();
    if (id == 0)
        Incrementa_Variavel_Global(id);
    else
        printf("Processo pai\n");
      i++;
    }
  }
