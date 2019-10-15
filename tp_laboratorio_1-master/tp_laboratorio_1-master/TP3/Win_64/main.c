#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "biblioAgus.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

///geters seters,no se puede usar flechas por fuera de geters ,seters en parcial
///contructores...no usar malloc ni calloc ni realloc sin estar en funciones
///funciones del linkedList...desarrollar funciones para linkedList,derrollar herramientas de linked list antes
///entender para que sirve cada funcion de linkedList
///isEmpty dice si hay algo o no



int main()
{
    int option;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
            getInt("Menu:\
     \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
    2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\
  3. Alta de empleado.\
     \n4. Modificar datos de empleado.\
     \n5. Baja de empleado.\
     \n6. Listar empleados.\
     \n7. Ordenar empleados.\
     \n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\
     \n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\
    10. Salir\n\n",&option,1,10);

        switch(option)
        {
            case 1:
                if(flag==0)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    flag=1;
                }
                else
                {
                    printf("Ya se ha cargado el archivo\n");
                }

                break;
            case 2:

                if(flag==0)
                {
                       controller_loadFromBinary("data.bin",listaEmpleados);
                        flag=1;
                }
                else
                {
                    printf("Ya se a cargado el archivo\n");
                }
                break;
            case 3:
                if(flag)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar el archivo\n");
                }
                break;
            case 4:
                if(ll_len(listaEmpleados))
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("No se han ingresado empleados\n");
                }
                break;
            case 5:
                if(ll_len(listaEmpleados))
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("No se han ingresado empleados\n");
                }
                break;
            case 6:

                if(ll_len(listaEmpleados))
                {
                     controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("No se han ingresado empleados\n");
                }

                break;
            case 7:
                if(ll_len(listaEmpleados))
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("No se han ingresado empleados\n");
                }
                break;
            case 8:
                if(flag)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar el archivo\n");
                }

                break;
            case 9:
                if(flag)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar el archivo\n");
                }
                break;


        }
        system("pause");
        system("cls");
    }while(option != 10);

    return 0;
}
