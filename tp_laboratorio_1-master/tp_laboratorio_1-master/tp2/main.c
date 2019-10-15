#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    int opcion;
    eEmpleado listaEmpleados[TAM];

    inicializarEmpleados(listaEmpleados,TAM);

    do
    {
        getInt("1. Altas\n2. Modificar\n3. Bajas\n4. Informar\n5. Salir\nQue desea hacer?\n\n",&opcion,1,5);

        switch(opcion)
        {
        case 1:

            cargarEmpleado(listaEmpleados,TAM);

            break;

        case 2:

            modificarEmpleado(listaEmpleados,TAM);

            break;

        case 3:

            bajaEmpleado(listaEmpleados,TAM);

            break;

        case 4:

            informarSobreEmpledo(listaEmpleados,TAM);

            break;

        }

        system("pause");
        system("cls");

    }
    while(opcion!=5);


    return 0;
}
