#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "biblioAgus.h"

int main()
{
    int option;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
            getInt("Menu:\
     \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
    2. Listar empleados\
  \n3. Cargar dedicacion\
    \n4. Listar empleados con Dedicacion\
    \n5.Listar empleados con edad menor a 21\
    \n6. Salir\n\n",&option,1,6);

        switch(option)
        {
            case 1:
                if(flag==0)
                {
                    controller_loadFromText("datos.csv",listaEmpleados);
                    flag=1;
                }
                else
                {
                    printf("Ya se ha cargado el archivo\n");
                }

                break;
            case 2:

                 if(ll_len(listaEmpleados))
                    {
                         controller_ListEmployee(listaEmpleados);
                    }
                    else
                    {
                        printf("No se han ingresado empleados\n");
                    }
                break;
            case 3:
                ll_map(listaEmpleados,laQueMapea);
            break;

            case 4:
                controller_ListEmployeeConDedicacion(listaEmpleados);
                break;
            case 5:
                break;
            case 6:
                break;

        }
        system("pause");
        system("cls");
    }while(option != 6);

    return 0;
}
