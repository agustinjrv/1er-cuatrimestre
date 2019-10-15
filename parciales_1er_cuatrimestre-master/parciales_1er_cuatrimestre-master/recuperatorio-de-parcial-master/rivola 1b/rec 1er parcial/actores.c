#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "biblioAgus.h"

void inicializarActores(eActor lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombre," ");
        strcpy(lista[i].paisDeOrigen," ");
        lista[i].edad=0;
        lista[i].cargado=0;

    }

}

void  mostrarActoresPorPaisDeOrigen(eActor listaActores[],int tamAct)
{
    int opcion;
    getInt("Listar actores de...\n1.EEUU\n2.Argentina\n3.Australia\n4.Uruguay\n5.Salir\n\n",&opcion,1,5);

    switch(opcion)
    {
    case 1:
        mostrarActoresDeUnPais(listaActores,tamAct,"EEUU");
        break;
    case 2:
        mostrarActoresDeUnPais(listaActores,tamAct,"Argentina");
        break;
    case 3:
        mostrarActoresDeUnPais(listaActores,tamAct,"Australia");
        break;
    case 4:
        mostrarActoresDeUnPais(listaActores,tamAct,"Uruguay");
        break;
    }




}

void mostrarActor(eActor unActor)
{
    printf("%s\n",unActor.nombre);
}


int mostrarActoresDeUnPais(eActor listaActores[],int tamAct,char lugar[])
{
    int i;
    int retorno=0;
    int flag=0;
    for(i=0;i<tamAct;i++)
    {
        if(stricmp(listaActores[i].paisDeOrigen,lugar)==0 && listaActores[i].cargado==1)
        {
             printf("\nActores de : %s\n",lugar);
             flag=1;
             break;
        }
    }
    if(flag)
    {
        for(i=i;i<tamAct;i++)
        {
             if(stricmp(listaActores[i].paisDeOrigen,lugar)==0 && listaActores[i].cargado==1)
             {
                  mostrarActor(listaActores[i]);
             }
        }
        retorno=1;
    }
    else
    {
        printf("\nNo hay peliculas ingresadas con actores de ese pais\n\n");
        system("pause");
    }

    return retorno;
}

void listarActoresEdadMayorAmenor(eActor listaActores[],int tamAct)
{
    int i;
    int j;
    eActor auxiliar;

    for(i=0; i<tamAct-1; i++)
    {
        for(j=i+1; j<tamAct; j++)
        {
            if(listaActores[i].edad<listaActores[j].edad )
            {
                auxiliar=listaActores[i];
                listaActores[i]=listaActores[j];
                listaActores[j]=auxiliar;
            }
        }
    }


    printf("id--Actor--------------edad\n");

    for(i=0;i<tamAct;i++)
    {
        if(listaActores[i].cargado==1)
        {
             mostrarActorConEdad(listaActores[i]);
        }

    }

}

void mostrarActorConEdad(eActor unActor)
{
    printf("%d--%10s%10d\n",unActor.id,unActor.nombre,unActor.edad);
}

void listaActoresMayoresDeEdad(eActor listaActores[],int tamAct)
{
    int i;

    printf("Actor--------------edad\n");

    for(i=0;i<tamAct;i++)
    {
        if(listaActores[i].edad>=18 && listaActores[i].cargado==1)
        {
            mostrarActorConEdad(listaActores[i]);
        }
    }

}

int BuscarLugarLibreActores(eActor lista[],int tamAct)
{
    int encontro=-1;
    int i;

    for(i=0; i<tamAct; i++)
    {
        if(lista[i].cargado==0)
        {
            encontro=i;
            break;
        }

    }

    return encontro;
}

void cargarActor(eActor listaActores[],int tamAct)
{
    int i=BuscarLugarLibreActores(listaActores,tamAct);

    if(i!=-1)
    {
        listaActores[i]=getActor(i,listaActores,tamAct);
        printf("\nActor ingresado exitosamente!!!\n");
    }
    else
    {
        printf("\nMemoria llena\n");
    }
}

eActor getActor(int i,eActor listaActores[],int tam)
{
    eActor retornarActor;

    retornarActor.id=i+1;
    printf("id :%d.\n",retornarActor.id);
    getString("Ingrese el nombre del actor : ",retornarActor.nombre,1,50);
    getString("ingrese el pais de origen : ",retornarActor.paisDeOrigen,1,50);
    getInt("ingrese la edad del actor : ",&retornarActor.edad,1,100);
    retornarActor.cargado=1;

    return retornarActor;
}

void  hardcodearActores(eActor lista[])
{
    int i;
    char nombre[5][50]={"Julieta roberto","Richar darin","Nicole Kidman","Tita merello","Natalia Oreiro"};
    char paisDeOrigen[5][50]={"EEUU","Argentina","Australia","Argentina","Uruguay"};
    int edad[5]={33,77,11,18,33};

    for(i=0; i<5; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombre,nombre[i]);
        strcpy(lista[i].paisDeOrigen,paisDeOrigen[i]);
        lista[i].edad=edad[i];
        lista[i].cargado=1;

    }
}

void modificarActor(eActor listaActores[],int TAMACT)
{
    int i;
    int opcion;
    fflush(stdin);
    getInt("Ingrese el numero de id del actor a modificar :",&i,1,1000);
    i=i-1;

    if(listaActores[i].cargado)
    {
        system("cls");

        do
        {

            printf("id---------nombre-------pais de origen---------edad\n");
            mostrarActorTodosLosDatos(listaActores[i]);

            getInt("\nQue desea modificar?\n\n1.Nombre\n2.Pais de origen\n3.Edad\n4.Para salir\n",&opcion,1,4);

            switch(opcion)
            {
            case 1:
                getString("Ingrese el nuevo nombre del actor : ",listaActores[i].nombre,1,50);

                break;
            case 2:
                getString("ingrese el nuevo pais de origen : ",listaActores[i].paisDeOrigen,1,50);

                break;
            case 3:
                getInt("ingrese la nueva edad del actor",&listaActores[i].edad,1,100);

                break;
            }

            if(opcion!=4)
            {
                system("pause");
                system("cls");
            }

        }
        while(opcion!=4);

    }
    else
    {
        printf("Error,id de Actor inexistente\n\n");
    }


}

void mostrarActorTodosLosDatos(eActor unActor)
{
     printf("%d%20s%15s%14d\n",unActor.id,unActor.nombre,unActor.paisDeOrigen,unActor.edad);
}

int mostrarActoresDeUnPaisElegido(eActor listaActores[],int tamAct,char opcion[])
{
    int flag;
    getString("Ingrese un Pais : ",opcion,1,50);

    flag=mostrarActoresDeUnPais(listaActores,tamAct,opcion);
}

void  bajaActoresDeUnPais(eActor listaActores[],int tamAct)
{
    char opcion[2];
    char pais[50];
    int flag=0;
    int i;
    flag=mostrarActoresDeUnPaisElegido(listaActores,tamAct,pais);

    if(flag!=0)
    {
        {
            getString("\nDesea eliminar los actores de este pais?ingrese s o n\n",opcion,1,1);

            if(stricmp(opcion,"s")==0)
            {
                for(i=0;i<tamAct;i++)
                {
                    if(stricmp(listaActores[i].paisDeOrigen,pais)==0 && listaActores[i].cargado==1)
                    {
                        listaActores[i].cargado=0;
                    }

                }

                printf("\nSe a eliminado a todos los actores de ese pais\n");
                flag=1;
            }
            else if(stricmp(opcion,"n")==0)
            {
                flag=1;
            }
            else
            {
                printf("error");
            }

        }
        while(flag==0);
    }




}
