int Sumar(int numero1,int numero2);
int Restar(int numero1,int numero2);
int Multiplicar(int numero1,int numero2);
float Dividir(int numero1,int numero2);
int Factorizar(int numero);

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

/** \brief inicializa los empleados para que empiece el programa sin nada cargado
 *
 * \param lista[] eEmpleado lista que se inicializara
 * \param tam int tamaño de la lista
 * \return void
 *
 */
//void  hardcodearEmpleados(eEmpleado lista[],int tam);

/** \brief inicializa los empleados para que empiece el programa sin nada cargado
 *
 * \param lista[] eEmpleado lista que se inicializara
 * \param tam int tamaño de la lista
 * \return void
 *
 */
//void  inicializarEmpleados(eEmpleado lista[],int tam);
