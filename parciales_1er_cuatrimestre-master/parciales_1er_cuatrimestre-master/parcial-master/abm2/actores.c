#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Peliculas.h"
#include "biblioAgus.h"
#include "actores.h"

void  hardcodearActores(eActor lista[],int tam)
{
    int i;
    char nombre[5][50]= {"Julieta roberto","Richar darin","Nicole Kidman","Tita merello","Natalia Oreiro"};
    char paisDeOrigen[5][50]= {"EEUU","Argentina","Australia","Argentina","Uruguay"};

    for(i=0; i<tam ; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombre,nombre[i]);
        strcpy(lista[i].PaisDeOrigen,paisDeOrigen[i]);
    }


}

void informarSobrePelicula(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int opcion;



    do
    {
        getInt("1.listar los datos de Peliculas sin actores\
       \n2.listar los datos de Peliculas con actores\
       \n3.Listar por anio de estreno\
       \n4.Listar peliculas con genero y actor\
       \n5.Listar peliculas actores EEUU\
       \n6.Listar Peliculas por nacionalidad elegida \
       \n7.listar peliculas segun su genero\
       \n8.Cantidad de peliculas por genero\
       \n9.Mostrar mas solicitados\
       \n10.Mostrar genero con menos peliculas\
       \n11.Mostrar actores que no trabajaron\
       \n12.Salir\
       \nQue desea hacer?\n",&opcion,1,12);


        switch(opcion)
        {

        case 1:
            mostrarListaPeliculas(listaPeliculas,tam);
            break;
        case 2:
            mostrarListaPeliculasConActores(listaPeliculas,tam,listaActores,aTam);
            break;
        case 3:
            ordenarPeliculasPorFechaEstreno(listaPeliculas,tam);
            mostrarListaPeliculasConActores(listaPeliculas,tam,listaActores,aTam);
            break;

        case 4:
            // ordenarActoresPorPais(listaPeliculas,tam,listaActores,aTam);
            mostrarListaPeliculasConGeneroActor(listaPeliculas,tam,listaActores,aTam);
            break;
        case 5:
            mostrarListaPeliculasConActoresEEUU(listaPeliculas,tam,listaActores,aTam);

            break;
        case 6:
            mostrarListaPeliculasConActoresDeNacionalidadElegida(listaPeliculas,tam,listaActores,aTam);
            break;
        case 7:

            mostrarListaPeliculasConGeneros(listaPeliculas,tam,listaActores,aTam);

            break;
        case 8:
            mostrarCantidadDePeliculasPorGenero(listaPeliculas,tam,listaActores,aTam);

            break;

        case 9:
            mostrarActoresQueMasPeliculasProtagonizaron(listaPeliculas,tam,listaActores,aTam);
            break;
        case 10:
            mostrarGeneroConMenosPeliculas(listaPeliculas,tam,listaActores,aTam);
            break;
        case 11:
            mostrarActoresQueNoTrabajaron(listaPeliculas,tam,listaActores,aTam);
            break;
        }
    }
    while(opcion!=12);


}

void mostrarListaPeliculasConGeneroActor(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int flag=0;
    char generos[5][50]= {"accion","comedia","terror","Romantica","otro"};

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado)
        {
            printf("id\tTitulo\t\tGenero\t\tAcotor P.\n");
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
                mostrarPeliculaConActoresGeneros(listaPeliculas[i],listaActores[(listaPeliculas[i].idActor)-1],generos[(listaPeliculas[i].idGenero)-1]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado Peliculas\n");
    }


}

void mostrarPeliculaConActoresGeneros(ePelicula unaPelicula,eActor unActor,char genero[])
{


    printf("\n%d%11s%15s%20s\n",unaPelicula.id,unaPelicula.titulo,genero,unActor.nombre);

}

void mostrarListaPeliculasConActores(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int flag=0;
    char generos[5][50]= {"accion","comedia","terror","Romantica","otro"};

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado)
        {
            printf("id\tTitulo\t\tEstreno\t    Codigo\tGenero\t\tAcotor P.\n");
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
                mostrarPeliculaConActores(listaPeliculas[i],listaActores[(listaPeliculas[i].idActor)-1],generos[(listaPeliculas[i].idGenero)-1]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado Peliculas\n");
    }


}

void mostrarPeliculaConActores (ePelicula unaPelicula,eActor unActor,char genero[])
{


    printf("\n%d%11s%15d%10d%15s%20s\n",unaPelicula.id,unaPelicula.titulo,unaPelicula.anioDeEstreno,unaPelicula.codigo,genero,unActor.nombre);

}

