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

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len = ll_len(pArrayListEmployee);
    int i;

    ll_sort(pArrayListEmployee,ordenarPorNombre,1);

    printf("id---nombre------empleo-------edad-----horas trabajadas\n");
    for(i = 0; i < len; i++)
    {
        Employee* aux = (Employee*)ll_get(pArrayListEmployee, i);

        mostrarEmpleado(aux);
    }

    return 1;
}

int controller_ListEmployeeConDedicacion(LinkedList* pArrayListEmployee)
{
     int len = ll_len(pArrayListEmployee);
    int i;
    char dedicacion[50]="lalal";

    printf("id---nombre------empleo-------edad-----horas trabajadas---dedicacion\n");
    for(i = 0; i < len; i++)
    {
        Employee* aux = (Employee*)ll_get(pArrayListEmployee, i);

        employee_getDedicacion(aux,dedicacion);

        if(stricmp(dedicacion,"estandar")==0)
        {
            mostrarEmpleadoConDedicacion(aux);
        }
    }

     for(i = 0; i < len; i++)
    {
        Employee* aux = (Employee*)ll_get(pArrayListEmployee, i);
        employee_getDedicacion(aux,dedicacion);
        if(stricmp(dedicacion,"sobre la media")==0)
        {
            mostrarEmpleadoConDedicacion(aux);
        }
    }

     for(i = 0; i < len; i++)
    {
        Employee* aux = (Employee*)ll_get(pArrayListEmployee, i);
        employee_getDedicacion(aux,dedicacion);
        if(stricmp(dedicacion,"excesivo")==0)
        {
            mostrarEmpleadoConDedicacion(aux);
        }
    }



    return 1;
}

