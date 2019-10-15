#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Employee.h"
#include "biblioAgus.h"



Employee* employee_new()
{
    Employee* retornarEmploye;

    retornarEmploye=(Employee*) calloc(sizeof(Employee),1);

    return retornarEmploye;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* retornarEmpleado=employee_new();
    int sePudo=1;
    if(retornarEmpleado!=NULL)
    {
        if(sePudo)
        {
            sePudo=employee_setId(retornarEmpleado,atoi(idStr));
        }
        if(sePudo)
        {
            sePudo=employee_setNombre(retornarEmpleado,nombreStr);
        }
        if(sePudo)
        {
            sePudo=employee_setHorasTrabajadas(retornarEmpleado,atoi(horasTrabajadasStr));
        }
        if(sePudo)
        {
           sePudo=employee_setSueldo(retornarEmpleado,atoi(sueldo));
        }
        if(!sePudo)
        {
            retornarEmpleado=NULL;
        }

    }
        return retornarEmpleado;



}

int employee_setId(Employee* this,int id)
{
    int retorno=1;

    if(id>0)
    {
        this->id=id;
    }
    else
    {
        retorno=0;
    }
    return retorno;



}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=1;

    if(strlen(nombre)>0)
    {
        strcpy(this->nombre,nombre);
    }
    else
    {
        retorno=0;
    }

    return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=1;

    if(horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
    }
    else
    {
        retorno=0;
    }
    return retorno;

}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=1;

    if(sueldo>0)
    {
        this->sueldo=sueldo;
    }
    else
    {
        retorno=0;
    }
    return retorno;

}

int employee_getNombre(Employee* this,char* nombre)
{

    int retorno=1;

    if(strlen(nombre)>0)
    {
        strcpy(nombre,this->nombre);
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int retorno=1;

    if(horasTrabajadas>0)
    {
        *horasTrabajadas=this->horasTrabajadas;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=1;

    if(sueldo>0)
    {
        *sueldo=this->sueldo;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=1;

    if(id>0)
    {
        *id=this->id;
    }
    else
    {
        retorno=0;
    }
    return retorno;

}

void mostrarEmpleado(Employee* unEmpleado)
{
    printf("%d%10s%8d%20d\n\n", unEmpleado->id, unEmpleado->nombre, unEmpleado->horasTrabajadas, unEmpleado->sueldo);
}

int ordenarPorNombre(void* empleado1,void* empleado2)
{

    int retornar;
    char* nombre1=(char*)malloc(sizeof(char)*50);
    char* nombre2=(char*)malloc(sizeof(char)*50);

    Employee* unEmpleado=(Employee*)empleado1;
    Employee* otroEmpleado=(Employee*)empleado2;

    if(unEmpleado!=NULL && otroEmpleado!=NULL)
    {
        employee_getNombre(unEmpleado,nombre1);
        employee_getNombre(otroEmpleado,nombre2);
        retornar=stricmp(nombre1,nombre2);


    }


    free(nombre1);
    free(nombre2);

    return retornar;
}

int buscarIdMax(LinkedList* pArrayListEmployee)
{
    int i;
    int tam=ll_len(pArrayListEmployee);
    int idMax=0;
    Employee* auxEmpleado;

    for(i=0;i<tam;i++)
    {
        auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

        if(auxEmpleado->id>idMax)
        {
            idMax=auxEmpleado->id;
        }
    }

    return idMax;
}

int ordenarPorId(void* empleado1,void* empleado2)
{
    int retornar;
    int id1=0;
    int id2=0;

    Employee* unEmpleado=(Employee*)empleado1;
    Employee* otroEmpleado=(Employee*)empleado2;

    if(unEmpleado!=NULL && otroEmpleado!=NULL)
    {
        employee_getId(unEmpleado,&id1);
        employee_getId(otroEmpleado,&id2);


       if(id1>id2)
       {
           retornar=1;
       }
       else if(id1<id2)
       {
           retornar=-1;
       }
       else
       {
           retornar=0;
       }

    }

    return retornar;
}

int ordenarPorHoras(void* empleado1,void* empleado2)
{
    int retornar;
    int horas1=0;
    int horas2=0;

    Employee* unEmpleado=(Employee*)empleado1;
    Employee* otroEmpleado=(Employee*)empleado2;

    if(unEmpleado!=NULL && otroEmpleado!=NULL)
    {
        employee_getHorasTrabajadas(unEmpleado,&horas1);
        employee_getHorasTrabajadas(otroEmpleado,&horas2);


       if(horas1>horas2)
       {
           retornar=1;
       }
       else if(horas1<horas2)
       {
           retornar=-1;
       }
       else
       {
           retornar=0;
       }

    }

    return retornar;
}

int ordenarPorSueldo(void* empleado1,void* empleado2)
{
    int retornar;
    int sueldo1=0;
    int sueldo2=0;

    Employee* unEmpleado=(Employee*)empleado1;
    Employee* otroEmpleado=(Employee*)empleado2;

    if(unEmpleado!=NULL && otroEmpleado!=NULL)
    {
        employee_getSueldo(unEmpleado,&sueldo1);
        employee_getSueldo(otroEmpleado,&sueldo2);


       if(sueldo1>sueldo2)
       {
           retornar=1;
       }
       else if(sueldo1<sueldo2)
       {
           retornar=-1;
       }
       else
       {
           retornar=0;
       }

    }

    return retornar;
}

