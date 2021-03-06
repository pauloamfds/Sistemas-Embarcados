#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int vector[50000];

struct vector_lim{
  int i;
  int f;
  int Max;
};

void *MaxValue(void* num);
int main()
{

  int i;
  int max = 0;
  int treadMax = 0;
  struct vector_lim vl[4];
  pthread_t t0;
	pthread_t t1;
  pthread_t t2;
	pthread_t t3;
  srand(time(0));
  for (i = 0; i < 50000; i++)
    {
      vector[i] = rand();
      //printf("%d\n", vector[i]);
    }

  for (i = 0; i < 50000; i++)
  {
    if (vector[i] > max)
      max = vector[i];
  }
  vl[0].i = 0;
  vl[0].f = 12499;
  vl[0].Max = 0;
  vl[1].i = 12500;
  vl[1].f = 24999;
  vl[1].Max = 0;
  vl[2].i = 25000;
  vl[2].f = 37499;
  vl[2].Max = 0;
  vl[3].i = 37500;
  vl[3].f = 49999;
  vl[3].Max = 0;

  pthread_create(&t0, NULL,&MaxValue,&vl[0]);
  pthread_create(&t1, NULL,&MaxValue,&vl[1]);
  pthread_create(&t2, NULL,&MaxValue,&vl[2]);
  pthread_create(&t3, NULL,&MaxValue,&vl[3]);
  pthread_join (t0, NULL);
  pthread_join (t1, NULL);
  pthread_join (t2, NULL);
  pthread_join (t3, NULL);
  printf("\nMaximo por metodo tradicional: %d\n", max);
  for (i = 0; i < 4; i++)
    if(treadMax < vl[i].Max)
      treadMax = vl[i].Max;

  printf("\nMaximo por thread: %d\n\n",treadMax );
  return 0;
}
void* MaxValue(void* num)
{
  struct vector_lim* p = (struct vector_lim*) num;
	int i;
  p->Max = 0;
	for (i = p->i; i <= p->f; ++i)
    if(p->Max < vector[i])
      p->Max = vector[i];


	return NULL;
}