void mostrarListaPeliculas(ePelicula listaPeliculas[],int tam )
{
    int i;
    int flag=0;
    char generos[5][50]= {"accion","comedia","terror","Romantica","otro"};

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado)
        {
            printf("id\tTitulo\t\tEstreno\t    Codigo\tGenero\n");
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
                mostrarPelicula(listaPeliculas[i],generos[(listaPeliculas[i].idGenero)-1]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado Peliculas\n");
    }


}

void mostrarPelicula(ePelicula unaPelicula,char genero[])
{


    printf("\n%d%11s%15d%10d%15s\n",unaPelicula.id,unaPelicula.titulo,unaPelicula.anioDeEstreno,unaPelicula.codigo,genero);

}

void modificarPelicula(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int opcion;
    char generos[5][50]= {"accion","comedia","terror","Romantica","otro"};
    fflush(stdin);
    getInt("Ingrese el numero de id del Pelicula a modificar :",&i,1000,2000);
    i=i-1000;

    if(listaPeliculas[i].cargado)
    {
        system("cls");

        do
        {

            printf("id\tTitulo\t\tEstreno\t    Codigo\tGenero\n");
            mostrarPeliculaConActores(listaPeliculas[i],listaActores[(listaPeliculas[i].idActor)-1],generos[(listaPeliculas[i].idGenero)-1]);

            getInt("\nQue desea modificar?\n\n1.Titulo\n2.Actor\n3.Anio de estreno\n4.Para salir\n",&opcion,1,4);

            switch(opcion)
            {
            case 1:
                getString("Ingrese el titulo del Pelicula : \n",listaPeliculas[i].titulo,1,50);

                break;
            case 2:
                getInt("Ingrese el actor principal de la peicula :\n\n1.Julieta roberto\n2.Richar darin\n3.Nicole Kidman\n4.Tita merello\n5.Natalia Oreiro\n",&listaPeliculas[i].idActor,1,5);

                break;
            case 3:
                getInt("Ingrese el anio de estreno : ",&listaPeliculas[i].codigo,1000,3000);

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


void bajaPelicula(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int flag=0;
    int i;
    char opcion[2];
    char generos[5][50]= {"accion","comedia","terror","Romantica","otro"};


    getInt("Ingrese el numero de id del Pelicula a dar de baja :",&i,1000,1999);
    i=i-1000;

    system("pause");


    if(listaPeliculas[i].cargado)
    {
        system("cls");
        printf("id\tTitulo\t\tEstreno\t    Codigo\tGenero\t\tAcotor P.\n");

        mostrarPeliculaConActores(listaPeliculas[i],listaActores[(listaPeliculas[i].idActor)-1],generos[(listaPeliculas[i].idGenero)-1]);

        do
        {


            getString("\nDesea eliminar a este Pelicula?\n",opcion,1,1);

            opcion[0]=tolower(opcion[0]);


            if(strcmp(opcion,"s")==0)
            {
                listaPeliculas[i].cargado=0;
                printf("\nSe a eliminado el Pelicula\n");
                flag=1;
            }
            else if(strcmp(opcion,"n")==0)
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
        printf("\nid de Pelicula inexistente\n");
    }

}



void ordenarActoresPorPais(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{

    int i;
    int j;
    eActor auxActor;
    ePelicula auxPelicula;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listaActores[i].PaisDeOrigen,listaActores[j].PaisDeOrigen)==1)
            {
                auxActor=listaActores[i];
                listaActores[i]=listaActores[j];
                listaActores[j]=auxActor;

                auxPelicula.idActor=listaPeliculas[i].idActor;
                listaPeliculas[i].idActor=listaPeliculas[j].idActor;
                listaPeliculas[j].idActor=auxPelicula.idActor;
            }

        }
    }

}


void mostrarListaPeliculasConActoresEEUU(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int flag=0;



    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado && (stricmp(listaActores[listaPeliculas[i].idActor-1].PaisDeOrigen,"EEUU"))==0)
        {
            printf("id\tTitulo\t\tAcotor P.\n");
            flag=1;
            break;
        }
    }

    if(flag)
    {

        for(i=i; i<tam; i++)
        {
            if(listaPeliculas[i].cargado && (stricmp(listaActores[listaPeliculas[i].idActor-1].PaisDeOrigen,"EEUU"))==0)
            {
                mostrarPeliculaConActoresDeUnaNacionalidad(listaPeliculas[i],listaActores[(listaPeliculas[i].idActor)-1]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado Peliculas con actores EEUU\n");
    }

}

void mostrarPeliculaConActoresDeUnaNacionalidad(ePelicula unaPelicula,eActor unActor)
{
    printf("\n%d%11s%20s\n",unaPelicula.id,unaPelicula.titulo,unActor.nombre);
}


void mostrarListaPeliculasConActoresDeNacionalidadElegida(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int opcion;

    getInt("Ingrese la nacionaliad de el actor principal :\
           \n1.EEUU\
           \n2.Argentina\
           \n3.Australia\
           \n4.Uruguay\n",&opcion,1,4);


    switch(opcion)
    {
    case 1:
        mostrarListaPeliculasConActoresEEUU(listaPeliculas,tam,listaActores,aTam);

        break;
    case 2:
        mostrarListaPeliculasConActoresArgentina(listaPeliculas,tam,listaActores,aTam);

        break;
    case 3:

        mostrarListaPeliculasConActoresAustalia(listaPeliculas,tam,listaActores,aTam);

        break;
    case 4:
        mostrarListaPeliculasConActoresUruguay(listaPeliculas,tam,listaActores,aTam);

        break;

    }




}

void mostrarListaPeliculasConActoresArgentina(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int flag=0;



    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado && (stricmp(listaActores[listaPeliculas[i].idActor-1].PaisDeOrigen,"argentina"))==0)
        {
            printf("id\tTitulo\t\tAcotor P.\n");
            flag=1;
            break;
        }
    }

    if(flag)
    {

        for(i=i; i<tam; i++)
        {
            if(listaPeliculas[i].cargado && (stricmp(listaActores[listaPeliculas[i].idActor-1].PaisDeOrigen,"argentina"))==0)
            {
                mostrarPeliculaConActoresDeUnaNacionalidad(listaPeliculas[i],listaActores[(listaPeliculas[i].idActor)-1]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado Peliculas con actores argentinos\n");
    }

}

void mostrarListaPeliculasConActoresAustalia(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int flag=0;



    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado && (stricmp(listaActores[listaPeliculas[i].idActor-1].PaisDeOrigen,"australia"))==0)
        {
            printf("id\tTitulo\t\tAcotor P.\n");
            flag=1;
            break;
        }
    }

    if(flag)
    {

        for(i=i; i<tam; i++)
        {
            if(listaPeliculas[i].cargado && (stricmp(listaActores[listaPeliculas[i].idActor-1].PaisDeOrigen,"australia"))==0)
            {
                mostrarPeliculaConActoresDeUnaNacionalidad(listaPeliculas[i],listaActores[(listaPeliculas[i].idActor)-1]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado Peliculas con actores austalianos\n");
    }
}

void mostrarListaPeliculasConActoresUruguay(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int flag=0;



    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado && (stricmp(listaActores[listaPeliculas[i].idActor-1].PaisDeOrigen,"uruguay"))==0)
        {
            printf("id\tTitulo\t\tAcotor P.\n");
            flag=1;
            break;
        }
    }

    if(flag)
    {

        for(i=i; i<tam; i++)
        {
            if(listaPeliculas[i].cargado && (stricmp(listaActores[listaPeliculas[i].idActor-1].PaisDeOrigen,"uruguay"))==0)
            {
                mostrarPeliculaConActoresDeUnaNacionalidad(listaPeliculas[i],listaActores[(listaPeliculas[i].idActor)-1]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado Peliculas con actores de uruguay\n");
    }
}

void mostrarListaPeliculasConGeneros(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{

    int i;
    int j;
    int flag=0;
    char generos[5][50]= {"accion","comedia","terror","Romantica","otro"};

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado)
        {
            printf("id\tTitulo\t\tGenero\n");
            flag=1;
            break;
        }
    }



    if(flag)
    {
        for(j=i; j<tam; j++)
        {
            if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==1)
            {
                printf("\t\t\tAccion\n");

                for(j=j; j<tam; j++)
                {
                    if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==1)
                    {
                        mostrarPeliculaSegunSuGeneros(listaPeliculas[j]);
                    }
                }
                break;
            }

        }


        for(j=i; j<tam; j++)
        {
            if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==2)
            {
                printf("\t\t\tComedia\n");

                for(j=j; j<tam; j++)
                {
                    if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==2)
                    {

                        mostrarPeliculaSegunSuGeneros(listaPeliculas[j]);
                    }
                }
                break;
            }
        }



        for(j=i; j<tam; j++)
        {
            if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==3)
            {
                printf("\t\t\tTerror\n");

                for(j=j; j<tam; j++)
                {
                    if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==3)
                    {

                        mostrarPeliculaSegunSuGeneros(listaPeliculas[j]);
                    }
                }
                break;
            }
        }

        for(j=i; j<tam; j++)
        {

            if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==4)
            {
                printf("\t\t\tRomantica\n");

                for(j=j; j<tam; j++)
                {
                    if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==4)
                    {

                        mostrarPeliculaSegunSuGeneros(listaPeliculas[j]);
                    }
                }
                break;
            }

        }


        for(j=i; j<tam; j++)
        {
            if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==5)
            {
                printf("\t\t\tOtro\n");

                for(j=j; j<tam; j++)
                {
                    if(listaPeliculas[j].cargado && listaPeliculas[j].idGenero==5)
                    {

                        mostrarPeliculaSegunSuGeneros(listaPeliculas[j]);
                    }
                }
                break;
            }
        }

    }
    else
    {
        printf("\nNo se han ingresado Peliculas\n");
    }

    system("pause");
    system("cls");


}

