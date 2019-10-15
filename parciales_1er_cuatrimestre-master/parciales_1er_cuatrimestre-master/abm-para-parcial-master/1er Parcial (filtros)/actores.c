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
    int opcion;
    getInt("Listar actores de...\n1.EEUU\n2.Argentina\n3.Australia\n4.Uruguay\n5.Salir\n\n",&opcion,1,5);

    switch(opcion)
    {
    case 1:
        mostrarActoresDeUnPais(listaActores,tamAct,"EEUU");
        break;
    case 2:
        mostrarActoresDeUnPais(listaActores,tamAct,"Argentina");
        break;
    case 3:
        mostrarActoresDeUnPais(listaActores,tamAct,"Australia");
        break;
    case 4:
        mostrarActoresDeUnPais(listaActores,tamAct,"Uruguay");
        break;
    }




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
    else
    {
        printf("\nNo hay peliculas ingresadas con actores de ese paias\n\n");
    }
}
