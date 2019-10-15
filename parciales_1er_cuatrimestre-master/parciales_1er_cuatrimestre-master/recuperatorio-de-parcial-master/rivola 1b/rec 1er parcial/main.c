#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "biblioAgus.h"
#define TAM 1000
#define TAMACT 1000

int main()
{
    int opcion;
    ePelicula listaPeliculas[TAM];
    eActor listaActores[TAMACT];
    inicializarPeliculas(listaPeliculas,TAM);
    inicializarActores(listaActores,TAMACT);
    hardcodearActores(listaActores);
    hardcodearPeliculas(listaPeliculas);
    char pais[50]={"lalal"};


    do
    {
        getInt("1.Altas de Peliculas\n2.Informar Sobre Peliculas\n3.Modificar pelicula\n4.Baja de pelicula\n5.alta de Actores\n6.modificar Actor\n7.listar Actores de un pais elegido\n8.baja de actores de un pais\n9.Salir\nQue desea hacer?\n\n",&opcion,1,9);

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
        case 5:
            cargarActor(listaActores,TAMACT);
            break;
        case 6:

            modificarActor(listaActores,TAMACT);
            break;
        case 7:
            mostrarActoresDeUnPaisElegido(listaActores,TAMACT,pais);

            break;
        case 8:

            bajaActoresDeUnPais(listaActores,TAMACT);
            break;
        }

        system("pause");
        system("cls");

    }
    while(opcion!=9);






    return 0;
}
