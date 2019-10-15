#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"

int Sumar(int numero1,int numero2)
{
    return (numero1+numero2);
}

int Restar(int numero1,int numero2)
{
    return (numero1-numero2);
}

int Multiplicar(int numero1,int numero2)
{
    return (numero1*numero2);
}

float Dividir(int numero1,int numero2)
{
    return (float)numero1/numero2;
}

int Factorizar(int numero)
{
    int acumulador=1;
    int i;
    for(i=1; i<=numero; i++)
    {
        acumulador=acumulador*i;
    }
    return acumulador;
}

void getString(char mensaje[],char input[],int tamMin,int tamMax)
{
    int i;
    int retorno=0;

    do
    {

        printf(mensaje);
        fflush(stdin);
        gets(input);

        if(strlen(input)>=tamMin && strlen(input)<=tamMax)
        {
            for(i=0;i<strlen(input);i++)
            {
                if((input[i]<'a' || input[i]>'z') && (input[i]<'A' || input[i]>'Z'))
                {
                    retorno=0;
                    break;
                }
                else
                {
                    retorno=1;
                }
            }

        }


        if(retorno==0)
        {
            printf("error\n");
        }

    }while(retorno==0);
}

void getInt(char mensaje[],int *numero,int tamMin,int tamMax)
{
    char ingreso[50];
    int retorno=0;
    int flag=1;
    int auxiliar=0;
    int i;

    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

            for(i=0;i<=strlen(ingreso);i++)
            {
                if(ingreso[i]=='.')
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


    }while(retorno==0);


}

void getFloat(char mensaje[],float *numero,float tamMin,float tamMax)
{
    char ingreso[50];
    int retorno=0;
    int flag=0;
    float auxiliar;
    int i;



    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

        for(i=0;i<=strlen(ingreso);i++)
        {
            if(ingreso[i]=='.')
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
        if(retorno==0)
        {
            printf("error\n");
        }


    }while(retorno==0);

}


void getLetrasYNumeros(char mensaje[],char input[],int tamMin,int tamMax)
{
    int i;
    int retorno=0;

    do
    {

        printf(mensaje);
        fflush(stdin);
        gets(input);

        if(strlen(input)>=tamMin && strlen(input)<=tamMax)
        {
            for(i=0;i<strlen(input);i++)
            {
                if((input[i]<'a' || input[i]>'z') && (input[i]<'A' || input[i]>'Z') && (input[i]<'0' || input[i]>'9'))
                {
                    retorno=0;
                    break;
                }
                else
                {
                    retorno=1;
                }
            }

        }


        if(retorno==0)
        {
            printf("error\n");
        }

    }while(retorno==0);
}

void  hardcodearPeliculas(ePelicula lista[])
{

    int i;
    char titulo[8][50]= {"terminator","thor","it","gladiador","scary movie","sexto sentido","scary movie 2","sexto sentido"};
    int anioDeEstreno[8]= {2020,2019,2018,2018,2012,1990,2015,1999};
    int codigo[8]={999,666,555,777,111,222,101,202};
    int idGenero[8]={1,1,3,3,2,3,2,2};
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

