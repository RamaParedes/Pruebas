#ifndef SECTOR_H_INCLUDE
#define SECTOR_H_INCLUDE

typedef struct
{
    int id;
    char descripcion[20];

} eSector;

int obtenerSector(eSector sectores[], int tam, int id, char desc[]);

void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);


#endif // SECTOR_H_INCLUDED

