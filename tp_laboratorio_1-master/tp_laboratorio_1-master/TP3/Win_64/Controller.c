#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "biblioAgus.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* ARCHIVO;
    int tam;

    ARCHIVO=fopen(path,"r");

    if(ARCHIVO==NULL)
    {
        printf("no se a podido abrir el archivo");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("archivo abierto existosamente ");

        tam=parser_EmployeeFromText(ARCHIVO,pArrayListEmployee);

        printf("\n\nSe han cargado %d empleados\n",tam);

        fclose(ARCHIVO);

    }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* ARCHIVO;

    ARCHIVO=fopen(path,"rb");

    if(ARCHIVO==NULL)
    {
        printf("\nError al leer el archivo\n");
    }
    else
    {
        parser_EmployeeFromBinary(ARCHIVO,pArrayListEmployee);
    }

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* unEmpleado= employee_new();

    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    int idMax=buscarIdMax(pArrayListEmployee);
    int sePudo=1;
    idMax+=1;

    if(unEmpleado!=NULL)
    {
        printf("Empleado n:%d\n",(idMax));
        sePudo=employee_setId(unEmpleado,idMax);
        if(sePudo)
        {
            getString("Ingrese el nombre del nuevo empleado : ",nombre,1,50);
            sePudo=employee_setNombre(unEmpleado,nombre);
        }
        if(sePudo)
        {

            getInt("Ingrese las horas trabajadas del nuevo empleado : ",&horasTrabajadas,1,400000000);
            sePudo=employee_setHorasTrabajadas(unEmpleado,horasTrabajadas);
        }
        if(sePudo)
        {
            getInt("Ingrese el sueldo del nuevo empleado : ",&sueldo,1,40000000);
            sePudo=employee_setSueldo(unEmpleado,sueldo);
        }
        if(sePudo)
        {
             ll_add(pArrayListEmployee,unEmpleado);
        }
        else
        {
            printf("error al cargar el nuevo Empleado");
        }

    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int id;
    int i;
    int flag=0;
    int tam=ll_len(pArrayListEmployee);
    char* nombre=(char* ) malloc(sizeof(char)*50);
    int horasTrabajadas;
    int sueldo;
    Employee* unEmpleado = employee_new();

    getInt("Ingrese el id del empleado que desea modificar :",&id,1,tam);

    for(i=0; i<tam; i++)
    {
        unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

        if(unEmpleado->id==id)
        {
            unEmpleado=ll_pop(pArrayListEmployee,i);
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        system("cls");
        printf("Empleado encontrado exitosamente\n\n");

        do
        {
            printf("id-----nombre---horas trabajadas------sueldo\n");

            mostrarEmpleado(unEmpleado);

            getInt("1. Nombre\
                   \n2. Horas trabajadas\
                   \n3.Sueldo\
                   \n4.Salir\n\n",&opcion,1,4);

            switch(opcion)
            {
            case 1:
                getString("Ingrese el nombre del empleado : ",nombre,1,50);
                employee_setNombre(unEmpleado,nombre);
                break;
            case 2:
                getInt("Ingrese las horas trabajadas del nuevo empleado : ",&horasTrabajadas,1,400000000);
                employee_setHorasTrabajadas(unEmpleado,horasTrabajadas);
                break;
            case 3:
                getInt("Ingrese el sueldo del nuevo empleado : ",&sueldo,1,40000000);
                employee_setSueldo(unEmpleado,sueldo);
                break;
            }

            system("pause");
            system("cls");
        }
        while(opcion!=4);

        ll_push(pArrayListEmployee,i,unEmpleado);
    }
    else
    {
        printf("id de empleado inexistente\n");
    }

    return 1;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    char opcion[5]= {" "};
    int id;
    int i;
    int flag=0;
    int tam=ll_len(pArrayListEmployee);
    Employee* unEmpleado = employee_new();

    getInt("Ingrese el id del empleado que desea eliminar :",&id,1,tam);

    for(i=0; i<tam; i++)
    {
        unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

        if(unEmpleado->id==id)
        {
            unEmpleado=ll_get(pArrayListEmployee,i);
            flag=1;
            break;
        }
    }

    if(flag)
    {
        printf("\n\nid---nombre---horas trabajadas----sueldo\n");
        mostrarEmpleado(unEmpleado);

        while((stricmp(opcion,"si")) && (stricmp(opcion,"no")))
        {
            getString("\nDesea eliminar este empleado (ingrese si o no)?\n\n",opcion,2,2);
        }

        if(stricmp(opcion,"si")==0)
        {
            ll_remove(pArrayListEmployee,i);

            printf("\nEmpleado eliminado exitosamente\n");

        }
    }

    system("pause");
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len = ll_len(pArrayListEmployee);
    int i;



    printf("id---nombre---horas trabajadas----sueldo\n");
    for(i = 0; i < len; i++)
    {
        Employee* aux = (Employee*)ll_get(pArrayListEmployee, i);

        mostrarEmpleado(aux);
    }

    return 1;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
     int opcion;
     int orden;

     getInt("ordenar por :\
           \n1.ID\
            \n2.Nombre\
            \n3.Horas trabajadas\
            \n4.Sueldo\
            \n5.Salir\n",&opcion,1,5);

            switch(opcion)
            {
                 case 1:
                         getInt("Ordenar...\
                            \n1.Acendente\
                            \n0.Decendente\n\n",&orden,0,1);

                            printf("\nOrdenando...espere un momento por favor\n\n");

                            ll_sort(pArrayListEmployee,ordenarPorId,orden);

                            printf("Ordenamiento terminado\n");


                     break;

                 case 2:
                     getInt("Ordenar...\
                            \n1.Acendente\
                            \n0.Decendente\n\n",&orden,0,1);

                            printf("\nOrdenando...espere un momento por favor\n\n");

                           ll_sort(pArrayListEmployee,ordenarPorNombre,orden);

                           printf("Ordenamiento terminado\n");

                     break;

                 case 3:

                     getInt("Ordenar...\
                            \n1.Acendente\
                            \n0.Decendente\n\n",&orden,0,1);

                             printf("\nOrdenando...espere un momento por favor\n\n");

                           ll_sort(pArrayListEmployee,ordenarPorHoras,orden);

                           printf("Ordenamiento terminado\n");
                     break;

                 case 4:

                     getInt("Ordenar...\
                            \n1.Acendente\
                            \n0.Decendente\n\n",&orden,0,1);

                             printf("\nOrdenando...espere un momento por favor\n\n");

                           ll_sort(pArrayListEmployee,ordenarPorSueldo,orden);

                           printf("Ordenamiento terminado\n");
                     break;

            }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* ARCHIVO;
    int i;
    int tam;
    Employee* unEmpleado;
    ARCHIVO=fopen(path,"w");
    if(ARCHIVO==NULL)
    {
        printf("Error.no se a podido abrir el archivo");
        exit(EXIT_FAILURE);
    }
    else
    {
        tam=ll_len(pArrayListEmployee);


        fprintf(ARCHIVO,"id,nombre,horas trabajadas,sueldo\n");
        for(i=0; i<tam; i++)
        {
            unEmpleado=employee_new();
            unEmpleado=ll_get(pArrayListEmployee,i);

            fprintf(ARCHIVO,"%d,%s,%d,%d\n",unEmpleado->id,unEmpleado->nombre,unEmpleado->horasTrabajadas,unEmpleado->sueldo);
        }
        fclose(ARCHIVO);
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* ARCHIVO;
    Employee* unEmpleado;
    int i;
    int tam;



    ARCHIVO=fopen(path,"wb");

    if(ARCHIVO==NULL)
    {
        printf("no se a podido guardar el archivo");
        exit(EXIT_FAILURE);
    }
    else
    {
        tam=ll_len(pArrayListEmployee);

        for(i=0; i<tam; i++)
        {
            unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

            fwrite(unEmpleado,sizeof(Employee),1,ARCHIVO);
        }

        printf("Datos guardados en modo binario!!!\n");

        fclose(ARCHIVO);

    }

    return 1;
}



