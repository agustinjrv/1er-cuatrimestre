#ifndef ACTORES_H_INCLUDED
#define ACTORES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char paisDeOrigen[50];
    int edad;
    int cargado;
} eActor;

#endif // ACTORES_H_INCLUDED

void  inicializarActores(eActor lista[],int tam);
void  mostrarActoresPorPaisDeOrigen(eActor listaActores[],int tamAct);
void mostrarActor(eActor unActor);
void mostrarActorConEdad(eActor unActor);
void listaActoresMayoresDeEdad(eActor listaActores[],int tamAct);
int BuscarLugarLibreActores(eActor[],int tamAct);
int mostrarActoresDeUnPais(eActor listaActores[],int tamAct,char lugar[]);
void  hardcodearActores(eActor lista[]);
void modificarActor(eActor listaActores[],int TAMACT);
void mostrarActorTodosLosDatos(eActor unActor);


void listarActoresEdadMayorAmenor(eActor listaActores[],int tamAct);
eActor getActor(int i,eActor listaActores[],int tam);
int mostrarActoresDeUnPaisElegido(eActor listaActores[],int tamAct,char opcion[]);
void  bajaActoresDeUnPais(eActor listaActores[],int tamAct);

void cargarActor(eActor[],int tamAct);
