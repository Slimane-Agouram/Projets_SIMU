//
//  main.c
//  SIMU1
//
//  Created by Slimane AGOURAM on 05/03/2014.
//  Copyright (c) 2014 Slimane AGOURAM. All rights reserved.
//
#define MAX_NBRE INT_MAX

#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "math.h"
#include <stdint.h>
#include <inttypes.h>
#include "gmp.h"

uint64_t * Lavaux_Jensens(int initial, int nombre_chiffres)
{
    int i = 0;
    uint64_t * result;
    result = calloc(nombre_chiffres,  (nombre_chiffres+1) *sizeof(int64_t));
    long pivot= initial;
    
    for(i=0; i<nombre_chiffres;i++ )
    {
        *(result+i) =(uint64_t)((31167285*pivot +1)%(uint64_t)(pow(2, 48)));
        pivot =*(result+i);

    }
    return result;
}


uint64_t * knuth_lewis(long initial, int nombre_chiffres)
{
    int i= 0;
    long pivot = initial;
    uint64_t *result;
    result = calloc(nombre_chiffres,  (nombre_chiffres+1) *sizeof(int64_t));
    for (i=0;i<nombre_chiffres ; i++)
    {
        
        *(result+i) = (uint64_t)(1664525*pivot + 1013904223)%(uint64_t)pow(2,32);
        pivot = *(result+i);
    }
    
    return result;
}
uint64_t  * Marsaglia(long initial, int nombre_chiffres)
{
    int i= 0;
    long pivot = initial;
    uint64_t *result;
    result = calloc(nombre_chiffres,  (nombre_chiffres) *sizeof(int64_t));
    for (i=0;i<nombre_chiffres ; i++)
    {
        
        *(result+i) = (uint64_t)(69069*pivot)%(uint64_t)pow(2,32);
        pivot = *(result+i);
    }
    
    return result;
}

uint64_t  * MitchelMoore(long initial, int nombre_chiffres)
{
    int i= 0;
    uint64_t *result;
    //uint64_t *resultat_intermediaire =calloc(55,  (55) *sizeof(int64_t));
    //resultat_intermediaire = Marsaglia(initial, 55);
    result = calloc(nombre_chiffres,  (nombre_chiffres+1) *sizeof(int64_t));
    result = Marsaglia(initial, 55);
    for (i=55;i<nombre_chiffres ; i++)
    {
        
        *(result+i) = (uint64_t)(*(result + (i-24)) + *(result +(i-55)))%(uint64_t)pow(2,55);
    }
    
    return result;
}






