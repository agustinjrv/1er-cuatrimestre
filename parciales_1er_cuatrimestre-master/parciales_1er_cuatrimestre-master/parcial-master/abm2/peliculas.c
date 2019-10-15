#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Peliculas.h"
#include "biblioAgus.h"



ePelicula getPelicula(int i,ePelicula lista[],int tam)
{
    ePelicula retornarPelicula;
    retornarPelicula.id=i+1000;
    printf("id :%d.\n",retornarPelicula.id);
    getString("Ingrese el titulo del Pelicula : ",retornarPelicula.titulo,1,50);
    getInt("Ingrese el anio de estreno : ",&retornarPelicula.anioDeEstreno,1894,2025);

    retornarPelicula.codigo=pedirCodigo(lista ,tam);

    getInt("Ingrese el genero de la peicula :\n\n1.accion\n2.comedia\n3.terror\n4.Romantica\n5.otro \n",&retornarPelicula.idGenero,1,5);
    getInt("Ingrese el actor principal de la peicula :\n\
           \n1.Julieta roberto\
           \n2.Richar darin\
           \n3.Nicole Kidman\
           \n4.Tita merello\
           \n5.Natalia Oreiro\n",&retornarPelicula.idActor,1,5);
    retornarPelicula.cargado=1;

    return retornarPelicula;
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



void ordenarPeliculasPorFechaEstreno(ePelicula lista[],int tam)
{
    int i;
    int j;
    ePelicula auxiliar;


    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].anioDeEstreno>lista[j].anioDeEstreno)
            {
                auxiliar=lista[i];
                lista[i]=lista[j];
                lista[j]=auxiliar;
            }
        }
    }
}





void  inicializarPeliculas(ePelicula lista[],int tam)
{

    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1000;
        strcpy(lista[i].titulo," ");
        lista[i].anioDeEstreno=0000;
        lista[i].codigo=000;
        lista[i].idGenero=0;
        lista[i].idActor=0;
        lista[i].cargado=0;
    }

}

void  hardcodearPeliculas(ePelicula lista[])
{

    int i;
    char titulo[8][50]= {"terminator","thor","it","gladiador","scary movie","sexto sentido","scary movie 2","sexto sentido"};
    int anioDeEstreno[8]= {2020,2019,2018,2018,2012,1990,2015,1999};
    int codigo[8]={999,666,555,777,111,222,101,202};
    int idGenero[8]={1,1,3,4,2,5,2,5};
    int idActor[8]={1,5,4,4,4,4,1,1};

    for(i=0; i<8; i++)
    {
        lista[i].id=i+1000;
        strcpy(lista[i].titulo,titulo[i]);
        lista[i].anioDeEstreno=anioDeEstreno[i];
        lista[i].codigo=codigo[i];
        lista[i].idGenero=idGenero[i];
        lista[i].idActor=idActor[i];
        lista[i].cargado=1;
    }


}

int pedirCodigo(ePelicula lista[],int tam)
{
    int i;
    ePelicula retornarPelicula;
    do
    {
        getInt("Ingrese el codigo del Pelicula : ",&retornarPelicula.codigo,100,999);

        for(i=0;i<tam;i++)
        {
            if(retornarPelicula.codigo==lista[i].codigo)
            {
                printf("Error ese codigo ya existe\n");
                retornarPelicula.codigo=-1;
                break;
            }

        }
    }while(retornarPelicula.codigo==-1);

    return retornarPelicula.codigo;

}







