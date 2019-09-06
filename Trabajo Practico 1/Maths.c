#include "maths.h"
    //Uso de las funciones de "Maths.h" para suma, resta, multiplicación y división

    float suma(float x, float y)
    {
        float sumar;

        sumar= x + y;

        return sumar;
    }

    float resta(float x, float y)
    {
        float restar;

        restar = x - y;

        return restar;
    }

    float multiplicacion(float x, float y)
    {
        float multiplicar;

        multiplicar = x * y;

        return multiplicar;
    }

    float division(float x, float y)
    {
        float dividir;

        dividir = x / y;

        return dividir;
    }

    int factorial(int x)
    {
        int factoreo;
        if(x==0)
        {
            factoreo = 1;
        }
        else
        {
            factoreo = factoreo * factorial(x-1);
        }
        return factoreo;
    }
