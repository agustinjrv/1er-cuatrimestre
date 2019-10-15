#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "biblioAgus.h"

char genero[6][50]={"accion","comedia","terror","romantico","otro"};


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

    getInt("1.Listar los datos de Peliculas sin actores\
           \n2.Listar los datos de Peliculas con actores\
           \n3.Ordenar pelicula por anio de estreno\
           \n4.Listar actores de eeuu\
           \n5.Listar actores de un pais elegido\
           \n6.Listar peliculas de un pais elegido\
           \n7.Listar peliculas por genero\
           \n8.Informar cantidad de peliculas por cada genero\
           \n9.informar actores que mas peliculas protagonizaron\
           \n10.Informar Generos con menos peliculas\
           \n11.Informar actor que no trabajo en ninguna peli\
           \n12.Salir\nQue desea hacer?\n\n",&opcion,1,12);

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
            mostrarActoresDeUnPais(listaActores,tamAct,"EEUU");
            break;
        case 5:
            mostrarActoresPorPaisDeOrigen(listaActores,tamAct);
            break;
        case 6:
            mostrarPeliculasPorPaisDeOrigen(listaPeliculas,tam,listaActores,tamAct);
            break;
        case 7:
            mostrarPeliculasPorGenero(listaPeliculas,tam);
            break;
        case 8:
            mostrarCantidadDePeliculasPorCadaGenero(listaPeliculas,tam);
            break;
        case 9:
            mostrarActoresMasSolicitados(listaPeliculas,tam,listaActores,tamAct);
            break;
        case 10:
            mostrarGenerosConMenosPeliculas(listaPeliculas,tam);
            break;
        case 11:

            mostrarActoresQueNoTrbajaron(listaPeliculas,tam,listaActores,tamAct);
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

void  mostrarPeliculasPorPaisDeOrigen(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct)
{
     int opcion;
    getInt("Listar las peliculas de...\n1.EEUU\n2.Argentina\n3.Australia\n4.Uruguay\n5.Salir\n\n",&opcion,1,5);

    switch(opcion)
    {
    case 1:
        mostrarPeliculasDeUnPais(listaPeliculas,tam,listaActores,tamAct,"EEUU");
        break;
    case 2:
        mostrarPeliculasDeUnPais(listaPeliculas,tam,listaActores,tamAct,"Argentina");
        break;
    case 3:
        mostrarPeliculasDeUnPais(listaPeliculas,tam,listaActores,tamAct,"Australia");
        break;
    case 4:
        mostrarPeliculasDeUnPais(listaPeliculas,tam,listaActores,tamAct,"Uruguay");
        break;
    }



}


void mostrarPeliculasDeUnPais(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct,char lugar[])
{
    int i;
    int flag;
    for(i=0;i<tam;i++)
    {
        if(listaPeliculas[i].cargado==1 && (stricmp(listaActores[listaPeliculas[i].idActor-1].paisDeOrigen,lugar)==0))
        {
             printf("\nPeliculas de : %s\n",lugar);
             flag=1;
             break;
        }
    }
    if(flag)
    {
        for(i=i;i<tam;i++)
        {
             if(listaPeliculas[i].cargado==1 && (stricmp(listaActores[listaPeliculas[i].idActor-1].paisDeOrigen,lugar)==0))
             {
                  mostrarPeliculaConActor(listaPeliculas[i],listaActores[listaPeliculas[i].idActor-1]);
             }
        }
    }
    else
    {
        printf("\nNo hay peliculas ingresadas con actores de ese paias\n\n");
    }
}

void mostrarPeliculasPorGenero(ePelicula listaPeliculas[],int tam)
{
     int opcion;
    getInt("Listar las peliculas por genero...\n1.accion\n2.comedia\n3.terror\n4.romántica\n5.Otro\n6.Salir\n\n",&opcion,1,6);


    if(opcion!=6)
    {
        mostrarPeliculasDeUnGenero(listaPeliculas,tam,opcion);
    }
}

void mostrarPeliculasDeUnGenero(ePelicula listaPeliculas[],int tam,int opcion)
{
    int i;
    int flag=0;
    for(i=0;i<tam;i++)
    {
        if(listaPeliculas[i].cargado==1 && listaPeliculas[i].idGenero==opcion)
        {
             printf("\nPeliculas de genero: %s\n",genero[opcion-1]);
             flag=1;
             break;
        }
    }
    if(flag)
    {
        for(i=i;i<tam;i++)
        {
             if(listaPeliculas[i].cargado==1 && listaPeliculas[i].idGenero==opcion)
             {
                  mostrarPeliculaSoloConGenero(listaPeliculas[i]);
             }
        }
    }
    else
    {
        printf("\nNo hay peliculas ingresadas con ese genero\n\n");
    }
}

void mostrarPeliculaSoloConGenero (ePelicula unaPelicula)
{
    printf("\n%d%15s\n",unaPelicula.id,unaPelicula.titulo);
}

