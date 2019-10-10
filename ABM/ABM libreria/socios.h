

#include "libros.h"
#include "autores.h"
#include "fechas.h"

#ifndef SOCIOS_H_INCLUDE
#define SOCIOS_H_INCLUDE

typedef struct
{
    int codigoDeSocio;
    char apellido[31];
    char nombre[31];
    char sexo;
    int telefono[16];
    char eMail[31];
    int estado;
    eFecha fechaDeAsociado;
} eSocios;


#endif // SOCIOS_H_INCLUDE

void inicializarSocios(eSocios lista[], int tam);

int menu();

int buscarLibre(eSocios lista[], int tam);

void mostrarSocioXAutorXLibro(eSocios socio[], int tamSocios, eAutor autores, int tamAutores, eLibro libros, int tamLibros);

void mostrarSociosXAutoresXLibros(eSocios lista[], int tam);

int mayorCodigoDeSocios(eSocios lista[], int tam);

void altaSocio(eSocios lista[], int tam);

void bajaSocio(eSocios lista[], int tam);

void modificarSocio(eSocios lista[], int tam);

int menuM();

void OrdenarSocios(eSocios lista[], int tam);


