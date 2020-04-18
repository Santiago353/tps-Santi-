#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int opc;
    float a;
    float b;

    float mostrarsuma;
    float mostrarresta;
    float mostrarmultiplicacion;
    float mostrardivision;
    float mostrarfactorialA;
    float mostrarfactorialB;

    do
    {
        menu();

        printf("\nEl primer numero es: %f \n", a);
        printf("El segundo numero es: %f \n", b);

        printf ("\n\nOpcion: ");
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            printf("\nIngrese el 1er operando: ");
            scanf("%f", &a);
            break;

        case 2:
            printf("\nIngrese el 2do operando: ");
            scanf("%f", &b);
            break;

        case 3:
            printf("3. Calculando operaciones....\n ");
            mostrarsuma = suma(a, b);
            mostrarresta = resta(a, b);
            mostrarmultiplicacion = multiplicar(a, b);
            mostrardivision = dividir(a, b);
            mostrarfactorialA = factorialA(a);
            mostrarfactorialB = factorialB(b);
            break;

        case 4:
            printf("\nLa suma es: %.2f \n", mostrarsuma);
            printf("La resta es: %.2f \n", mostrarresta);
            printf("La division es: %.2f \n", mostrardivision);
            printf("La multiplicacion es: %.2f \n", mostrarmultiplicacion);
            printf("El factorial es: %.2f \n", mostrarfactorialA);
            printf("El factorial es: %.2f \n", mostrarfactorialB);
            break;

        case 5:
            break;

        default:
            printf("\nIntroduce una opción valida...");
        }

        system("pause");
        system("cls");
    }
    while (opc != 5);
}
