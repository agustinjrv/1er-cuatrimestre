#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    int opcion;
    int aux;
    int numero1;
    int numero2;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    int factorialNum1;
    int factorialNum2;
    int flag1=0;
    int flag2=0;
    int flag3=0;

    do
    {

        opcion=PedirOpcion(flag1,flag2,numero1,numero2);

        switch(opcion)
        {
        case 1:
            printf("\nIngrese el 1er operando :");
            if(scanf("%d",&aux)==1)
            {
                numero1=aux;
                flag1=1;
            }
            else
            {
                printf("Error,ese numero no es valido\n");
            }
            break;
        case 2:
                printf("\nIngrese el 2do operando :");
                if(scanf("%d",&aux)==1)
                {
                    numero2=aux;
                    flag2=2;
                }
                else
                {
                    printf("Error,ese numero no es valido\n");
                }
            break;
        case 3:
            if(flag1 && flag2)
            {
                suma=Sumar(numero1,numero2);
                resta=Restar(numero1,numero2);
                multiplicacion=Multiplicar(numero1,numero2);
                if(numero2!=0)
                {
                    division=Dividir(numero1,numero2);
                }
                if(numero1==0)
                {
                    factorialNum1=1;
                }
                else
                {
                    factorialNum1=Factorizar(numero1);
                }
                if(numero2==0)
                {
                    factorialNum2=1;
                }
                else
                {
                    factorialNum2=Factorizar(numero2);
                }


                printf("\nLas operaciones ya se realizaron\n");
                flag3=1;
            }
            else
            {
                printf("\nError,primero ingrese ambos operando\n");
            }


            break;
        case 4:
            if(flag3)
            {
                printf("\nEl resultado de A+B es: %d",suma);
                printf("\nEl resultado de A-B es: %d",resta);
                printf("\nEl resultado de A*B es: %d",multiplicacion);
                if(numero2!=0)
                {
                    printf("\nEl resultado de A/B es: %f",division);
                }
                else
                {
                    printf("\nError no se puede dividir por 0");
                }
                printf("\nEl factorial de A es: %d y El factorial de B es: %d\n",factorialNum1,factorialNum2);

            }
            else
            {
                printf("\nError,primero calcule las operaciones\n");
            }
            break;
        case 5:
            opcion=5;
            break;
        default:
            printf("La opcion ingresada es incorrecta\n\n");
        }
        fflush(stdin);
        system("pause");
        system("cls");
    }while(opcion != 5);
}

