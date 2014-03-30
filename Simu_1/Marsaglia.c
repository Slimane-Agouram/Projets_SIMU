#define MAX 1000000
#define INITIAL 10

#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "math.h"
#include <stdint.h>
#include <inttypes.h>



uint64_t  * Marsaglia(long init, int maximum)
{


    int i= 0;
    long pivot = init;
    uint64_t *result;
    result = calloc(maximum,  (maximum) *sizeof(int64_t));
    #pragma omp parallel
    {
      #pragma omp for
    for (i=0;i<maximum ; i++)
    {

        *(result+i) = (uint64_t)(69069*pivot)%(uint64_t)pow(2,32);
        pivot = *(result+i);
    }
}
return result;


}

void main()
{



  uint64_t *resultat_Marsaglia;
resultat_Marsaglia=Marsaglia(INITIAL, MAX);
float * resultat_float;
resultat_float = calloc(MAX,  (MAX) *sizeof(float));

printf("Fait\n");



FILE *f_Marsaglia = fopen("simu_Marsaglia_fwrite.jpeg", "wb");
if (f_Marsaglia == NULL)
{
    printf("Error opening file f_Marsaglia!\n");
    exit(1);
}

fwrite(resultat_Marsaglia, sizeof(uint64_t),MAX,f_Marsaglia);
fclose(f_Marsaglia);


}
