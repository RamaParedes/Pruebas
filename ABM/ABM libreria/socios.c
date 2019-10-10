#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "prestamos.h"
#include "input.h"
#include "fechas.h"
#include "libros.h"
#include "autores.h"
#include "socios.h"
#define T 3
#define OCUPADO 1
#define LIBRE 0
void inicializarSocios(eSocios lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        lista[i].estado = 0;
    }
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector\n");
    printf("6- Ordenar empleados por sector y dentro del sector por nombre\n");
    printf("7- Mostrar los datos de o los empleados que mas ganan por sector\n");
    printf("8- Mostrar almuerzos\n");
    printf("9- Mostrar almuerzos empleado\n");
    printf("10- Mostrar almuerzos x sector\n");
    printf("11- Salir\n");
    printf("\nIngrese opcion: ");
    setbuf(stdin,NULL);
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eSocios lista[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarSocioXAutorXLibro(eSocios socio[], int tamSocios, eAutor autores, int tamAutores, eLibro libros, int tamLibros)
{
    printf("  %d   %s   %s    %c    %d     %s     %d\n", socio.codigoDeSocio, socio.apellido, socio.nombre, socio.sexo, socio.telefono, socio.eMail, socio.eFecha.fechaDeAsociado);
    printf("  %d   %s   %s \n", autores.codigoDeAutor, autores.apellido, autores.nombre);
    printf("  %d   %s   %d \n", libros.codigoDeLibro, libros.titulo, libros.codigoDeAutor);

}

void mostrarSociosXAutoresXLibros(eSocios lista[], int tam)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            mostrarSocioXAutorXLibro(lista[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay socios que mostrar\n\n");
    }
}

int mayorCodigoDeSocios(eSocios lista[], int tam)
{
    int i;
    int flag = 0;
    int aux = 0;
    for(i=0; i < tam; i++)
    {
        if(flag==0 || lista[i].codigoDeSocio > aux)
        {
            aux = lista[i].codigoDeSocio;
            flag = 1;
        }
    }
    return aux;
}

void altaSocio(eSocios lista[], int tam)
{
    int i;
    i = buscarLibre(lista,tam);

    if(i != -1)
    {
        lista[i].codigoDeSocio = mayorCodigoDeSocios(lista, T) + 1;
        getChar("ingrese apellido")
        gets(lista[i].apellido);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese telefono: ");
        scanf("%d", &lista[i].telefono);
        printf("Ingrese eMail: ");
        fflush(stdin);
        gets(lista[i].eMail);
        printf("Ingrese fecha de asociado: ");
        scanf("%d", &lista[i].efecha.fechaDeAsociado);
        lista[i].estado = OCUPADO;
    }
    else
    {
        printf("no hay espacio");
    }
}

void bajaSocio(eSocios lista[], int tam, int codigoDeSocio)
{
    int i;
    int loEncontro = 0;
    printf("Ingrese codigo de socio a dar de baja: ");
    scanf("%d", &codigoDeSocio);

    for(i=0; i<tam; i++)
    {
        if(codigoDeSocio == lista[i].codigoDeSocio)
        {
            lista[i].estado = LIBRE;
            loEncontro = 1;
            break;
        }
    }
    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}

void modificarSocio(eSocios lista[], int tam)
{
    int i;
    int loEncontro = 0;
    int codigoDeSocio;
    printf("Ingrese codigo de socio a modificar: ");
    scanf("%d", &codigoDeSocio);

    for(i=0; i<tam; i++)
    {
        if(codigoDeSocio == lista[i].codigoDeSocio && lista[i].estado == OCUPADO)
        {
            do
            {
                switch(menuM())
                {
                case 1:
                    printf("Ingrese un nuevo apellido: ");
                    fflush(stdin);
                    gets(lista[i].apellido);
                    break;
                case 2:
                    printf("Ingrese un nuevo nombre: ");
                    fflush(stdin);
                    gets(lista[i].nombre);
                    break;
                case 3:
                    printf("Ingrese un nuevo sexo: ");
                    fflush(stdin);
                    scanf("%c", &lista[i].sexo);
                    break;
                case 4:
                    printf("Ingrese telefono: ");
                    scanf("%d", &lista[i].telefono);
                    break;
                case 5:
                    printf("Ingrese eMail: ");
                    fflush(stdin);
                    gets(lista[i].eMail);
                    break;
                case 6:
                    seguir = 'n';
                    break;
                }
            }
            while(seguir == 's');
            loEncontro = 1;
            break;
        }
    }
    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}
int menuM()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones de Modificar***\n\n");
    printf("1- modificar apellido\n");
    printf("2- modificar nombre\n");
    printf("3- modificar sexo\n");
    printf("4- modificar telefono\n");
    printf("5- modificar eMail\n");
    printf("6- Salir\n");
    printf("\nIngrese opcion: ");
    setbuf(stdin,NULL);
    scanf("%d", &opcion);

    return opcion;
}

void OrdenarSocios(eSocios lista[], int tam)
{
    eSocios auxLista;
    int i;
    int j;

    for(i = 0; i < tam-1; i++)
    {
        for(j = i+1; j < tam; j++)
        {
            if(strcmp(lista[i].apellido,lista[j].apellido) && strcmp(lista[i].nombre,lista[j].nombre) > 0)
            {
                auxLista = lista[i];
                lista[i] = lista[j];
                lista[j] = auxLista;
            }
        }
    }
}
