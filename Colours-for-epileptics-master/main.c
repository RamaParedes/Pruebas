#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // FUNCION "SLEEP"

/*

 * TEST DE EPILEPSIA DEV-BUILD (VERSION 1.0.2)
 * ADVERTENCIA: NO EJECUTAR SI USTED, U OTRO INDIVIDUO PRESENTE SUFRE DE PROBLEMAS EPILEPTICOS
 * DISCLAIMER: EL SIGUIENTE PROGRAMA ES UNA MODIFICACION DEL MISMO CREADO POR BRENDA FRIAS

 --- NOVEDADES ---

 * AHORA SOPORTA VARIABLES CON MEMORIA DINAMICA!

 --- PROXIMAMENTE ---

 * SOPORTE DE ARCHIVOS
 * FUNCION PARA CAMBIAR EL COLOR DEL ENTORNO EN OTROS PROJECTOS

*/


void cambioDeColores(int numeroColor);
int valptr (void* pointer);

int main()
{
    int* velocidad = (int*) malloc( sizeof(int) );

    if ( valptr(velocidad) == -1 )
    {
        printf("oops! algo salio mal... \n\n");
        printf("error 0001: fallo al intentar buscar memoria libre\n\n");
        system("pause");
        exit(1);
    }

    printf("bienvenido al test de epilepsia...\n\n");
    printf("que tan rapido queres que vayan los colores? (milisegundos): ");
    scanf("%d", velocidad);
    system("cls");
    printf("ESTAS LISTO PARA IR DIRECTO AL HOSPITAL?!\n\n");
    system("color 06");
    system("pause");
    system("cls");

    for(int i=1;i<=5;i++)
    {
        printf("VAMOS PARA ALLA!!!\n\n");
        cambioDeColores(i);
        Sleep(*velocidad);
        if( i == 5)
        {
            i=1;
        }

    }

    return 0;
}

void cambioDeColores(int numeroColor)
{
    if (numeroColor==1)
    {
        system("color 1f");
    }
    else if (numeroColor==2)
    {
        system("color 20");
    }
    else if (numeroColor==3)
    {
        system("color 4f");
    }
    else if (numeroColor==4)
    {
        system("color 5f");
    }
    else if(numeroColor==5)
    {
        system("color 60");
    }

}

int valptr (void* pointer)
{
    int todoOK = 0;

    if (pointer == NULL)
    {
        todoOK = -1;
    }

    return todoOK;
}
