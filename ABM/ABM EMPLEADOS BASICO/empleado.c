#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "empleado.h"
#include "input.h"
#include "sector.h"

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

/** \brief
 *
 * \return int
 *
 */
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
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return int
 *
 */
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

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param legajo int
 * \return int
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eEmpleado emp)
{

    printf("  %d   %s   %c    %.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);

}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {

            mostrarEmpleado(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void altaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            printf("Ingrese el dia fecha de nacimiento");
            scanf("%d", &vec[indice].fechaNac.dia);

            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(vec[esta]);
        }
    }
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void bajaEmpleado(eEmpleado vec[], int tam)
{

    int legajo;
    char confirma;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(vec[esta]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            vec[esta].ocupado = 0;
        }
        else{
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
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
            vec[esta].sueldo = nuevoSueldo;
        }
        else{
            printf("\nNo se ha modificado el sueldo\n");
        }
    }
}

void Ordenar(eEmpleado vec[], int tam)
{
    eEmpleado auxVec;
    int i;
    int j;

    for(i = 0;i < tam-1;i++)
    {
        for(j = i+1;j < tam;j++)
        {
            if(strcmp(vec[i].nombre,vec[j].nombre)>0)
            {
                auxVec = vec[i];
                vec[i] = vec[j];
                vec[j] = auxVec;
            }
        }
    }
}
