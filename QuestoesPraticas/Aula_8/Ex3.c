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
  int Sum;
  double media;
};

void *Media(void* num);
int main()
{

  int i;
  int sum = 0;
  double med;
  double treadmed;
  int tsum = 0;

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
  vl[0].i = 0;
  vl[0].f = 12499;
  vl[0].Sum = 0;
  vl[1].i = 12500;
  vl[1].f = 24999;
  vl[1].Sum = 0;
  vl[2].i = 25000;
  vl[2].f = 37499;
  vl[2].Sum = 0;
  vl[3].i = 37500;
  vl[3].f = 49999;
  vl[3].Sum = 0;

  pthread_create(&t0, NULL,&Media,&vl[0]);
  pthread_create(&t1, NULL,&Media,&vl[1]);
  pthread_create(&t2, NULL,&Media,&vl[2]);
  pthread_create(&t3, NULL,&Media,&vl[3]);
  pthread_join (t0, NULL);
  pthread_join (t1, NULL);
  pthread_join (t2, NULL);
  pthread_join (t3, NULL);
  printf("\nMedia por metodo tradicional: %lf\n", med);

  for (i = 0; i < 4; i++)
      {treadmed += vl[i].media;
      }




  printf("\nMedia por thread: %lf\n\n",treadmed );
  return 0;
}
void* Media(void* num)
{
  struct vector_lim* p = (struct vector_lim*) num;
	int i;
  int s = 0;

	for (i = p->i; i <= p->f; i++)
      s += vector[i];
  p->Sum = s;
  p->media = s/50000.0;
	return NULL;
}
