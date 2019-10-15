#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "biblioAgus.h"

void  inicializarActores(eActor lista[],int tam)
{
    int i;
    char nombre[5][50]={"Julieta roberto","Richar darin","Nicole Kidman","Tita merello","Natalia Oreiro"};
    char paisDeOrigen[5][50]={"EEUU","Argentina","Australia","Argentina","Uruguay"};

    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombre,nombre[i]);
        strcpy(lista[i].paisDeOrigen,paisDeOrigen[i]);
    }

}

void  mostrarActoresPorPaisDeOrigen(eActor listaActores[],int tamAct)
{
    mostrarActoresDeUnPais(listaActores,tamAct,"EEUU");
    mostrarActoresDeUnPais(listaActores,tamAct,"Argentina");
    mostrarActoresDeUnPais(listaActores,tamAct,"Australia");
    mostrarActoresDeUnPais(listaActores,tamAct,"Uruguay");
}

void mostrarActor(eActor unActor)
{
    printf("%s\n",unActor.nombre);
}


void mostrarActoresDeUnPais(eActor listaActores[],int tamAct,char lugar[])
{
    int i;
    int flag;
    for(i=0;i<tamAct;i++)
    {
        if(stricmp(listaActores[i].paisDeOrigen,lugar)==0)
        {
             printf("\nActores de : %s\n",lugar);
             flag=1;
             break;
        }
    }
    if(flag)
    {
        for(i=i;i<tamAct;i++)
        {
             if(stricmp(listaActores[i].paisDeOrigen,lugar)==0)
             {
                  mostrarActor(listaActores[i]);
             }
        }
    }
}
