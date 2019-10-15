#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"



ePelicula getPelicula(int i)
{
    ePelicula retornarPelicula;

    retornarPelicula.id=1000+i;
    printf("id :%d.\n",retornarPelicula.id);
    getString("Ingrese el titulo de la Pelicula : ",retornarPelicula.titulo,1,50);
    getInt("Ingrese el codigo de la Pelicula : ",&retornarPelicula.codigo,100,999);
    retornarPelicula.cargado=1;

    return retornarPelicula;
}
int getGenero()
{
    int opcion;

    printf("Generos\n1.accion\n2.comedia\n3.terror\n4.otro\n");
    getInt("Que genero es?",&opcion,1,4);


    return opcion;
}

int getActor()
{
    int opcion;
    printf("Actores\n1.julieta roberto\n2.Roberto deniro\n3.Richar darin\n4.tita merelo\n5.sandro\n");
    getInt("Que actor es?",&opcion,1,5);

    return opcion;
}



void mostrarListaPeliculas(ePelicula listaPeliculas[],int tam,eActor actores[],eGenero generos[])
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(listaPeliculas[i].cargado)
        {
            printf("id\ttitulo\t\tcodigo\tFecha de estreno\tactores\tgenero\n");
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
                mostrarPelicula(listaPeliculas[i],actores[listaPeliculas[i].idActor],generos[listaPeliculas[i].idGenero]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado Peliculas\n");
    }


}

void mostrarPelicula (ePelicula unaPelicula,eActor unActor,eGenero unGenero)
{
    printf("\n%d%13s%18d%10s%10s\n",unaPelicula.id,unaPelicula.titulo,unaPelicula.codigo,unaPelicula.fechaDeEstreno,unActor.nombreApellido,unGenero.nombre);
}

void cargarPelicula(ePelicula listaPeliculas[],int tamP)
{
    int i=BuscarLugarLibre(listaPeliculas,tamP);

    if(i!=-1)
    {
        listaPeliculas[i]=getPelicula(i);
        listaPeliculas[i].idGenero=getGenero();
        listaPeliculas[i].idActor=getActor();

        printf("\nPelicula ingresada exitosamente!!!");
    }
    else
    {
        printf("\nmemoria llena\n");
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

/*void modificarPelicula(ePelicula lista[],int tam)
{
    int i;
    int opcion;
    fflush(stdin);
    getInt("Ingrese el numero de id del Pelicula a modificar :",&i,1,tam);
    i=i-1;

    if(lista[i].cargado)
    {
        system("cls");

        do
        {

            printf("\nid\tnombre\t\tapellido\tsalario\t\tsector\n");
            mostrarPelicula(lista[i]);

            getInt("\nQue desea modificar?\n\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n5. Para salir\n",&opcion,1,5);

            switch(opcion)
            {
            case 1:
                getString("Ingrese el titulo de la Pelicula : \n",lista[i].titulo,1,50);

                break;
            case 2:
                getString("Ingrese el apellido del Pelicula : \n",lista[i].apellido,1,50);

                break;
            case 3:
                getFloat("Ingrese el sueldo del Pelicula : ",&lista[i].salario,1,40000000000000);

                break;
            case 4:
                getInt("Ingrese el sector del Pelicula : ",&lista[i].sector,1,100);

                break;
            }

            if(opcion!=5)
            {
                system("pause");
                system("cls");
            }

        }
        while(opcion!=5);

    }
    else
    {
        printf("Error,id de Pelicula inexistente\n\n");
    }


}

void bajaPelicula(ePelicula lista[],int tam)
{
    int flag=0;
    int i;
    char opcion[2];


    getInt("Ingrese el numero de id del Pelicula a dar de baja :",&i,1,tam);
    i=i-1;

    system("pause");


    if(lista[i].cargado)
    {
        system("cls");
        printf("\nid\tnombre\t\tapellido\tsalario\t\tsector\n");
        mostrarPelicula(lista[i]);

        do
        {


            getString("\nDesea eliminar a este Pelicula?\n",opcion,1,1);

            opcion[0]=tolower(opcion[0]);


            if(strcmp(opcion,"s")==0)
            {
                lista[i].cargado=0;
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

void ordenarPeliculasPorApellido(ePelicula lista[],int tam)
{
    int i;
    int j;
    ePelicula auxiliar;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].sector>lista[j].sector)
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
            if(lista[i].sector==lista[j].sector)
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
}

void informarSalarios(ePelicula lista[],int tam)
{
    float promedio=0;
    float acumulador=0;
    int contador=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].cargado)
        {
            acumulador+=lista[i].salario;
        }
    }

    promedio=acumulador/(i-1);

    for(i=0; i<tam; i++)
    {
        if(lista[i].cargado)
        {
            if(lista[i].salario>promedio)
            {
                contador++;
            }
        }

    }
    printf("Suma total de los salarios :%.2f\nPromedio de los salarios :%.2f\nCantidad de Peliculas que superan el promedio :%d\n",acumulador,promedio,contador);

}*/

void informarSobrePelicula(ePelicula listaPeliculas[],int tam)
{
    int opcion;

    getInt("1.listar los datos de Películas sin actores\n2.listar los datos de Películas con actores\n3.Salir\nQue desea hacer?\n",&opcion,1,3);

    switch(opcion)
    {



    case 1:

        mostrarListaPeliculas(lista,tam);
        break;
    case 2:

        informarSalarios(lista,tam);

        break;
    case 3:
        break;
    }

}




void  inicializarPeliculas(ePelicula lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].titulo," ");
        lista[i].codigo=000;
        lista[i].idActor=-1;
        lista[i].idGenero=-1;
        lista[i].cargado=0;
    }

}


