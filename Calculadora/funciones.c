#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu()
{
    printf ("CALCULADORA");

    printf ("\nIntroduce algunas de las opciones que se le muestre:\n");
    printf ("1.- Ingresar 1er operando:\n");
    printf ("2.- Ingresar 2do operando:\n");
    printf ("3.- Calcular todas las operaciones:\n");
    printf ("4.- Informar resultados:\n");
    printf ("5.- Salir:\n");
    return 0;
}


float suma(float a, float b)
{
    return a+b;
}

float resta(float a, float b)
{
    return a-b;
}

float multiplicar(float a, float b)
{
    return a*b;
}

float dividir(float a, float b)
{
    return a/b;
}


float factorialA(float a)
{
    float factorialdea;

    if (a==0)
    {
        factorialdea= 1;
    }
    else if (a<0)
    {
        factorialdea= 0;
    }
    else
    {
        factorialdea= a*factorialA(a-1);
    }

    return factorialdea;
}


float factorialB(float b)
{
    float factorialdeb;

    if (b==0)
    {
        factorialdeb= 1;
    }
    else if (b<0)
    {
        factorialdeb= 0;
    }
    else
    {
        factorialdeb= b*factorialB(b-1);
    }

    return factorialdeb;
}
