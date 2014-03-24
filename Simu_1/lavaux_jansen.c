#define MAX 1000000
#define INITIAL 10

#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "math.h"
#include <stdint.h>
#include <inttypes.h>

uint64_t * Lavaux_Jensens(int init, int MAX)
{
    int i = 0;
    uint64_t * result;
    result = calloc(MAX,  (MAX+1) *sizeof(int64_t));
    long pivot= init;

    for(i=0; i<MAX;i++ )
    {
        *(result+i) =(uint64_t)((31167285*pivot +1)%(uint64_t)(pow(2, 48)));
        pivot =*(result+i);

    }
    return result;
}

void main
{
  uint64_t *resultat_Jensen;
  #pragma omp for
  {
  resultat_Jensen = Lavaux_Jensens(INITIAL,MAX);
  }
  printf("Fait\n");


  /*
  for(i=0;i<MAX;i++)
  {
      printf("%lld \n",*(resultat_Jensen+i) );
  }


  FILE *f_lavaux = fopen("simu_lavaux_Jensen.txt", "w");
  if (f_lavaux == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }

  fprintf(f_lavaux, "%s\n", "Lavaux_Jensen");

  for(i=0; i<MAX;i++)
  {
  fprintf(f_lavaux, "%llu\n", *(resultat_Jensen+i));
  }

  fclose(f_lavaux);

  FILE *f2_lavaux = fopen("simu_Jensen_0_1.txt", "w");
  if (f2_lavaux == NULL)
  {
      printf("Error opening file f2!\n");
      exit(1);
  }
  fprintf(f2_lavaux, "%s\n", "Lavaux_Jensen_0_1");

  for(i=0; i<nombre_chiffres;i++)
  {
      fprintf(f2_lavaux, "%f\n", (float)(*(resultat_Jensen+i)/(float)(pow(2, 48))));
  }

  fclose(f2_lavaux);
  free(resultat_Jensen);
  */
}
