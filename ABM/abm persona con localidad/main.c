#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAM_PERSONAS 3
#define TAM_LOCALIDAD 3

typedef struct
{
    int id;
    char descripcion[50];
} eLocalidad;

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int edad;
    int estado;
    int idLocalidad;
} ePersonas;

int cargarLocalidades(int cantidadRegistros,eLocalidad listado[]);
void mostrarLocalidad(eLocalidad localidad);
void mostrarListadoLocalidades(int cantidaRegistros, eLocalidad listado[]);
eLocalidad construirLocalidad();
void inicializarPersonas(int cantidadRegistros, ePersonas listado[]);
int cargarPersona(int cantidadRegistros, ePersonas listado[]);
int borrarPersona(int cantidadRegistros, ePersonas listado[], ePersonas persona);
int buscarLugar(int cambiarRegistro, ePersonas listado[]);
int buscarPersona(int cantidadRegistros, ePersonas listado[], ePersonas persona);
void mostrarPersona(ePersonas persona);
void mostrarPersonas(int cantidadRegistros, ePersonas persona[]);
ePersonas construirPersonas();

int main()
{
    eLocalidad localidades[TAM_LOCALIDAD];

    cargarLocalidades(TAM_LOCALIDAD, localidades);

    mostrarListadoLocalidades(TAM_LOCALIDAD, localidades);

    ePersonas personas[TAM_PERSONAS];

    inicializarPersonas(TAM_PERSONAS, personas);

    cargarPersona(TAM_PERSONAS, personas);

    mostrarPersonas(TAM_PERSONAS, personas);

    borrarPersona(TAM_PERSONAS, personas, personas[0]);

    return 0;
}

int cargarLocalidades(int cantidadRegistros, eLocalidad listado[])
{
    int i;
    for(i = 0; i < cantidadRegistros; i++)
    {
        listado[i] = construirLocalidad();
    }
    return 1;
}

void mostrarLocalidad(eLocalidad localidad)
{
    printf("\n Codigo: \t %d \n", localidad.id);
    printf("\n Nombre: \t %s \n", localidad.descripcion);
    printf("------------------------------");
}

void mostrarListadoLocalidades(int cantidaRegistros, eLocalidad listado[])
{
    int i;
    for(i = 0; i < cantidaRegistros; i++)
    {
        mostrarLocalidad(listado[i]);
    }
}

eLocalidad construirLocalidad()
{
    eLocalidad retornarLocalidad;
    printf("ingrese el id: ");
    scanf("%d", &retornarLocalidad.id);

    printf("ingrese la descripcion: ");
    setbuf(stdin,NULL);
    gets(retornarLocalidad.descripcion);

    return retornarLocalidad;
}

void inicializarPersonas(int cantidadRegistros, ePersonas listado[])
{
    for(int i=0; i < cantidadRegistros; i++)
    {
        listado[i].estado = 0;
    }
}

int cargarPersona(int cantidadRegistros, ePersonas listado[])
{
    int localidadIngresada;
    int indice;
    indice = buscarLugar(cantidadRegistros, listado);
    if(indice != -1)
    {
        printf("ingrese localidad: ");
        scanf("%d", &localidadIngresada);
        listado[indice] = construirPersonas(localidadIngresada);
    }
    return indice;
}

int borrarPersona(int cantidadRegistros, ePersonas listado[], ePersonas persona)
{
   int indice;
   indice = buscarPersona(cantidadRegistros, listado, persona);

   if(indice != -1)
   {
       listado[indice].estado = 1;
   }
   return indice;
}

int buscarLugar(int cambiarRegistro, ePersonas listado[])
{
    int indice = -1;

    for(int i=0; i < cambiarRegistro; i++)
    {
        if(listado[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarPersona(int cantidadRegistros, ePersonas listado[], ePersonas persona)
{
    int i;

    for(i=0; i < cantidadRegistros; i++)
    {
        if(listado[i].id == persona.id)
        {
            return i;
        }
    }
    return -1;
}

void mostrarPersona(ePersonas persona)
{

    printf("\n ingrese la id: \t %d \n", persona.id);
    printf("\n ingrese el nombre: \t %s \n",  persona.nombre);
    printf("\n ingrese el apellido: \t %s \n",  persona.apellido);
    printf("\n ingrese la edad: \t %d \n",  persona.edad);

}

void mostrarPersonas(int cantidadRegistros, ePersonas persona[])
{
    int cont= 0;

    for(int i=0; i < cantidadRegistros; i++)
    {
        if(persona[i].estado == 1)
        {

            mostrarPersona(persona[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}
ePersonas construirPersonas(int idLocalidad)
{
    ePersonas retornarPersonas;

    printf("ingrese el id: ");
    scanf("%d", &retornarPersonas.id);

    printf("ingrese el nombre: ");
    setbuf(stdin,NULL);
    gets(retornarPersonas.nombre);

    printf("ingrese el apellido: ");
    setbuf(stdin,NULL);
    gets(retornarPersonas.apellido);

    printf("ingrese la edad: ");
    scanf("%d", &retornarPersonas.edad);

    retornarPersonas.idLocalidad = idLocalidad;

    return retornarPersonas;
}
