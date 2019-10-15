#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Peliculas.h"

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



/*
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
}*/
/*
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

}*/





