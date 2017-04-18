#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <math.h>

long int A[60][60];
long int B[60][60];

struct vector_lim{
  int i;
  int f;
  long int sumMa[60][60];
};

void* SumaMatriz(void* soma);

int main()
{
  int i,j;
  int s = 0;
  long int sum[60][60];
  long int sum1[60][60];
  struct vector_lim vl[4];
  pthread_t t0;
	pthread_t t1;
  pthread_t t2;
	pthread_t t3;

  srand(time(0));

  for (i = 0; i < 60; i++){
    for(j = 0; j < 60; j++)
      {
        A[i][j] = rand()%1000;
        B[i][j] = rand()%1000;
      //  printf(", %ld, %ld ", A[i][j], B[i][j]);
      s++;
      }
      //printf("\n");
    }
    printf("%d\n",s );
    for (i = 0; i < 60; i++){
      for(j = 0; j < 60; j++){
        sum[i][j] = A[i][j] + B[i][j];
        //printf(", %ld ", sum[i][j]);
      }
      //printf("\n");
    }
    vl[0].i = 0;
    vl[0].f = 14;
    vl[1].i = 15;
    vl[1].f = 29;
    vl[2].i = 30;
    vl[2].f = 44;
    vl[3].i = 45;
    vl[3].f = 59;

  pthread_create(&t0, NULL,&SumaMatriz,&vl[0]);
  pthread_create(&t1, NULL,&SumaMatriz,&vl[1]);
  pthread_create(&t2, NULL,&SumaMatriz,&vl[2]);
  pthread_create(&t3, NULL,&SumaMatriz,&vl[3]);
  pthread_join (t0, NULL);
  pthread_join (t1, NULL);
  pthread_join (t2, NULL);
  pthread_join (t3, NULL);

  for(i = 0; i < 15; i++)
    for(j = 0; j<60; j++)
      sum1[i][j] = vl[0].sumMa[i][j];
  for(i = 15; i < 30; i++)
    for(j = 0; j<60; j++)
      sum1[i][j] = vl[1].sumMa[i][j];
  for(i = 30; i < 45; i++)
    for(j = 0; j<60; j++)
      sum1[i][j] = vl[2].sumMa[i][j];
  for(i = 45; i < 60; i++)
    for(j = 0; j<60; j++)
      sum1[i][j] = vl[3].sumMa[i][j];

    s = 0;
    for(i = 0; i < 60; i++)
      for(j = 0; j < 60; j++)
          if( sum[i][j] == sum1[i][j])//comparação para ver se são iguais
            s++;
  printf("%d\n", s); //se igual, s = 3600; s = 60x60

    return 0;
}

void* SumaMatriz(void* soma)
{
  struct vector_lim* p = (struct vector_lim*) soma;
  int k;
  int n;
  long int sum;
  for(k = p->i; k <= p->f; k++)
    for(n = 0; n < 60; n++){
      //sum = A[k][n] + B[k][n];
      p->sumMa[k][n] = A[k][n] + B[k][n];
    }
  return NULL;
}