int main(int argc, const char * argv[])
{
    

    int nombre_chiffres, initial=0, i;
    uint64_t *resultat_Jensen,*resultat_lewis, * resultat_Marsaglia, *resultat_Moore;
    
    
    printf("Donner le nombre de variables a génerer ainsi que l'element intial :/n nombre d'élelments a generer :");
    scanf("%d", &nombre_chiffres);
    printf("le nombre saisi est %d :",nombre_chiffres );
    printf("element initial ?: ");
    scanf("%d", &initial);
    printf("l'initial est %d :\n",initial );
    
    //Lavaux_Jensen ///////////////////////////////////////////////////////////////////////////////////
    
    resultat_Jensen = Lavaux_Jensens(initial, nombre_chiffres);

    for(i=0;i<nombre_chiffres;i++)
    {
        printf("%lld \n",*(resultat_Jensen+i) );
    }
    
    printf("debut extraction vers fichier \n");

   
    FILE *f = fopen("simu_lavaux_Jensen.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    /* print some text */
    fprintf(f, "%s\n", "Lavaux_Jensen");

    for(i=0; i<nombre_chiffres;i++)
    {
    fprintf(f, "%llu\n", *(resultat_Jensen+i));
    }
    
    fclose(f);
    
    
    FILE *f2 = fopen("simu_Jensen_0_1.txt", "w");
    if (f2 == NULL)
    {
        printf("Error opening file f2!\n");
        exit(1);
    }
    fprintf(f2, "%s\n", "Lavaux_Jensen_0_1");

    for(i=0; i<nombre_chiffres;i++)
    {
        fprintf(f2, "%f\n", (float)(*(resultat_Jensen+i)/(float)(pow(2, 48))));
    }
    
    fclose(f2);
    free(resultat_Jensen);
    
    //Knuth_lewis////////////////////////////////////////////////////////////
    resultat_lewis=knuth_lewis(initial, nombre_chiffres);
    
    for(i=0;i<nombre_chiffres;i++)
    {
        printf("%lld \n",*(resultat_lewis+i) );
    }
    
    
    FILE *f_lewis = fopen("simu_lewis.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file f_lewis!\n");
        exit(1);
    }
    
    /* print some text */
    fprintf(f_lewis, "%s\n", "Knuth_Lewis");
    
    for(i=0; i<nombre_chiffres;i++)
    {
        fprintf(f_lewis, "%llu\n", *(resultat_lewis+i));
    }
    
    fclose(f_lewis);
    
    
    FILE *f2_lewis = fopen("simu_lewis_0_1.txt", "w");
    if (f2 == NULL)
    {
        printf("Error opening file f2_lewis!\n");
        exit(1);
    }
    fprintf(f2_lewis, "%s\n", "Knuth_Lewis_0_1");

    for(i=0; i<nombre_chiffres;i++)
    {
        fprintf(f2_lewis, "%f\n", (float)(*(resultat_lewis+i)/(float)(pow(2, 32))));
    }
    
    fclose(f2_lewis);
    free(resultat_lewis);
    
    //Marsaglia /////////////////////////////////////////////
    
    resultat_Marsaglia=Marsaglia(initial, nombre_chiffres);
    
    for(i=0;i<nombre_chiffres;i++)
    {
        printf("%lld \n",*(resultat_Marsaglia+i) );
    }
    
    
    FILE *f_Marsaglia = fopen("simu_Marsaglia.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file f_Marsaglia!\n");
        exit(1);
    }
    
    /* print some text */
    fprintf(f_Marsaglia, "%s\n", "Marsaglia");
    
    for(i=0; i<nombre_chiffres;i++)
    {
        fprintf(f_Marsaglia, "%llu\n", *(resultat_Marsaglia+i));
    }
    
    fclose(f_Marsaglia);
    
    
    FILE *f2_Marsaglia = fopen("simu_Marsaglia_0_1.txt", "w");
    if (f2 == NULL)
    {
        printf("Error opening file f2_Marsaglia!\n");
        exit(1);
    }
    fprintf(f2_Marsaglia, "%s\n", "Marsaglia_0_1");
    
    for(i=0; i<nombre_chiffres;i++)
    {
        fprintf(f2_Marsaglia, "%f\n", (float)(*(resultat_Marsaglia+i)/(float)(pow(2, 32))));
    }
    
    fclose(f2_Marsaglia);
    
    free(resultat_Marsaglia);

    //Mitchel Moore /////////////////////////////
    
    printf("fin");
    resultat_Moore = MitchelMoore(initial, nombre_chiffres);
    for (i=0;i<nombre_chiffres ; i++) {
        printf("%llu \n", *(resultat_Moore +i));
    }
    
    FILE *f_Moore = fopen("simu_Moore.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file f_Moore!\n");
        exit(1);
    }
    
    
    /* print some text */
    fprintf(f_Moore, "%s\n", "MitchelMoore");
    
    for(i=0; i<nombre_chiffres;i++)
    {
        fprintf(f_Moore, "%llu\n", *(resultat_Moore+i));
    }
    
    fclose(f_Moore);
    
    
    FILE *f2_Moore = fopen("simu_Moore_0_1.txt", "w");
    if (f2 == NULL)
    {
        printf("Error opening file f2_Moore!\n");
        exit(1);
    }
    fprintf(f2_Moore, "%s\n", "Moore_0_1");
    
    for(i=0; i<55;i++)
    {
        fprintf(f2_Moore, "%f\n", (float)(*(resultat_Moore+i)/(float)(pow(2, 32))));
    }
    for(i=55; i<nombre_chiffres;i++)
    {
        fprintf(f2_Moore, "%f\n", (float)(*(resultat_Moore+i)/(float)(pow(2, 55))));
    }
    
    fclose(f2_Moore);


    
    
    return 0;
}

