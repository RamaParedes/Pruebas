#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM_SOCIOS 3
#define TAM_PRESTAMOS 3
#include "socios.h"
#include "prestamos.h"
#include "input.h"
#include "fechas.h"
#include "libros.h"
#include "autores.h"

int main()
{
    eAutor autores[] =
    {
        {0000, {"AAAA"}, {"aaaa"}},
        {1111, "BBBB", "bbbb"},
        {2222, "CCCC", "cccc"},
        {3333, "DDDD", "dddd"},
        {4444, "EEEE", "eeee"},
        {5555, "FFFF", "ffff"},
        {6666, "GGGG", "gggg"},
        {7777, "HHHH", "hhhh"},
        {8888, "IIII", "iiii"},
        {9999, "JJJJ", "jjjj"}
    };

    eLibro libros[] =
    {
        {0000, "AAA", 0000},
        {1111, "BBB", 1111},
        {2222, "CCC", 2222},
        {3333, "DDD", 3333},
        {4444, "EEE", 4444},
        {5555, "FFF", 5555},
        {6666, "GGG", 6666},
        {7777, "HHH", 7777},
        {8888, "III", 8888},
        {9999, "JJJ", 9999}
    };

    char seguir = 's';
    eSocios lista[TAM_SOCIOS];
    inicializarSocios(lista, TAM_SOCIOS);
    do
    {
        switch(menu())
        {

        case 1:
            altaSocio(lista,TAM_SOCIOS);
            system("pause");
            break;
        case 2:
            modificarSocio(lista,TAM_SOCIOS);
            system("pause");

            break;
        case 3:
            bajaSocio(lista,TAM_SOCIOS);
            system("pause");
            break;
        case 4:
            OrdenarSocios(lista,TAM_SOCIOS);
            mostrarSociosXAutoresXLibros(lista,TAM_SOCIOS);
            system("pause");
            break;
        case 5:
            ///
            system("pause");
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
