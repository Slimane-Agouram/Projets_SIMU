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
    for (i=0;i<maximum ; i++)
    {

        *(result+i) = (uint64_t)(69069*pivot)%(uint64_t)pow(2,32);
        pivot = *(result+i);
    }

    return result;
}

void main()
{
  uint64_t *resultat_Marsaglia;
#pragma omp prarallel for
{
resultat_Marsaglia=Marsaglia(INITIAL, MAX);
}
printf("Fait\n");


/*for(i=0;i<MAX;i++)
{
    printf("%lld \n",*(resultat_Marsaglia+i) );
}


FILE *f_Marsaglia = fopen("simu_Marsaglia.txt", "w");
if (f_MArsaglia == NULL)
{
    printf("Error opening file f_Marsaglia!\n");
    exit(1);
}

fprintf(f_Marsaglia, "%s\n", "Marsaglia");

for(i=0; i<MAX;i++)
{
    fprintf(f_Marsaglia, "%llu\n", *(resultat_Marsaglia+i));
}

fclose(f_Marsaglia);


FILE *f2_Marsaglia = fopen("simu_Marsaglia_0_1.txt", "w");
if (f2_Marsaglia == NULL)
{
    printf("Error opening file f2_Marsaglia!\n");
    exit(1);
}
fprintf(f2_Marsaglia, "%s\n", "Marsaglia_0_1");

for(i=0; i<MAX;i++)
{
    fprintf(f2_Marsaglia, "%f\n", (float)(*(resultat_Marsaglia+i)/(float)(pow(2, 32))));
}

fclose(f2_Marsaglia);

free(resultat_Marsaglia);
*/

}
