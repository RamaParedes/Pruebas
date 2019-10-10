
#include "libros.h"
#include "autores.h"
#include "fechas.h"

#ifndef PRESTAMOS_H_INCLUDE
#define PRESTAMOS_H_INCLUDE

typedef struct
{
    int codigoDePrestamo;
    int codigoDeLibro;
    int codigoDeSocio;
    eFecha fechaDePrestamo;
} ePrestamos;





#endif // PRESTAMOS_H_INCLUDE
