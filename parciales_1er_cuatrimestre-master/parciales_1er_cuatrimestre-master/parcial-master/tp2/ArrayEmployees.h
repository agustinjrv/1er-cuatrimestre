typedef struct
{
    int id;
    int codigo;
    char titulo[50];
    char fechaDeEstreno[50];
    int idGenero;
    int idActor;
    int cargado;
} ePelicula;

typedef struct
{
    int id;
    char nombreApellido[50];
    char PaisDeOrigen[50];
} eActor;

typedef struct
{
    int id;
    char nombre[50];
} eGenero;

void  hardcodearActores(eActor lista[],int tam);
void  hardcodearGenero(eGenero lista[],int tam);


/** \brief esta funcion muestra un mensaje, pide un string ademas valida que lo sea y el tamaño
 *
 * \param mensaje[] char mensaje a mostrar
 * \param input[] char donde se guarda el string
 * \param tamMin int tamaño minimo del string
 * \param tamMax int tamaño maximo del string
 * \return void
 *
 */
void getString(char mensaje[],char input[],int tamMin,int tamMax);
/** \brief esta funcion muestra un mensaje, pide un int ademas valida que lo sea y el tamaño
 *
 * \param mensaje[] char mensaje a mostrar
 * \param numero int* donde se guarda el int
 * \param tamMin int tamaño minimo del int
 * \param tamMax int tamaño maximo del int
 * \return void
 *
 */
void getInt(char mensaje[],int *numero,int tamMin,int tamMax);
/** \brief esta funcion muestra un mensaje, pide un float ademas valida que lo sea y el tamaño
 *
 * \param mensaje[] char mensaje a mostrar
 * \param numero float* donde se guarda el float
 * \param tamMin float tamaño minimo del float
 * \param tamMax float tamaño maximo del float
 * \return void
 *
 */
void getFloat(char mensaje[],float *numero,float tamMin,float tamMax);

void mostrarPelicula (ePelicula,eActor,eGenero);

void cargarPelicula(ePelicula[],int tam);

ePelicula getPelicula(int i);

int getGenero();

int getActor();

int BuscarLugarLibre(ePelicula[],int tam);

void mostrarListaPeliculas(ePelicula [],int tam,eActor[],eGenero[]);

void inicializarPeliculas(ePelicula lista[],int tam);

void informarSobrePelicula(ePelicula lista[],int);


