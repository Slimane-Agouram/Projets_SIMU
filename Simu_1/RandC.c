#define MAX 3000000
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


int i;

float * result_RandC = calloc(MAX, (MAX+1)*sizeof(float));
srand(INITIAL);


for(i=0; i<MAX;i++)
{
    *(result_RandC+i)=(float)rand() / ((float)(RAND_MAX)+(float)(1));
}

FILE *f_RandC = fopen("simu_RandC_fwrite.jpeg", "wb");
if (f_RandC == NULL)
{
    printf("Error opening file f_RandC!\n");
    exit(1);
}

fwrite(result_RandC, sizeof(float),MAX,f_RandC);
fclose(f_RandC);


printf("Fait\n");
}
