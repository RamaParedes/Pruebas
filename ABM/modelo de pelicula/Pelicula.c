
#include "Pelicula.h"


void cargarPelicula(ePelicula lista[], int tam)
{
    int i;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf("Ingrese fechaDeEstreno: ");
        scanf("%d", &lista[i].fechaDeEstreno);
        printf("Ingrese el titulo: ");
        fflush(stdin);
        scanf("%c", &lista[i].titulo);
        printf("Ingrese actor: ");
        fflush(stdin);
        scanf("%c", &lista[i].actor);




        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }



}

void mostrarListaPeliculas(ePelicula lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarPelicula(lista[i]);
        }

    }
}
void mostrarPelicula(ePelicula unaPelicula)
{
    printf("%d-%c-%c\n", unaPelicula.fechaDeEstreno,unaPelicula.titulo, unaPelicula.actor);

}
int buscarLibre(ePelicula lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
void inicializarPeliculas(ePelicula lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodearDatosPelicula(ePelicula lista[], int tam)
{
    int i;
    int fechaDeEstrenos[]={};
    char titulos[][50]={};
    char actor[] [50]={};


    for(i=0; i<tam; i++)
    {
        lista[i].fechaDeEstreno = fechaDeEstrenos[i];
        strcpy(lista[i].titulo, titulos[i]);
        lista[i].actor = actor[i];
        lista[i].estado = OCUPADO;

    }




}



