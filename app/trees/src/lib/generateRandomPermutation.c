#include <stdlib.h>
#include <time.h>

#include "./generateRandomPermutation.h"

int *generateRandomPermutation(int n)
{
  int *array = malloc(sizeof(int) * n);

  fillArray(array, n);

  shuffle(array, n);

  return array;
}

void fillArray(int *array, int n)
{
  for (int i = 0; i < n; i++)
  {
    array[i] = i + 1;
  }
}

void shuffle(int *array, int n)
{
  srand(time(NULL));

  for (int i = n - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);

    int aux = array[i];

    array[i] = array[j];
    array[j] = aux;
  }
}