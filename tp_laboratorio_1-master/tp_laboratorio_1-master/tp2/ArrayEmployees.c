#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"



eEmpleado getEmpleado(int i)
{
    eEmpleado retornarEmpleado;

    retornarEmpleado.id=i+1;
    printf("id :%d.\n",retornarEmpleado.id);
    getString("Ingrese el nombre del empleado : ",retornarEmpleado.nombre,1,50);
    getString("Ingrese el apellido del empleado : ",retornarEmpleado.apellido,1,50);
    getFloat("Ingrese el sueldo del empleado : ",&retornarEmpleado.salario,1,40000000000000);
    getInt("Ingrese el sector del empleado : ",&retornarEmpleado.sector,1,100);
    retornarEmpleado.cargado=1;

    return retornarEmpleado;
}

void mostrarListaEmpleados(eEmpleado lista[],int tam)
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].cargado)
        {
            printf("id\tnombre\t\tapellido\tsalario\t\tsector\n");
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
                mostrarEmpleado(lista[i]);
            }
        }
    }
    else
    {
        printf("\nNo se han ingresado empleados\n");
    }


}

void cargarEmpleado(eEmpleado lista[],int tam)
{
    int i=BuscarLugarLibre(lista,tam);

    if(i!=-1)
    {
        lista[i]=getEmpleado(i);
        printf("\nEmpleado ingresado exitosamente!!!\n");
    }
    else
    {
        printf("\nmemoria llena\n");
    }

}

void mostrarEmpleado (eEmpleado unEmpleado)
{
    printf("\n%d%13s%18s%15.2f%15d\n",unEmpleado.id,unEmpleado.nombre,unEmpleado.apellido,unEmpleado.salario,unEmpleado.sector);
}

int BuscarLugarLibre(eEmpleado lista[],int tam)
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

void modificarEmpleado(eEmpleado lista[],int tam)
{
    int i;
    int opcion;
    fflush(stdin);
    getInt("Ingrese el numero de id del empleado a modificar :",&i,1,tam);
    i=i-1;

    if(lista[i].cargado)
    {
        system("cls");

        do
        {

            printf("\nid\tnombre\t\tapellido\tsalario\t\tsector\n");
            mostrarEmpleado(lista[i]);

            getInt("\nQue desea modificar?\n\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n5. Para salir\n",&opcion,1,5);

            switch(opcion)
            {
            case 1:
                getString("Ingrese el nombre del empleado : \n",lista[i].nombre,1,50);

                break;
            case 2:
                getString("Ingrese el apellido del empleado : \n",lista[i].apellido,1,50);

                break;
            case 3:
                getFloat("Ingrese el sueldo del empleado : ",&lista[i].salario,1,40000000000000);

                break;
            case 4:
                getInt("Ingrese el sector del empleado : ",&lista[i].sector,1,100);

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
        printf("Error,id de empleado inexistente\n\n");
    }


}

void bajaEmpleado(eEmpleado lista[],int tam)
{
    int flag=0;
    int i;
    char opcion[2];


    getInt("Ingrese el numero de id del empleado a dar de baja :",&i,1,tam);
    i=i-1;

    system("pause");


    if(lista[i].cargado)
    {
        system("cls");
        printf("\nid\tnombre\t\tapellido\tsalario\t\tsector\n");
        mostrarEmpleado(lista[i]);

        do
        {


            getString("\nDesea eliminar a este empleado?\n",opcion,1,1);

            opcion[0]=tolower(opcion[0]);


            if(strcmp(opcion,"s")==0)
            {
                lista[i].cargado=0;
                printf("\nSe a eliminado el empleado\n");
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
        printf("\nid de empleado inexistente\n");
    }

}

void ordenarEmpleadosPorApellido(eEmpleado lista[],int tam)
{
    int i;
    int j;
    eEmpleado auxiliar;

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

void informarSalarios(eEmpleado lista[],int tam)
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
    printf("Suma total de los salarios :%.2f\nPromedio de los salarios :%.2f\nCantidad de empleados que superan el promedio :%d\n",acumulador,promedio,contador);

}

void informarSobreEmpledo(eEmpleado lista[],int tam)
{
    int opcion;

    getInt("1.Mostrar informacion de empleados\n2.Mostrar informacion de salarios\n3.Salir\nQue desea hacer?\n",&opcion,1,3);

    switch(opcion)
    {



    case 1:

        ordenarEmpleadosPorApellido(lista,tam);
        mostrarListaEmpleados(lista,tam);
        break;
    case 2:

        informarSalarios(lista,tam);

        break;
    case 3:
        break;
    }

}


void  inicializarEmpleados(eEmpleado lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].id=i+1;
        strcpy(lista[i].nombre," ");
        strcpy(lista[i].apellido," ");
        lista[i].salario=0;
        lista[i].sector=0;
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




