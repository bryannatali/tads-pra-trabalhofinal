#include <stdio.h>

#include "./lib/generateRandomPermutation.h"
#include "./lib/ArvoreAVL.h"

void visitar(int valor)
{
  printf("%d ", valor);
}

int main(int argc, char const *argv[])
{
  // int *conjunto = generateRandomPermutation(20);

  // for (int i = 0; i < 20; i++)
  // {
  //   printf("%d, ", conjunto[i]);
  // }
  // printf("\n");

  // free(conjunto);
  // return 0;

  int countConjuntos = 0;

  // FILE *fp;

  // fp = fopen("arvore_avl_data_pior_caso.csv", "w+");
  // fprintf(fp, "NumConjunto;NumOperacoes");

  // pior caso
  // for (countConjuntos = 1; countConjuntos <= 1000; countConjuntos++)
  // {
  //   Arvore *a = criar();

  //   int countChaves = 1;

  //   printf("Conjunto %d\n", countConjuntos);

  //   fprintf(fp, "\n%d", countConjuntos);

  //   while (countChaves <= countConjuntos)
  //   {
  //     adicionar(a, countChaves);
  //     countChaves++;
  //   }

  //   int numOperacoes = getNumeroOperacoes();

  //   fprintf(fp, ";%d", numOperacoes);

  //   // printf("Numero de operacoes: %d\n", numOperacoes);

  //   // freeArvore(a);
  //   // free(a);
  // }

  // fprintf(fp, "\n");
  // fclose(fp);

  FILE *fp;

  fp = fopen("arvore_avl_data_medio_caso.csv", "w+");
  fprintf(fp, "NumTeste;NumConjunto;NumOperacoes");

  // médio caso
  // for (int countTestes = 1; countTestes <= 10; countTestes++)
  // {
  for (countConjuntos = 1; countConjuntos <= 1000; countConjuntos++)
  {
    Arvore *a = criar();

    int *conjunto = generateRandomPermutation(countConjuntos);

    printf("Conjunto %d\n", countConjuntos);
    fprintf(fp, "\n%d;%d", 1, countConjuntos);

    for (int i = 0; i < countConjuntos; i++)
    {
      adicionar(a, conjunto[i]);
      // printf("%d, ", conjunto[i]);
    }

    int numOperacoes = getNumeroOperacoes();

    // printf("Numero de operacoes: %d\n", numOperacoes);
    fprintf(fp, ";%d", numOperacoes);

    // printf("\n");
    // free(conjunto);

    // freeArvore(a);
  }
  // }

  fprintf(fp, "\n");
  fclose(fp);

  // testing

  // Arvore *a = criar();

  // countConjuntos = 1000;

  // printf("Conjunto %d\n", countConjuntos);

  // srand(time(NULL));

  // for (int countChaves = 1; countChaves <= countConjuntos; countChaves++)
  // {
  //   int chave = rand() % 1000;
  //   // printf("Chave %d\n", chave);
  //   adicionar(a, chave);
  // }

  // long int numOperacoes = getNumeroOperacoes();

  // printf("Numero de operacoes: %ld\n", numOperacoes);

  return 0;
}
