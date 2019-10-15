#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "actores.h"
#include "genero.h"
#define TAM 1000



void  hardcodearActores(eActor lista[],int tam)
{
    int i;
    char nombre[5][50]= {"julieta roberto","Roberto deniro","Richar darin","tita merelo","sandro"};
    char pais[5][50]={"EEUU","EEUU","Argentina","Argentina","Argentina"};

    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombreApellido,nombre[i]);
        strcpy(lista[i].PaisDeOrigen,pais[i]);
    }

}


