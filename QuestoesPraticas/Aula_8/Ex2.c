#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>




int main()
{
  int vector[50000];
  int i;
  srand(time(0));
  for (i = 0; i < 50000; i++)
    {
      vector[i] = rand() % 5;
      printf("%d\n", vector[i]);
    }

  return 0;
}