void getInt(char mensaje[],int *numero,int tamMin,int tamMax)
{
    char ingreso[50];
    int retorno=0;
    int flag;
    int auxiliar=0;
    int i;

    do
    {
        flag=1;
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

        for(i=0; i<strlen(ingreso); i++)
        {
            if(ingreso[i]=='.' || ingreso[i]<'0' || ingreso [i]>'9')
            {
                flag=0;
                break;
            }
        }

        auxiliar=atoi(ingreso);

        if(auxiliar>=tamMin && auxiliar<=tamMax && flag==1)
        {
            *numero=auxiliar;
            retorno=1;
        }

        if(retorno==0)
        {
            printf("error\n");
        }


    }
    while(retorno==0);


}

void getString(char mensaje[],char input[],int tamMin,int tamMax)
{
    int i;
    int retorno;

    do
    {
        retorno=1;
        printf(mensaje);
        fflush(stdin);
        gets(input);

        if(strlen(input)>=tamMin && strlen(input)<=tamMax)
        {
            for(i=0; i<strlen(input); i++)
            {
                if((input[i]<'a' || input[i]>'z') && (input[i]<'A' || input[i]>'Z'))
                {
                    retorno=0;
                    break;
                }
            }

        }

        if(retorno==0)
        {
            printf("error\n");
        }

    }
    while(retorno==0);
}

void getFloat(char mensaje[],float *numero,float tamMin,float tamMax)
{
    char ingreso[50];
    int retorno=0;
    int flag;
    float auxiliar;
    int i;

    do
    {
        flag=0;
        auxiliar=0;
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

        for(i=0; i<strlen(ingreso); i++)
        {
            if(ingreso[i]=='.' || ingreso[i]<'0' || ingreso [i]>'9')
            {
                flag++;

                if(flag==2)
                {
                    break;
                }
            }
        }

        auxiliar=atof(ingreso);

        if(auxiliar>=tamMin && auxiliar<=tamMax &&flag!=2)
        {
            *numero=auxiliar;
            retorno=1;

        }
        else if(retorno==0)
        {
            printf("error\n");
        }


    }
    while(retorno==0);

}


void  hardcodearGenero(eGenero lista[],int tam)
{
    int i;
    char nombre[4][50]= {"accion","comedia ","terror","otro"};

    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombre,nombre[i]);

    }

}


void  hardcodearActores(eActor lista[],int tam)
{
    int i;
    char nombre[5][50]= {"julieta roberto","Roberto deniro","Richar darin","tita merelo","sandro"};
    char pais[5][50]={"EEUU","EEUU","Argentina","Argentina","Argentina"};

    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombreApellido,nombre[i]);
        strcpy(lista[i].PaisDeOrigen,pais[i]);
    }

}





