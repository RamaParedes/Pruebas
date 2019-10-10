#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Listar Sectores con Empleados\n");
    printf("7- Cantidad de empleados por sector\n");
    printf("8- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{

    char nombreSector;
    //int consigioNombre;

    obtenerSector(sectores, tam, emp.idSector, nombreSector);

    /*if( !consigioNombre){
         strcpy(nombreSector, "Sin definir");
     }*/
    printf("   %d       %10s     %c    %.2f  %s\n", emp.id, emp.name, emp.sexo, emp.salary, nombreSector);

}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int contador = 0;

    printf(" Legajo      Nombre        Sexo    Sueldo    Sector\n\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int id)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{

    int indice;
    int legajo;
    int esta;
    char nombre;
    int buscarEmpleado;


    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, id);

        if( esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", id);
            mostrarEmpleado(sectores, tamSector, vec[esta]);
        }
        else
        {
            vec[indice].id = id;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            printf("Ingrese sector: ");
            scanf("%f",&vec[indice].idSector);

            vec[indice].ocupado = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }
    }

}

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{

    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {

        if(idSector == sectores[i].id)
        {

            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{

    system("cls");
    for(int i=0; i < tamSec; i++)
    {
        printf("Sector: %s\n\n", sectores[i].descripcion);
        for(int j=0; j < tam; j++)
        {
            if( (empleados[j].idSector == sectores[i].id) && (empleados[j].ocupado == 1))
            {
                mostrarEmpleado(sectores, tamSec, empleados[j]);
            }
        }

        printf("\n\n");
    }




}

int menuModificar (eEmpleado* employee, int *id, int tam)
{
    int indice = findEmployeeById(employee,tam,*id);;

    int opcion;
    printf("--------------NOMINA DE EMPLEADOS--------------// MODIFICAR\n");
    printf("Empleado a modificar... Legajo: %04d | %s %s | salario: %.f | sector: %d \n\n", *id, (employee+indice)->name, (employee+indice)->lastName, (employee+indice)->salary, (employee+indice)->sector);
    printf("1) Modificar nombre\n");
    printf("2) Modificar apellido\n");
    printf("3) Modificar salario\n");
    printf("4) Modificar sector\n");
    printf("5) Salir\n\n");

    printf("Que desea hacer?: ");
    scanf("%d", &opcion );

    return opcion;

}
int menuDeInformes ()
{
        int opcion;
    printf("--------------NOMINA DE EMPLEADOS-------------- // INFORMES\n");
    printf("1) Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio. \n");
    printf("3) Salir\n\n");

    printf("Que desea hacer?: ");
    scanf("%d", &opcion );

    return opcion;
}
int initEstruct(eEmpleado* employee, int tam)
{
    int error = -1;

    if ( employee != NULL )
    {
        eEmpleado employeeToLoad[] = {
        {1,"Jonny", "Pozo", 90000, 3, 0},
        {2,"Camila", "Gomez", 45000, 3, 0},
        {3,"Nina", "Nolan", 30000, 1, 0},
        {4,"Pablo", "Ruiz", 15000, 2, 0},
        {5,"Indra", "Netsoff", 6000, 2, 0},
        {2,"Camila", "Gomez", 75500, 2, 0},
        {6,"Gonzalo", "Lopez", 25000, 1, 0},
        {4,"Pablo", "Ruiz", 45000, 1, 0},
        {7,"Minerva","Hass",65000,2,0},
        {8,"John","Marston",25000,2,0}
        };

        for (int i = 0; i < 8; i++)
        {
            *(employee+i) = employeeToLoad[i];
        }
        error = 0;
    }

    return error;
}
void ModificacionEmpleado(eEmpleado vec[], int tam)
{

    int legajo;
    char confirma;
    float nuevoSueldo;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(vec[esta]);

        printf("\nQuiere cambiar el sueldo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            //valido sueldo
            vec[esta].salary = nuevoSueldo;
        }
        else{
            printf("\nNo se ha modificado el sueldo\n");
        }
    }
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{

    int contador;
    system("cls");

    for(int i=0; i< tamSec; i++ )
    {
        contador = 0;
        printf("Sector: %s\n\n", sectores[i].descripcion);

        for(int j=0; j < tam; j++)
        {
            if(sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1)
            {
                contador++;
            }
        }

        printf("Cantidad: %d\n\n", contador);
    }
}