void mostrarPeliculaSegunSuGeneros(ePelicula unaPelicula)
{
    printf("\n%d%11s\n",unaPelicula.id,unaPelicula.titulo);
}



void mostrarCantidadDePeliculasPorGenero(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;
    char generos[5][50]= {"accion","comedia","terror","Romantica","otro"};

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado==1)
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
        }
    }

    printf("cantidad de Peliculas de accion : %d\
           \ncantidad de Peliculas de comedia : %d\
           \ncantidad de Peliculas de terror : %d\
           \ncantidad de Peliculas de romantica : %d\
           \ncantidad de Peliculas de otro : %d\n",contador1,contador2,contador3,contador4,contador5);




    system("pause");
    system("cls");


}


void mostrarActoresQueMasPeliculasProtagonizaron(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;
    int actorMax=-1;

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado==1)
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
        }
    }


    if(actorMax<contador1)
    {
        actorMax=contador1;
    }
    if(actorMax<contador2)
    {
        actorMax=contador2;
    }
    if(actorMax<contador3)
    {
        actorMax=contador3;
    }
    if(actorMax<contador4)
    {
        actorMax=contador4;
    }
    if(actorMax<contador5)
    {
        actorMax=contador5;
    }

    if(actorMax!=0)
    {
        printf("\nLos actores que trabajaron en mas peliculas son : ");

        if(contador1==actorMax)
        {
            printf("\nJulieta roberto");
        }
        if(contador2==actorMax)
        {
            printf("\nRichar darin");
        }
        if(contador3==actorMax)
        {
            printf("\nNicole Kidman");
        }
        if(contador4==actorMax)
        {
            printf("\nTita merello");
        }
        if(contador5==actorMax)
        {
            printf("\nNatalia Oreiro");
        }

        printf("\nTrabajaron en %d peliculas\n",actorMax);


    }

    system("pause");
    system("cls");

}


