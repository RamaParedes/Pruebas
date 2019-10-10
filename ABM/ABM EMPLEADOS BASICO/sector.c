#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "empleado.h"
#include "input.h"
#include "sector.h"

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

