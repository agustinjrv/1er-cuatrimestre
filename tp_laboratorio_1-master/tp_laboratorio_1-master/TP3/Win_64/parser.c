#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    int contador=0;


    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    while(!feof(pFile))
    {
        Employee* unEmpleado=employee_new();

        if(unEmpleado!=NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

            unEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            if(unEmpleado!=NULL)
            {
                ll_add(pArrayListEmployee,(Employee*)unEmpleado);
                contador++;
            }

        }
        else
        {
            printf("no se a podido asignar memoria para el empleado n%d",contador);
            break;
        }

    }
    return contador;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* unEmpleado=employee_new();
    Employee auxEmpleado;

    int contador=0;

    if(unEmpleado!=NULL)
    {
        while(!feof(pFile))
        {
            unEmpleado=employee_new();
            fread(&auxEmpleado,sizeof(Employee),1,pFile);

            if(feof(pFile))
            {
                break;
            }

            employee_setId(unEmpleado,auxEmpleado.id);
            employee_setNombre(unEmpleado,auxEmpleado.nombre);
            employee_setHorasTrabajadas(unEmpleado,auxEmpleado.horasTrabajadas);
            employee_setSueldo(unEmpleado,auxEmpleado.sueldo);

            ll_add(pArrayListEmployee,unEmpleado);
            contador++;
        }

    printf("se cargaron %d empleados del archivo data.bin\n",contador);


    }

    return 1;
}
