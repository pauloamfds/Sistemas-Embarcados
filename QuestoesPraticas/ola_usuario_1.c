#include <stdio.h>

int main()
{
  char nome[100];

  printf("Digite seu nome: ");
  scanf("%s", &nome);

  printf("Ola %s\n",nome );

  return 0;
}
