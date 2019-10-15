#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "biblioAgus.h"

char genero[4][50]={"accion","comedia","terror","otro"};


ePelicula getPelicula(int i,ePelicula listaPeliculas[],int tam)
{
    ePelicula retornarPelicula;
    int flag=0;

    retornarPelicula.id=i+1000;
    printf("id :%d.\n",retornarPelicula.id);
    getString("Ingrese el titulo de la pelicula : ",retornarPelicula.titulo,1,50);

    do
    {
        getInt("Ingrese el codigo de la pelicula : ",&retornarPelicula.codigo,100,999);
        flag=validarCodigo(&retornarPelicula.codigo,listaPeliculas,tam);

    }while(flag==0);

    getInt("ingrese el anio de estreno: ",&retornarPelicula.anioDeEstreno,1894,2025);
    getInt("De que genero es la pelicula?\n\n1.Accion\n2.Comedia\n3.Terror\n4.otro\n\n",&retornarPelicula.idGenero,1,4);
    getInt("Cual es el actorPrincipal?\n\n1.Julieta roberto\n2.Richar darin\n3.Nicole Kidman\n4.Tita merello\n5.Natalia Oreiro\n\n",&retornarPelicula.idActor,1,5);
    retornarPelicula.cargado=1;


    return retornarPelicula;
}

void mostrarlistaPeliculasSinActores(ePelicula lista[],int tam)
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].cargado)
        {
            printf("id---------Titulo-------Codigo---Estreno---Genero\n");
            flag=1;
            break;
        }
    }

    if(flag)
    {
        for(i=i; i<tam; i++)
        {
            if(lista[i].cargado)
            {
                mostrarPeliculaSinActor(lista[i]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado empleados\n");
    }


}

void cargarPelicula(ePelicula lista[],int tam)
{
    int i=BuscarLugarLibre(lista,tam);

    if(i!=-1)
    {
        lista[i]=getPelicula(i,lista,tam);
        printf("\nPelicula ingresada exitosamente!!!\n");
    }
    else
    {
        printf("\nMemoria llena\n");
    }

}

void mostrarPeliculaSinActor (ePelicula unaPelicula)
{
    printf("\n%d%15s%10d%10d%10s\n",unaPelicula.id,unaPelicula.titulo,unaPelicula.codigo,unaPelicula.anioDeEstreno,genero[unaPelicula.idGenero-1]);
}

int BuscarLugarLibre(ePelicula lista[],int tam)
{
    int encontro=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].cargado==0)
        {
            encontro=i;
            break;
        }

    }

    return encontro;
}

