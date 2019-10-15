

#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "actores.h"


typedef struct
{
    int id;
    char titulo[50];
    int codigo;
    int anioDeEstreno;
    int idGenero;
    int idActor;
    int cargado;
} ePelicula;


/** \brief muestra un empleado
 *
 * \param ePelicula empleado que se va a mostrar
 * \param
 * \return void
 *
 */
void mostrarPeliculaSinActor (ePelicula);
void mostrarPeliculaConActor (ePelicula unaPelicula,eActor unActor);
void mostrarPeliculaSoloConGenero (ePelicula);
/** \brief busca un lugar libre,y le pide al usuario que ingrese los datos de un empleado
 *
 * \param ePelicula[] lista para buscar lugar libre
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void cargarPelicula(ePelicula[],int tam);

/** \brief pide los datos de un empleado
 *
 * \param i int es el id del empleado
 * \return ePelicula para guardarlo en un lugaar del array de ePelicula
 *
 */

ePelicula getPelicula(int i,ePelicula listaPeliculas[],int tam);

/** \brief busca un lugar libre dentro del array ePelicula
 *
 * \param ePelicula[] array en el que se buscara lugar libre
 * \param tam int tamaño del array
 * \return int si encontro lugar libre devuelve el numero de id,sino devuelve -1
 *
 */
int BuscarLugarLibre(ePelicula[],int tam);

/** \brief busca si hay empleados que se hayan cargado ,si hay los muestra,y sino muestra un mensaje de que no hay empleados ingresados
 *
 * \param lista[] ePelicula lista que debe mostrar
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void mostrarlistaPeliculasSinActores(ePelicula lista[],int tam);
void mostrarlistaPeliculasConActores(ePelicula listaPeliculas[],int tam,eActor listaActores[]);
/** \brief inicializa los empleados para que empiece el programa sin nada cargado
 *
 * \param lista[] ePelicula lista que se inicializara
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void  inicializarPeliculas(ePelicula lista[],int tam);

/** \brief pide un id para modificar un empleado, si existe nos permite modificar los datos del empleado,sino nos dira que no existe
 *
 * \param lista[] ePelicula lista donde se modificara alguno de los empleados
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void modificarPelicula(ePelicula listaPeliculas[],int tam,eActor listaActores[]);

/** \brief pide un empleado ,si exite nos pregunta si desamos borrarlo,sino dira que no existe ese id
 *
 * \param lista[] ePelicula lista donde estan guardados los empleados
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void bajaPeliculas(ePelicula listaPeliculas[],int tam,eActor listaActores[]);

/** \brief ordena a los empleados por apellido en orden alfabetico
 *
 * \param lista[] ePelicula lista que ordenara
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void ordenarEmpleadosPorApellido(ePelicula lista[],int tam);
/** \brief muestra Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 *
 * \param lista[] ePelicula lista que se informara
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void informarSalarios(ePelicula lista[],int tam);

/** \brief menu que pregunta que desamos informar
 *
 * \param lista[] ePelicula se mostra info sobre este array
 * \param int tamaño de la lista
 * \return void
 *
 */
void informarSobrePelicula(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct);

int validarCodigo(int* codigo,ePelicula listaPelicula[],int tam);

void ordenarPeliculasPorAnioDeEstreno(ePelicula listaPeliculas[],int tam,eActor listaActores[],int orden);

void  mostrarPeliculasPorPaisDeOrigen(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct);

void mostrarPeliculasDeUnPais(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct,char lugar[]);

void mostrarPeliculasPorGenero(ePelicula listaPeliculas[],int tam);

void mostrarPeliculasDeUnGenero(ePelicula listaPeliculas[],int tam,int opcion);

void mostrarCantidadDePeliculasPorCadaGenero(ePelicula listaPeliculas[],int tam);

void mostrarActoresMasSolicitados(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct);

void mostrarGenerosConMenosPeliculas(ePelicula listaPeliculas[],int tam);

void mostrarActoresQueNoTrbajaron(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct);



#endif // PELICULAS_H_INCLUDED
