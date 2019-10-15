#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    char empleo[128];
    int horasTrabajadas;
    int edad;
    char dedicacion[128];
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* edad,char* empleo);

void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setedad(Employee* this,int edad);
int employee_getedad(Employee* this,int* edad);

int employee_setEmpleo(Employee* this,char* empleo);
int employee_getEmpleo(Employee* this,char* empleo);

int employee_setDedicacion(Employee* this,char* dedicacion);
int employee_getDedicacion(Employee* this,char* dedicacion);

void mostrarEmpleado(Employee* unEmpleado);
void mostrarEmpleadoConDedicacion(Employee* unEmpleado);

int ordenarPorNombre(void*,void*);
int ordenarPorId(void*,void*);
int ordenarPorHoras(void*,void*);
int ordenarPoredad(void*,void*);
int ordenarPorDedicacion(void*,void*);

int buscarIdMax(LinkedList* pArrayListEmployee);



#endif // employee_H_INCLUDED
