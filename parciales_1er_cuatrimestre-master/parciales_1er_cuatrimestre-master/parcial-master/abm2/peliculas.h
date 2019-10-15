#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED


typedef struct
{
    int id;
    char titulo[50];
    int anioDeEstreno;
    int codigo;
    int idGenero;
    int idActor;
    int cargado;

} ePelicula;



/** \brief busca un lugar libre,y le pide al usuario que ingrese los datos de un Pelicula
 *
 * \param ePelicula[] lista para buscar lugar libre
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void cargarPelicula(ePelicula[],int tam);

/** \brief pide los datos de un Pelicula
 *
 * \param i int es el id del Pelicula
 * \return ePelicula para guardarlo en un lugaar del array de ePelicula
 *
 */

ePelicula getPelicula(int i,ePelicula lista[],int tam);

/** \brief busca un lugar libre dentro del array ePelicula
 *
 * \param ePelicula[] array en el que se buscara lugar libre
 * \param tam int tamaño del array
 * \return int si encontro lugar libre devuelve el numero de id,sino devuelve -1
 *
 */
int BuscarLugarLibre(ePelicula[],int tam);

/** \brief inicializa los Peliculas para que empiece el programa sin nada cargado
 *
 * \param lista[] ePelicula lista que se inicializara
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void  inicializarPeliculas(ePelicula lista[],int tam);





/** \brief ordena a los Peliculas por apellido en orden alfabetico
 *
 * \param lista[] ePelicula lista que ordenara
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void ordenarPeliculasPorFechaEstreno(ePelicula lista[],int tam);



/** \brief inicializa los Peliculas para que empiece el programa sin nada cargado
 *
 * \param lista[] ePelicula lista que se inicializara
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void  hardcodearPeliculas(ePelicula lista[]);

int pedirCodigo(ePelicula lista[],int tam);



#endif // PELICULAS_H_INCLUDED
