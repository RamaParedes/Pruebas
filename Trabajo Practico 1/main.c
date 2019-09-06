#include <stdlib.h>
#include "maths.h"
int main()
{
    //Declaro las variables.

    float x;
    float y;
    float sumar;
    float restar;
    float dividir;
    float multiplicar;
    int primerFactorial;
    int segundoFactorial;
    int resultOp;

    //La toma de los numeros.
    printf("Ingrese el primer numero: \n");
    scanf("%f",&x);
    printf("Ingrese el segundo numero: \n");
    scanf("%f", &y);

    //Funciones matematicas, devuelven un resultado. Si el segundo numero es 0 en la division, la misma no se realiza

    sumar = suma(x, y);

    restar = resta(x, y);
    if(y != 0)
    {
        dividir = division(x, y);
    }
    else
    {
        dividir = 0;
    }

    multiplicar = multiplicacion(x, y);

    primerFactorial = factorial(x);
    segundoFactorial = factorial(y);

    //Los resultados, si se divide por 0, se muestra que no es posible realizar la misma.

    printf("El resultado de la suma de %0.2f y %0.2f es: %0.2f\n", x, y, sumar);

    printf("El resultado de la resta entre %0.2f y %0.2f es: %0.2f\n", x, y, restar);

    if(y != 0)
    {
        printf("El resultado de la division entre %0.2f y %0.2f es: %0.2f\n", x, y, dividir);
    }
    else
    {
        printf("No se puede dividir por 0\n");
    }

    printf("El resultado de la multiplicacion entre %0.2f y %0.2f es: %0.2f\n", x, y, multiplicar);

    if(x >= 0)
    {
        printf("El factorial del numero %0.2f es: %d\n", x, primerFactorial);
    }

    if(y >= 0)
    {
        printf("El factorial del numero %0.2f es: %d\n", y, segundoFactorial);
    }

    return 0;
}