void mostrarCantidadDePeliculasPorCadaGenero(ePelicula listaPeliculas[],int tam)
{
    int i;
    int flag=0;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;

    for(i=0;i<tam;i++)
    {

        if(listaPeliculas[i].cargado)
        {
            switch(listaPeliculas[i].idGenero)
            {
                case 1:
                    contador1++;
                    break;
                case 2:
                    contador2++;
                    break;
                case 3:
                    contador3++;
                    break;
                case 4:
                    contador4++;
                    break;
                case 5:
                    contador5++;
                    break;
            }

            flag=1;
        }

    }

    if(flag)
    {
        printf("Genero...\n");
        printf("Accion : %d\nComedia : %d\nTerror : %d\nRomantica : %d\nOtro :%d\n",contador1,contador2,contador3,contador4,contador5);
    }
    else
    {
        printf("\nNo hay peliculas ingresadas\n\n");
    }
}

void mostrarActoresMasSolicitados(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct)
{
     int i;
    int flag=0;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;
    int max;

    for(i=0;i<tam;i++)
    {

        if(listaPeliculas[i].cargado)
        {
            switch(listaPeliculas[i].idActor)
            {
                case 1:
                    contador1++;
                    break;
                case 2:
                    contador2++;
                    break;
                case 3:
                    contador3++;
                    break;
                case 4:
                    contador4++;
                    break;
                case 5:
                    contador5++;
                    break;
            }

            flag=1;
        }
    }

    if(flag)
    {
        printf("Los actores que mas peliculas protagonizaron son :\n");
        max=contador1;

        if(max<contador2)
        {
            max=contador2;
        }
        if(max<contador3)
        {
            max=contador3;
        }
        if(max<contador4)
        {
            max=contador4;
        }
        if(max<contador5)
        {
            max=contador5;
        }

        if(contador1==max)
        {
            printf("%s\n",listaActores[0].nombre);
        }

        if(contador2==max)
        {
            printf("%s\n",listaActores[1].nombre);
        }

        if(contador3==max)
        {
            printf("%s\n",listaActores[2].nombre);
        }

        if(contador4==max)
        {
            printf("%s\n",listaActores[3].nombre);
        }

        if(contador5==max)
        {
            printf("%s\n",listaActores[4].nombre);
        }

        printf("\ny trabajaron en %d peliculas\n\n",max);

    }
    else
    {
        printf("\nNo hay peliculas ingresadas\n\n");
    }

}

void mostrarGenerosConMenosPeliculas(ePelicula listaPeliculas[],int tam)
{
    int i;
    int flag=0;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;
    int min;

    for(i=0;i<tam;i++)
    {

        if(listaPeliculas[i].cargado)
        {
            switch(listaPeliculas[i].idGenero)
            {
                case 1:
                    contador1++;
                    break;
                case 2:
                    contador2++;
                    break;
                case 3:
                    contador3++;
                    break;
                case 4:
                    contador4++;
                    break;
                case 5:
                    contador5++;
                    break;
            }

            flag=1;
        }
    }

    if(flag)
    {
        printf("Los generos con menos peliculas son :\n");
        min=contador1;

        if(min>contador2)
        {
            min=contador2;
        }
        if(min>contador3)
        {
            min=contador3;
        }
        if(min>contador4)
        {
            min=contador4;
        }
        if(min>contador5)
        {
            min=contador5;
        }

        if(contador1==min)
        {
            printf("%s\n",genero[0]);
        }

        if(contador2==min)
        {
            printf("%s\n",genero[1]);
        }

        if(contador3==min)
        {
            printf("%s\n",genero[2]);
        }

        if(contador4==min)
        {
            printf("%s\n",genero[3]);
        }

        if(contador5==min)
        {
            printf("%s\n",genero[4]);
        }

        printf("\nestos generos tienen %d peliculas\n\n",min);

    }
    else
    {
        printf("\nNo hay peliculas ingresadas\n\n");
    }

}


void mostrarActoresQueNoTrbajaron(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct)
{
    int i;
    int flag=0;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;

    for(i=0;i<tam;i++)
    {

        if(listaPeliculas[i].cargado)
        {
            switch(listaPeliculas[i].idActor)
            {
                case 1:
                    contador1++;
                    break;
                case 2:
                    contador2++;
                    break;
                case 3:
                    contador3++;
                    break;
                case 4:
                    contador4++;
                    break;
                case 5:
                    contador5++;
                    break;
            }

            flag=1;
        }
    }

    if(flag && (contador1==0 || contador2==0 || contador3==0 || contador4==0 || contador5==0))
    {
        printf("Los actores que no trabajaron en ninguna pelicula :\n");


        if(contador1==0)
        {
            printf("%s\n",listaActores[0].nombre);
        }

        if(contador2==0)
        {
            printf("%s\n",listaActores[1].nombre);
        }

        if(contador3==0)
        {
            printf("%s\n",listaActores[2].nombre);
        }

        if(contador4==0)
        {
            printf("%s\n",listaActores[3].nombre);
        }

        if(contador5==0)
        {
            printf("%s\n",listaActores[4].nombre);
        }

    }
    else if(flag)
    {
        printf("\nTodos los Actores han trabajado en alguna peli\n\n");
    }
    else
    {
        printf("\nNo hay peliculas ingresadas\n\n");
    }

}
