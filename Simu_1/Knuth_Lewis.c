#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long * knuth_lewis(long initial, int nombre)
{
  int i= 0;
  long pivot = initial;
  long * result = malloc(nombre *sizeof(long));
  for (i=0;i<nombre ; i++)
  {

    *(result+i) = (1664525*pivot + 1013904223) %pow(2,32);
    pivot = *(result+i);
  }

  return result;
}



int main(int argc, const char * argv[])
{

    long initial,i;
    int nombre;
    long randomRes;

    // insert code here...
    printf("donner le nombre initial souhaité\n");
    scanf("%l",initial );
    printf("donner le nombre a  générer \n");
    scang("%d",nombre);

    randomRes = knuth_lewis(initial, nombre);
    for(i=0;i<nombre;i++)
    {
      printf("%l\n", *(randomRes+i));

    }


    return 0;
}
