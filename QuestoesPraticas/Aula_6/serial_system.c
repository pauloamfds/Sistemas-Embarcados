#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int a;
  int i;
  for (i = 1; i < argc; i ++)
  a = system(argv[i]);

  return 0;
}
