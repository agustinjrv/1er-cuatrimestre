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

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* edad,char* empleo)
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
           sePudo=employee_setedad(retornarEmpleado,atoi(edad));
        }
        if(sePudo)
        {
           sePudo=employee_setEmpleo(retornarEmpleado,empleo);
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

    if(this!=NULL)
    {
        if(strlen(nombre)>0)
        {
            strcpy(this->nombre,nombre);
        }
        else
        {
            retorno=0;
        }
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

int employee_setedad(Employee* this,int edad)
{
    int retorno=1;

    if(edad>0)
    {
        this->edad=edad;
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

int employee_getedad(Employee* this,int* edad)
{
    int retorno=1;

    if(edad>0)
    {
        *edad=this->edad;
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
    int id;
    char nombre[128];
    char empleo[128]="lala";
    int horasTrabajadas;
    int edad;

    employee_getId(unEmpleado,&id);
    employee_getNombre(unEmpleado,nombre);
    employee_getEmpleo(unEmpleado,empleo);
    employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas);
    employee_getedad(unEmpleado,&edad);


    printf("%d%10s%15s%8d%20d\n\n", id, nombre,empleo,edad ,horasTrabajadas);
}

int ordenarPorNombre(void* empleado1,void* empleado2)
{

    int retornar;
    char nombre1[50]="lala";
    char nombre2[50]="lulu";

    Employee* unEmpleado=(Employee*)empleado1;
    Employee* otroEmpleado=(Employee*)empleado2;

    if(unEmpleado!=NULL && otroEmpleado!=NULL)
    {
        employee_getNombre(unEmpleado,nombre1);
        employee_getNombre(otroEmpleado,nombre2);
        retornar=stricmp(nombre1,nombre2);


    }

    return retornar;
}

int employee_setEmpleo(Employee* this,char* empleo)
{
    int retorno=1;

    if(this!=NULL)
    {
        if(strlen(empleo)>0)
        {
            strcpy(this->empleo,empleo);
        }
        else
        {
            retorno=0;
        }
    }

    return retorno;
}


int employee_getEmpleo(Employee* this,char* empleo)
{

    int retorno=1;

    if(strlen(empleo)>0)
    {
        strcpy(empleo,this->empleo);
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

int employee_setDedicacion(Employee* this,char* dedicacion)
{
    int retorno=1;

    if(this!=NULL)
    {
        if(strlen(dedicacion)>0)
        {
            strcpy(this->dedicacion,dedicacion);
        }
        else
        {
            retorno=0;
        }
    }

    return retorno;
}
int employee_getDedicacion(Employee* this,char* dedicacion)
{
    int retorno=1;

    if(strlen(dedicacion)>0)
    {
        strcpy(dedicacion,this->dedicacion);
    }
    else
    {
        retorno=0;
    }

    return retorno;
}


void mostrarEmpleadoConDedicacion(Employee* unEmpleado)
{
    int id;
    char nombre[128]="lele";
    char empleo[128]="lala";
    char dedicacion[128]="lulu";
    int horasTrabajadas;
    int edad;

    employee_getId(unEmpleado,&id);
    employee_getNombre(unEmpleado,nombre);
    employee_getEmpleo(unEmpleado,empleo);
    employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas);
    employee_getedad(unEmpleado,&edad);
    employee_getDedicacion(unEmpleado,dedicacion);


    printf("%d%10s%15s%8d%20d%10s\n\n", id, nombre,empleo,edad ,horasTrabajadas,dedicacion);
}

int ordenarPorDedicacion(void* empleado1,void* empleado2)
{

    int retornar;
    int horasTrabajadas1;

    Employee* unEmpleado=(Employee*)empleado1;
    Employee* otroEmpleado=(Employee*)empleado2;



    if(unEmpleado!=NULL && otroEmpleado!=NULL)
    {
        employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas1);

    }

    if(horasTrabajadas1>0 && horasTrabajadas1 <=200)
    {
        retornar=1;
    }
    else if(horasTrabajadas1<=300)
    {
        retornar=-1;
    }
    else
    {
        retornar=0;
    }

    return retornar;
}
