#define MAX 1000000
#define INITIAL 10

#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "math.h"
#include <stdint.h>
#include <inttypes.h>

uint64_t * Lavaux_Jensens(int init, int maximum)
{
    int i = 0;
    uint64_t * result;
    result = calloc(maximum,  (maximum+1) *sizeof(int64_t));
    long pivot= init;
    #pragma omp parallel
    {
    #pragma omp for
    for(i=0; i<maximum;i++ )
    {
        *(result+i) =(uint64_t)((31167285*pivot +1)%(uint64_t)(pow(2, 48)));
        pivot =*(result+i);

    }
  }
    return result;
}

void main()
{
  uint64_t *resultat_Jensen;
  resultat_Jensen = Lavaux_Jensens(INITIAL,MAX);
  int i;

for(i=0;i<MAX;i++)
{
  printf("%f\n",*(resultat_Jensen+i)/pow(2, 48));
}

FILE *f_lavaux = fopen("simu_lavaux_fwrite.txt", "w");
if (f_lavaux == NULL)
{
    printf("Error opening file f_lavaux!\n");
    exit(1);
}

fwrite(resultat_Jensen, sizeof(uint64_t),MAX,f_lavaux);
fclose(f_lavaux);





  printf("Fait\n");

}
