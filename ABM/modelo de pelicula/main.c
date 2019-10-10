
#include <stdlib.h>
#include <string.h>
#include "Pelicula.h"

#define T 20


int menuDeOpciones(char[]);


int main()
{

    int indice;
    int opcion;

    ePelicula lista[T];
    inicializarPeliculas(lista,T);
}

void hardcodearDatosPelicula(lista,4);
{
    do
    {
        opcion = menuDeOpciones("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Salir\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargarPelicula(lista,  T);

            break;
            case 4:
                mostrarListaPeliculas(lista, T);
                break;

        }
    }while(opcion!=5);



    //inicializarPeliculas(lista, T);




    return 0;
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
