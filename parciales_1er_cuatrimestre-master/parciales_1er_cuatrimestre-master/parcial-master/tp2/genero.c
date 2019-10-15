#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "actores.h"
#include "genero.h"
#define TAM 1000

void  hardcodearGenero(eGenero lista[],int tam)
{
    int i;
    char nombre[4][50]= {"accion","comedia ","terror","otro"};

    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombre,nombre[i]);

    }

}
