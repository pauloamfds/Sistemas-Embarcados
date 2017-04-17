#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <math.h>

int vector[50000];

struct vector_lim{
  int i;
  int f;
  double media;
  double Var;
};

void *Variancia(void* num);
int main()
{

  int i;
  int sum = 0;
  double med;
  double treadvar;
  int tsum = 0;
  double sig= 0.0;
  double var;

  struct vector_lim vl[4];
  pthread_t t0;
	pthread_t t1;
  pthread_t t2;
	pthread_t t3;
  srand(time(0));
  for (i = 0; i < 50000; i++)
    {
      vector[i] = rand()%11;
      //printf("%d\n", vector[i]);
    }

  for (i = 0; i < 50000; i++)
  {
      sum += vector[i];
  }
  med = sum/50000.0;

  for (i = 0; i< 50000; i++)
  {
    sig += pow((vector[i] - med), 2);   //tem que colocar -lm na hora de compilar
  }

  var = sig/50000.0;

  vl[0].i = 0;
  vl[0].f = 12499;
  vl[0].media = med;
  vl[1].i = 12500;
  vl[1].f = 24999;
  vl[1].media = med;
  vl[2].i = 25000;
  vl[2].f = 37499;
  vl[2].media = med;
  vl[3].i = 37500;
  vl[3].f = 49999;
  vl[3].media = med;

  pthread_create(&t0, NULL,&Variancia,&vl[0]);
  pthread_create(&t1, NULL,&Variancia,&vl[1]);
  pthread_create(&t2, NULL,&Variancia,&vl[2]);
  pthread_create(&t3, NULL,&Variancia,&vl[3]);
  pthread_join (t0, NULL);
  pthread_join (t1, NULL);
  pthread_join (t2, NULL);
  pthread_join (t3, NULL);
  printf("\nVariancia por metodo tradicional: %lf\n", var);

  for (i = 0; i < 4; i++)
      {treadvar += vl[i].Var;
      }




  printf("\nMedia por thread: %lf\n\n",treadvar );
  return 0;
}
void* Variancia(void* num)
{
  struct vector_lim* p = (struct vector_lim*) num;
	int i;
  double s = 0.0;
  double medi;


  for (i = p->i; i <= p->f; i++)
    s += pow((vector[i] - p->media), 2);

  p->Var = s/50000.0;

	return NULL;
}
