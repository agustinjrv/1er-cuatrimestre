#ifndef BIBLIOAGUS_H_INCLUDED
#define BIBLIOAGUS_H_INCLUDED

int Sumar(int numero1,int numero2);
int Restar(int numero1,int numero2);
int Multiplicar(int numero1,int numero2);
float Dividir(int numero1,int numero2);
int Factorizar(int numero);

/** \brief esta funcion muestra un mensaje, pide un string ademas valida que lo sea y el tama�o
 *
 * \param mensaje[] char mensaje a mostrar
 * \param input[] char donde se guarda el string
 * \param tamMin int tama�o minimo del string
 * \param tamMax int tama�o maximo del string
 * \return void
 *
 */
void getString(char mensaje[],char input[],int tamMin,int tamMax);

/** \brief esta funcion muestra un mensaje, pide un int ademas valida que lo sea y el tama�o
 *
 * \param mensaje[] char mensaje a mostrar
 * \param numero int* donde se guarda el int
 * \param tamMin int tama�o minimo del int
 * \param tamMax int tama�o maximo del int
 * \return void
 *
 */
void getInt(char mensaje[],int *numero,int tamMin,int tamMax);

/** \brief esta funcion muestra un mensaje, pide un float ademas valida que lo sea y el tama�o
 *
 * \param mensaje[] char mensaje a mostrar
 * \param numero float* donde se guarda el float
 * \param tamMin float tama�o minimo del float
 * \param tamMax float tama�o maximo del float
 * \return void
 *
 */
void getFloat(char mensaje[],float *numero,float tamMin,float tamMax);



/** \brief inicializa los Peliculas para que empiece el programa sin nada cargado
 *
 * \param lista[] ePelicula lista que se inicializara
 * \param tam int tama�o de la lista
 * \return void
 *
 */
//void  inicializarPeliculas(ePelicula lista[],int tam);



#endif // BIBLIOAGUS_H_INCLUDED