void modificarPelicula(ePelicula listaPeliculas[],int tam,eActor listaActores[])
{
    int i;
    int opcion;
    fflush(stdin);
    getInt("Ingrese el numero de id de la pelicula a modificar :",&i,1000,20000);
    i=i-1000;

    if(listaPeliculas[i].cargado)
    {
        system("cls");

        do
        {

            printf("id---------Titulo-------Codigo---Estreno---Genero----Actor principal\n");
            mostrarPeliculaConActor(listaPeliculas[i],listaActores[listaPeliculas[i].idActor-1]);

            getInt("\nQue desea modificar?\n\n1. Titulo\n2. Actor\n3. Anio de estreno\n4. Para salir\n",&opcion,1,4);

            switch(opcion)
            {
            case 1:
                getString("Ingrese el nuevo titulo de la pelicula : \n",listaPeliculas[i].titulo,1,50);

                break;
            case 2:
                getInt("Cual es el actorPrincipal?\n\n1.Julieta roberto\n2.Richar darin\n3.Nicole Kidman\n4.Tita merello\n5.Natalia Oreiro\n\n",&listaPeliculas[i].idActor,1,5);

                break;
            case 3:
                getInt("Ingrese el anio de estreno : ",&listaPeliculas[i].anioDeEstreno,1894,2025);

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
        printf("Error,id de Pelicula inexistente\n\n");
    }


}

void bajaPeliculas(ePelicula listaPeliculas[],int tam,eActor listaActores[])
{
    int flag=0;
    int i;
    char opcion[2];


    getInt("Ingrese el numero de id del empleado a dar de baja :",&i,1000,2000);
    i=i-1000;

    system("pause");


    if(listaPeliculas[i].cargado)
    {
        system("cls");
        printf("id---------Titulo-------Codigo---Estreno---Genero----Actor principal\n");
        mostrarPeliculaConActor(listaPeliculas[i],listaActores[listaPeliculas[i].idActor-1]);

        do
        {
            getString("\nDesea eliminar a esta pelicula?ingrese s o n\n",opcion,1,1);
            opcion[0]=tolower(opcion[0]);


            if(stricmp(opcion,"s")==0)
            {
                listaPeliculas[i].cargado=0;
                printf("\nSe a eliminado la pelicula\n");
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
    else
    {
        printf("\nid de pelicula inexistente\n");
    }

}

void ordenarEmpleadosPorApellido(ePelicula lista[],int tam)
{
   /* int i;
    int j;
    ePelicula auxiliar;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].codigo>lista[j].codigo)
            {
                auxiliar=lista[i];
                lista[i]=lista[j];
                lista[j]=auxiliar;
            }
        }
    }

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].codigo==lista[j].codigo)
            {
                if(strcmp(lista[i].apellido,lista[j].apellido)==1)
                {

                    auxiliar=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxiliar;
                }
            }

        }
    }
    */
}


void informarSobrePelicula(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct)
{
    int opcion;
    int orden;

    getInt("1.Listar los datos de Peliculas sin actores\n2.Listar los datos de Peliculas con actores\n3.Ordenar pelicula por anio de estreno\n4.Listar actores por pais de origen\n5.Salir\nQue desea hacer?\n\n",&opcion,1,5);

    switch(opcion)
    {
        case 1:

            mostrarlistaPeliculasSinActores(listaPeliculas,tam);
            printf("\n");
            break;
        case 2:
            mostrarlistaPeliculasConActores(listaPeliculas,tam,listaActores);
            break;
        case 3:

            getInt("Como desea ordenar?\n0.Desendente\n1.Asendente\n\n",&orden,0,1);
            ordenarPeliculasPorAnioDeEstreno(listaPeliculas,tam,listaActores,orden);
            break;
        case 4:

            mostrarActoresPorPaisDeOrigen(listaActores,tamAct);
            break;
    }

}


void  inicializarPeliculas(ePelicula lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1000;
        strcpy(lista[i].titulo," ");
        lista[i].codigo=000;
        lista[i].anioDeEstreno=0000;
        lista[i].idGenero=-1;
        lista[i].idActor=-1;
        lista[i].cargado=0;
    }
}

void mostrarlistaPeliculasConActores(ePelicula listaPeliculas[],int tam,eActor listaActores[])
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado)
        {
            printf("id---------Titulo-------Codigo---Estreno---Genero----Actor principal\n");
            flag=1;
            break;
        }
    }

    if(flag)
    {
        for(i=i; i<tam; i++)
        {
            if(listaPeliculas[i].cargado)
            {
                mostrarPeliculaConActor(listaPeliculas[i],listaActores[listaPeliculas[i].idActor-1]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado empleados\n");
    }


}
void mostrarPeliculaConActor(ePelicula unaPelicula,eActor unActor)
{
     printf("\n%d%15s%10d%10d%10s%20s\n",unaPelicula.id,unaPelicula.titulo,unaPelicula.codigo,unaPelicula.anioDeEstreno,genero[unaPelicula.idGenero-1],unActor.nombre);
}

int validarCodigo(int* nuevoCodigo,ePelicula listaPelicula[],int tam)
{

    int i;
    int retornar=1;
    for(i=0;i<tam;i++)
    {
        if(*nuevoCodigo==listaPelicula[i].codigo)
        {
            printf("Error,ese codigo ya existe\n");
            retornar=0;
            break;
        }
    }

    return retornar;
}

void ordenarPeliculasPorAnioDeEstreno(ePelicula listaPeliculas[],int tam,eActor listaActores[],int orden)
{
    int i;
    int j;
    ePelicula auxiliar;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(listaPeliculas[i].anioDeEstreno>listaPeliculas[j].anioDeEstreno && orden ==1)
            {
                auxiliar=listaPeliculas[i];
                listaPeliculas[i]=listaPeliculas[j];
                listaPeliculas[j]=auxiliar;
            }
            else if(listaPeliculas[i].anioDeEstreno<listaPeliculas[j].anioDeEstreno && orden ==0)
            {
                auxiliar=listaPeliculas[i];
                listaPeliculas[i]=listaPeliculas[j];
                listaPeliculas[j]=auxiliar;
            }
        }
    }
}
