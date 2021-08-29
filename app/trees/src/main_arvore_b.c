#include <stdio.h>

#include "./lib/ArvoreB.h"
#include "./lib/generateRandomPermutation.h"

int main(int argc, char const *argv[])
{
  int countConjuntos = 0;

  // FILE *fp;

  // fp = fopen("arvore_b_data_pior_caso.csv", "w+");
  // fprintf(fp, "NumConjunto;NumOperacoes");

  // // // pior caso
  // for (countConjuntos = 1; countConjuntos <= 1000; countConjuntos++)
  // {
  //   ArvoreB *arvore = criaArvore(4);

  //   int countChaves = 1;

  //   printf("Conjunto %d\n", countConjuntos);

  //   fprintf(fp, "\n%d", countConjuntos);

  //   while (countChaves <= countConjuntos)
  //   {
  //     adicionaChave(arvore, countChaves);
  //     countChaves++;
  //   }

  //   int numOperacoes = getNumeroOperacoes();

  //   fprintf(fp, ";%d", numOperacoes);

  //   // printf("Numero de operacoes: %d\n", numOperacoes);
  // }

  // fprintf(fp, "\n");
  // fclose(fp);

  FILE *fp;

  fp = fopen("arvore_b_data_medio_caso.csv", "w+");
  fprintf(fp, "NumTeste;NumConjunto;NumOperacoes");

  // médio

  for (int countTestes = 1; countTestes <= 10; countTestes++)
  {
    srand(time(NULL));

    for (countConjuntos = 1; countConjuntos <= 1000; countConjuntos++)
    {
      ArvoreB *arvore = criaArvore(4);
      int *conjunto = generateRandomPermutation(countConjuntos);

      printf("Conjunto %d\n", countConjuntos);
      fprintf(fp, "\n%d;%d", countTestes, countConjuntos);

      for (int i = 0; i < countConjuntos; i++)
      {
        adicionaChave(arvore, conjunto[i]);
      }

      int numOperacoes = getNumeroOperacoes();

      // printf("Numero de operacoes: %d\n", numOperacoes);
      fprintf(fp, ";%d", numOperacoes);
    }
  }

  fprintf(fp, "\n");
  fclose(fp);

  return 0;
}
