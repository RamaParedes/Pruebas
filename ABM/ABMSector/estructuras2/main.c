#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Employee.h"

#define TAM 100
#define TAMSEC 5
#define TAM_EMPLEADOS


int main()
{
    eEmpleado* employeeToLoad = (eEmpleado*) malloc( sizeof(eEmpleado) );
    eEmpleado* employee = (eEmpleado*) malloc( TAM_EMPLEADOS * sizeof(eEmpleado) ); // se busca espacio para 100

    if ( employee == NULL || employeeToLoad == NULL )
    {
        printf("ERROR: no se pudo conseguir espacio para trabajar con los datos\n\n");
        system("pause");
        system("cls");
    }

    if ( initEmployees(employee, TAM_EMPLEADOS) )
    {
        printf("ERROR: Ocurrio un error en la inicializacion...\n\n");
        system("pause");
        system("cls");
    }

    if ( initEstruct(employee, TAM_EMPLEADOS) )
    {
        printf("ERROR: Ocurrio un error en hardcodeo ...\n\n");
        system("pause");
    }


    int idIncremental;
    int cantidadDeEmpleados;

    int opcion = 0;

    int id; // ESTA VARIABLE LA USO PARA QUE EL USUARIO INGRESE EL LEGAJO DEL EMPLEADO A MODIFICAR/ELIMINAR
    int indice;

    findLastId(employee,TAM_EMPLEADOS, &idIncremental);

    do
    {
        system("cls");
        findLastId(employee,TAM_EMPLEADOS, &cantidadDeEmpleados);

        switch (menuPrincipal())
        {
            case 1:
                getString( employeeToLoad->name, "Ingrese su nombre: ", "Error, el nombre es demasiado corto o demasiado largo", 2, 51 );
                getString( employeeToLoad->lastName, "Ingrese su apellido: ", "Error, el apellido es demasiado corto o demasiado largo", 2, 51 );
                getFloat( &employeeToLoad->salary, "Ingrese el salario: ", "ERROR: salario fuera de rango...", 8000,80000);
                getInt( &employeeToLoad->sector, "Ingrese el sector: ", "ERROR: ese sector no existe...", 1,5);
                idIncremental++;

                if ( (addEmployee(employee, TAM_EMPLEADOS, idIncremental, employeeToLoad->name, employeeToLoad->lastName, employeeToLoad->salary, employeeToLoad->sector) ) >= 0 )
                {
                    printf("\n\nalta realizada correctamente\n\n");
                }
                else
                {
                    printf("\n\nERROR: no se encontro espacio para a�adir un nuevo empleado...\n\n");
                }
                system("pause");
                break;

            case 2:
                if ( cantidadDeEmpleados != 0)
                {
                    getInt( &id, "\nIngrese el id del empleado que desea modificar: ", "ERROR: ese empleado no existe...", 1,TAM_EMPLEADOS);
                    indice = findEmployeeById(employee,TAM_EMPLEADOS,id);
                    if (indice == -1)
                    {
                        printf("\nEste empleado no existe...\n\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        do {
                            system("cls");
                            switch(menuModificar(employee, &id, TAM_EMPLEADOS))
                            {
                                case 1:
                                    getString( (employee+indice)->name, "Ingrese su nombre: ", "Error, el nombre es demasiado corto o demasiado largo", 2, 51 );
                                    break;

                                case 2:
                                    getString( (employee+indice)->lastName, "Ingrese su apellido: ", "Error, el apellido es demasiado corto o demasiado largo", 2, 51 );
                                    break;

                                case 3:
                                    getFloat( &(employee+indice)->salary, "Ingrese el salario: ", "ERROR: salario fuera de rango...", 8000,80000);
                                    break;

                                case 4:
                                    getInt( &(employee+indice)->sector, "Ingrese el sector: ", "ERROR: ese sector no existe...", 1,5);
                                    break;

                                case 5:
                                    opcion = 2;
                                    break;

                                default:
                                    system("pause");
                                    break;
                            }
                        } while (opcion != 2);
                    }

                }
                else
                {
                    printf("\nno se encontraron empleados a modificar...\n\n");
                    system("pause");
                }

                break;

            case 3:
                if ( cantidadDeEmpleados != 0)
                {
                    getInt( &id, "\nIngrese el id del empleado que desea dar de baja: ", "ERROR: ese empleado no existe...", 1,TAM_EMPLEADOS);
                    removeEmployee(employee,TAM_EMPLEADOS,id);
                }
                else
                {
                   printf("\nno se encontraron empleados para dar de baja...\n\n");
                }

                system("pause");
                break;

            case 4:
                if ( cantidadDeEmpleados != 0 )
                {
                    do
                    {
                        system("cls");
                        switch(menuDeInformes())
                        {
                            case 1:
                                if ( sortEmployees(employee, TAM_EMPLEADOS, 0) )
                                {
                                    printf("\nERROR: no se pudieron ordenar los empleados...\n\n");
                                }

                                if ( printEmployees(employee, TAM_EMPLEADOS) )
                                {
                                    printf("ERROR: no se pudieron listar los empleados...\n\n");
                                }
                                system("pause");
                                break;

                            case 2:
                                informarTotalYProm(employee, TAM_EMPLEADOS);
                                system("pause");
                                break;

                            case 3:
                                opcion = 3;
                                break;

                            default:
                                printf("\nComando desconocido... ");
                                system("pause");
                                break;
                        }
                    } while (opcion != 3);
                }
                else
                {
                   printf("\nno se encontraron empleados para poder realizar informes...\n\n");
                   system("pause");
                }
                break;

            case 5:
                opcion = 1;
                printf("\nSaliendo... ");
                system("pause");
                break;

            default:
                printf("\nComando desconocido... ");
                system("pause");
                break;
        }
    } while (opcion != 1);

    return 0;
}
