#include <stdio.h>

#include "./lib/ArvoreRubroNegra.h"
#include "./lib/generateRandomPermutation.h"

void visitar(int valor)
{
  printf("%d ", valor);
}

int main(int argc, char const *argv[])
{
  int countConjuntos = 0;

  // FILE *fp;

  // fp = fopen("arvore_rubro_negra_data_pior_caso.csv", "w+");
  // fprintf(fp, "NumConjunto;NumOperacoes");

  // // // pior caso
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
  // }

  // fprintf(fp, "\n");
  // fclose(fp);

  FILE *fp;

  fp = fopen("arvore_rubro_negra_data_medio_caso.csv", "w+");
  fprintf(fp, "NumTeste;NumConjunto;NumOperacoes");

  // médio caso

  for (int countTeste = 1; countTeste <= 10; countTeste++)
  {
    for (countConjuntos = 1; countConjuntos <= 1000; countConjuntos++)
    {
      Arvore *a = criar();
      int *conjunto = generateRandomPermutation(countConjuntos);

      printf("Conjunto %d\n", countConjuntos);

      fprintf(fp, "\n%d;%d", countTeste, countConjuntos);

      for (int i = 0; i < countConjuntos; i++)
      {
        adicionar(a, conjunto[i]);
      }

      int numOperacoes = getNumeroOperacoes();

      fprintf(fp, ";%d", numOperacoes);

      // printf("Numero de operacoes: %d\n", numOperacoes);
    }
  }

  fprintf(fp, "\n");
  fclose(fp);

  return 0;
}
