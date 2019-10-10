#include <stdio.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int fechaDeEstreno;
    char titulo[50];
    char actor[50];
    int estado;
} ePelicula;

void mostrarPelicula(ePelicula);
void cargarPelicula(ePelicula[], int);
void mostrarListaPeliculas(ePelicula[], int);

int buscarLibre(ePelicula[], int);
void inicializarPeliculas(ePelicula[], int);
void hardcodearDatosPelicula(ePelicula[], int);
