#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Peliculas.h"
#include "actores.h"
#include "biblioAgus.h"
#define TAM 20
#define ACANT 5

int main()
{
    int opcion;
    ePelicula listaPeliculas[TAM];
    eActor listaActores[ACANT];
    hardcodearActores(listaActores,ACANT);
    inicializarPeliculas(listaPeliculas,TAM);
    hardcodearPeliculas(listaPeliculas);

    do
    {
        getInt("1.Altas de peliculas\
               \n2.Informar sobre peliculas\
               \n3.Modificar datos de pelicula\
               \n4.Baja pelicula\
               \n5.Salir\
               \nQue desea hacer?\n\n",&opcion,1,5);

        switch(opcion)
        {
        case 1:

            cargarPelicula(listaPeliculas,TAM);

            break;

        case 2:

            informarSobrePelicula(listaPeliculas,TAM,listaActores,ACANT);

            break;

        case 3:

            modificarPelicula(listaPeliculas,TAM,listaActores,ACANT);


            break;
        case 4:
            bajaPelicula(listaPeliculas,TAM,listaActores,ACANT);

            break;

        }

        system("pause");
        system("cls");

    }
    while(opcion!=5);


    return 0;
}
