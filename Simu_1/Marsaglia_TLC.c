//
//  Marsaglia_TLC.c
//  SIMU
//
//  Created by Slimane AGOURAM on 30/03/2014.
//  Copyright (c) 2014 Slimane AGOURAM. All rights reserved.
//

#define MAX 100000 //nombres pr géneration
#define INITIAL 10 //nombre de départ pour l'algo
#define NTCL 12 //nombre de générations a utiliser pour le théoreme central limite

#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "math.h"
#include <stdint.h>
#include <inttypes.h>
#include <time.h>


float  * Marsaglia(long init, int maximum)
{


    int i= 0;
    long pivot = init;
    uint64_t *result;
    float* result_1_0;
    result = calloc(maximum,  (maximum) *sizeof(int64_t));
    result_1_0 = calloc(maximum,  (maximum) *sizeof(int64_t));

    #pragma omp parallel
    {
      #pragma omp for
    for (i=0;i<maximum ; i++)
    {

        *(result+i) = (uint64_t)(69069*pivot)%(uint64_t)pow(2,32);
        pivot = *(result+i);
    }

    for (i=0;i<maximum ; i++)
    {

        *(result_1_0+i) = (float)*(result+i)/(uint64_t)pow(2,32);
    }

}
return result_1_0;
}



void main()
{


int i,j;
float temp=0;
float * result_Marsaglia = calloc(MAX, (MAX+1)*sizeof(float));
float* tableau[NTCL];



for(i=0; i<NTCL;i++)
{
		tableau[i] = Marsaglia(INITIAL +i, MAX); //initial+i :pour ne pas la méme serie de vairables a chaque fois
}



for(j=0; j<MAX; j++)
{
for(i=0; i<NTCL;i++)
{
	temp = *(tableau[i]+j) + temp;
}

	*(result_Marsaglia+j)= (temp - (NTCL/2.0))/sqrt(NTCL/12.0);
	temp=0;
}

//imprimer les résutats à la console
/*for(i=0;i<MAX;i++)
{
	printf("%f \n", *(result_Marsaglia+i));
}*/

//ouverture  du fichier et ecriture du pointeur de résultats.
FILE *f_Marsaglia_TCL = fopen("Marsaglia_TLC.txt", "w");
if (f_Marsaglia_TCL == NULL)
{
    printf("Error opening file f_Marsaglia_TCL!\n");
    exit(1);
}

//fwrite(result_Marsaglia, sizeof(float),MAX,f_Marsaglia_TCL);
fprintf(f_Marsaglia_TCL, "%s\n","Marsaglia_TCL_Gauss" );
for(i=0;i<MAX;i++)
{
fprintf(f_Marsaglia_TCL, "%f\n",*(result_Marsaglia+i) );
}
fclose(f_Marsaglia_TCL);


printf("Génération Variables aléatoires suivant une loi normale :Fait :-) \n");
}

