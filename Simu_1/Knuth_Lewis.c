#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "math.h"
#include <stdint.h>
#include <inttypes.h>
#define MAX 1000000
#define INITIAL 10


uint64_t * knuth_lewis(long initial, int maximum)
{
    int i= 0;
    long pivot = initial;
    uint64_t *result;
    result = calloc(maximum,  (maximum+1) *sizeof(int64_t));
    for (i=0;i<MAX ; i++)
    {

        *(result+i) = (uint64_t)(1664525*pivot + 1013904223)%(uint64_t)pow(2,32);
        pivot = *(result+i);
    }

    return result;
}

void main()
{
  uint64_t *resultat_lewis;
  #pragma omp prarallel
  {
  resultat_lewis=knuth_lewis(INITIAL, MAX);
  }
  printf("Fait\n");


  /*
  for(i=0;i<MAX;i++)
  {
      printf("%lld \n",*(resultat_lewis+i) );
  }


  FILE *f_lewis = fopen("simu_lewis.txt", "w");
  if (f_lewis == NULL)
  {
      printf("Error opening file f_lewis!\n");
      exit(1);
  }

  fprintf(f_lewis, "%s\n", "Knuth_Lewis");

  for(i=0; i<MAX;i++)
  {
      fprintf(f_lewis, "%llu\n", *(resultat_lewis+i));
  }

  fclose(f_lewis);


  FILE *f2_lewis = fopen("simu_lewis_0_1.txt", "w");
  if (f2_lewis == NULL)
  {
      printf("Error opening file f2_lewis!\n");
      exit(1);
  }
  fprintf(f2_lewis, "%s\n", "Knuth_Lewis_0_1");

  for(i=0; i<MAX;i++)
  {
      fprintf(f2_lewis, "%f\n", (float)(*(resultat_lewis+i)/(float)(pow(2, 32))));
  }

  fclose(f2_lewis);
  free(resultat_lewis);
  */

}
