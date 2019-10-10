typedef struct
{

    int id;
    char name[50];
    char lastName[50];
    char sexo;
    float salary;
    int idSector;
    int ocupado;

} eEmpleado;

typedef struct
{

    int id;
    char descripcion[20];

} eSector;

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void ModificacionEmpleado(eEmpleado vec[], int tam);
int menuModificar (eEmpleado* employee, int *id, int tam);
int menuDeInformes ();
int initEstruct(eEmpleado* employee, int tam);
