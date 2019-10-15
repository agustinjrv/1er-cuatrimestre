#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int PedirOpcion(int flag1,int flag2,int numero1,int numero2)
{
    int opcion;
    printf("Calculadora\n");

    if (flag1==0)
    {
        printf("1. Ingresar 1er operando (A=x)\n");
    }
    else
    {
        printf("1. Ingresar 1er operando (A=%d)\n",numero1);
    }

    if(flag2==0)
    {
        printf("2. Ingresar 2do operando (B=y)\n");
    }
    else
    {
        printf("2. Ingresar 2do operando (B=%d)\n",numero2);
    }
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir");
    printf("\nQue desea hacer?\n\n");
    scanf("%d",&opcion);

    return opcion;

}

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




