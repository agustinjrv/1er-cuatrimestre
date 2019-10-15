#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
//#include "actores.h"
//#include "genero.h"
#define TAMP 1000
#define TAMA 5
#define TAMG 4


int main()
{
    int opcion;
    ePelicula listaPeliculas[TAMP];
    eGenero ListaGeneros[5];
    eActor ListaActores[4];

    hardcodearActores(ListaActores,5);
    hardcodearGenero(ListaGeneros,4);

    inicializarPeliculas(listaPeliculas,TAMP);

    do
    {
        getInt("1. Altas\n2.Listar\nQue desea hacer?\n\n",&opcion,1,5);

        switch(opcion)
        {
        case 1:

            cargarPelicula(listaPeliculas,TAMP);
            break;

        case 2:
            informarSobrePelicula(listaPeliculas[],TAMP);

            break;

        }

    }while(opcion!=3);


    return 0;
}