void mostrarActoresQueNoTrabajaron(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado==1)
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
        }
    }
    if(contador1==0 || contador2==0 || contador3==0 || contador4==0 || contador5==0)
    {
        printf("\nLos actores que no trabajaron en ninguna pelicula son : \n");

        if(contador1==0)
        {
            printf("Julieta roberto\n");
        }
        if(contador2==0)
        {
            printf("Richar darin\n");
        }
        if(contador3==0)
        {
            printf("Nicole Kidman\n");
        }
        if(contador4==0)
        {
            printf("Tita merello\n");
        }
        if(contador5==0)
        {
            printf("Natalia Oreiro\n");
        }
    }
    else
    {
        printf("\ntodos los actores trabajaron en alguna pelicula\n");
    }

    system("pause");
    system("cls");

}

void mostrarGeneroConMenosPeliculas(ePelicula listaPeliculas[],int tam,eActor listaActores[],int aTam)
{
    int i;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;
    int generoMin=-1;

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado==1)
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
        }
    }



    generoMin=contador1;

    if(generoMin>contador2)
    {
        generoMin=contador2;
    }
    if(generoMin>contador3)
    {
        generoMin=contador3;
    }
    if(generoMin>contador4)
    {
        generoMin=contador4;
    }
    if(generoMin>contador5)
    {
        generoMin=contador5;
    }

    printf("\nLos Generos con menos peliculas son : ");

    if(contador1==generoMin)
    {
        printf("\naccion");
    }
    if(contador2==generoMin)
    {
        printf("\ncomedia");
    }
    if(contador3==generoMin)
    {
        printf("\nterror");
    }
    if(contador4==generoMin)
    {
        printf("\nRomantica");
    }
    if(contador5==generoMin)
    {
        printf("\notro");
    }

    printf("\ncon %d peliculas\n",generoMin);

    system("pause");
    system("cls");

}
