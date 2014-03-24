#define MAX 1000000
#define INITIAL 10

#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "math.h"
#include <stdint.h>
#include <inttypes.h>
#include <time.h>


void main()
{

/*
FILE *f_RandC = fopen("simu_RandC_0_1.txt", "w");
if (f == NULL)
{
    printf("Error opening file f_RandC!\n");
    exit(1);
}


fprintf(f_RandC, "%s\n", "Rand_C");

srand(INITIAL);

for(i=0; i<MAX;i++)
{
    printf("%f\n", (double)rand() / ((double)(RAND_MAX)+(double)(1)) );
    fprintf(f_RandC, "%f\n",(double)rand() / ((double)(RAND_MAX)+(double)(1)));
}

fclose(f_RandC);*/

float * result_RandC = calloc(MAX, (MAX+1)*sizeof(float));
srand(INITIAL);

#pragma omp for
{
for(i=0; i<MAX;i++)
{
    *(result_RandC+i)=(double)rand() / ((double)(RAND_MAX)+(double)(1)));
}
}

printf("Fait\n");

}
