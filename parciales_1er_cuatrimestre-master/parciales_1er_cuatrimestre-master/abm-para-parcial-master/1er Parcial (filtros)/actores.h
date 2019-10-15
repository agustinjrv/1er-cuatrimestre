#ifndef ACTORES_H_INCLUDED
#define ACTORES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char paisDeOrigen[50];
} eActor;

#endif // ACTORES_H_INCLUDED

void  inicializarActores(eActor lista[],int tam);
void  mostrarActoresPorPaisDeOrigen(eActor listaActores[],int tamAct);
void mostrarActor(eActor unActor);
void mostrarActoresDeUnPais(eActor listaActores[],int tamAct,char lugar[]);

