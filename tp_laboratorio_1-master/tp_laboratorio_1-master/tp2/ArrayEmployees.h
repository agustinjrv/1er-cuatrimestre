typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
    int cargado;
} eEmpleado;


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

/** \brief muestra un empleado
 *
 * \param eEmpleado empleado que se va a mostrar
 * \param
 * \return void
 *
 */
void mostrarEmpleado (eEmpleado);
/** \brief busca un lugar libre,y le pide al usuario que ingrese los datos de un empleado
 *
 * \param eEmpleado[] lista para buscar lugar libre
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void cargarEmpleado(eEmpleado[],int tam);

/** \brief pide los datos de un empleado
 *
 * \param i int es el id del empleado
 * \return eEmpleado para guardarlo en un lugaar del array de eEmpleado
 *
 */

eEmpleado getEmpleado(int i);

/** \brief busca un lugar libre dentro del array eEmpleado
 *
 * \param eEmpleado[] array en el que se buscara lugar libre
 * \param tam int tamaño del array
 * \return int si encontro lugar libre devuelve el numero de id,sino devuelve -1
 *
 */
int BuscarLugarLibre(eEmpleado[],int tam);

/** \brief busca si hay empleados que se hayan cargado ,si hay los muestra,y sino muestra un mensaje de que no hay empleados ingresados
 *
 * \param lista[] eEmpleado lista que debe mostrar
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void mostrarListaEmpleados(eEmpleado lista[],int tam);

/** \brief inicializa los empleados para que empiece el programa sin nada cargado
 *
 * \param lista[] eEmpleado lista que se inicializara
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void  inicializarEmpleados(eEmpleado lista[],int tam);

/** \brief pide un id para modificar un empleado, si existe nos permite modificar los datos del empleado,sino nos dira que no existe
 *
 * \param lista[] eEmpleado lista donde se modificara alguno de los empleados
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void modificarEmpleado(eEmpleado lista[],int tam);

/** \brief pide un empleado ,si exite nos pregunta si desamos borrarlo,sino dira que no existe ese id
 *
 * \param lista[] eEmpleado lista donde estan guardados los empleados
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void bajaEmpleado(eEmpleado lista[], int tam);

/** \brief ordena a los empleados por apellido en orden alfabetico
 *
 * \param lista[] eEmpleado lista que ordenara
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void ordenarEmpleadosPorApellido(eEmpleado lista[],int tam);
/** \brief muestra Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 *
 * \param lista[] eEmpleado lista que se informara
 * \param tam int tamaño de la lista
 * \return void
 *
 */

void informarSalarios(eEmpleado lista[],int tam);

/** \brief menu que pregunta que desamos informar
 *
 * \param lista[] eEmpleado se mostra info sobre este array
 * \param int tamaño de la lista
 * \return void
 *
 */
void informarSobreEmpledo(eEmpleado lista[],int);
