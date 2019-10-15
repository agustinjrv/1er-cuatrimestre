#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "biblioAgus.h"
#define TAM 1000
#define TAMACT 5

int main()
{
    int opcion;
    ePelicula listaPeliculas[TAM];
    eActor listaActores[TAMACT];
    inicializarPeliculas(listaPeliculas,TAM);
    inicializarActores(listaActores,TAMACT);
    hardcodearPeliculas(listaPeliculas);


    do
    {
        getInt("1.Altas de Peliculas\n2.Informar Sobre Peliculas\n3.Modificar pelicula\n4.Baja de pelicula\n5.Salir\nQue desea hacer?\n\n",&opcion,1,5);

        switch(opcion)
        {
        case 1:
            cargarPelicula(listaPeliculas,TAM);
            break;
        case 2:
            informarSobrePelicula(listaPeliculas,TAM,listaActores,TAMACT);
            break;
        case 3:
            modificarPelicula(listaPeliculas,TAM,listaActores);

            break;
        case 4:
            bajaPeliculas(listaPeliculas,TAM,listaActores);
            break;

        }

        system("pause");
        system("cls");

    }
    while(opcion!=5);






    return 0;
}
