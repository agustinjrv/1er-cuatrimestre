#ifndef ACTORES_H_INCLUDED
#define ACTORES_H_INCLUDED

#include "Peliculas.h"

typedef struct
{
    int id;
    char nombre[50];
    char PaisDeOrigen[50];
} eActor;


void mostrarListaPeliculasConActores(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarListaPeliculasConActoresEEUU(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarListaPeliculasConActoresArgentina(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarListaPeliculasConActoresAustalia(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarListaPeliculasConActoresUruguay(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarListaPeliculasConActoresDeNacionalidadElegida(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarListaPeliculasConGeneros(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarCantidadDePeliculasPorGenero(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarActoresQueMasPeliculasProtagonizaron(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarGeneroConMenosPeliculas(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarActoresQueNoTrabajaron(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);


void  hardcodearActores(eActor lista[],int tam);


/** \brief menu que pregunta que desamos informar
 *
 * \param lista[] ePelicula se mostra info sobre este array
 * \param int tamaño de la lista
 * \return void
 *
 */
void informarSobrePelicula(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

/** \brief busca si hay Peliculas que se hayan cargado ,si hay los muestra,y sino muestra un mensaje de que no hay Peliculas ingresados
 *
 * \param lista[] ePelicula lista que debe mostrar
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void mostrarListaPeliculasConGeneroActor(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void mostrarPeliculaConActoresGeneros(ePelicula unaPelicula,eActor unActor,char genero[]);

void mostrarPeliculaSegunSuGeneros(ePelicula unaPelicula);

void mostrarPeliculaConActores(ePelicula unaPelicula,eActor unActor,char genero[]);

void mostrarPeliculaConActoresDeUnaNacionalidad(ePelicula unaPelicula,eActor unActor);

void mostrarPeliculaConActoresArgentina(ePelicula unaPelicula,eActor unActor);


void mostrarListaPeliculas(ePelicula listaPeliculas[],int tam );

void mostrarPelicula(ePelicula listaPeliculas,char genero[]);

/** \brief pide un id para modificar un Pelicula, si existe nos permite modificar los datos del Pelicula,sino nos dira que no existe
 *
 * \param lista[] ePelicula lista donde se modificara alguno de los Peliculas
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void modificarPelicula(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

/** \brief pide un Pelicula ,si exite nos pregunta si desamos borrarlo,sino dira que no existe ese id
 *
 * \param lista[] ePelicula lista donde estan guardados los Peliculas
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void bajaPelicula(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);

void ordenarActoresPorPais(ePelicula listaPeliculas[],int tam ,eActor listaActores[],int aTam);






#endif // ACTORES_H_INCLUDED
