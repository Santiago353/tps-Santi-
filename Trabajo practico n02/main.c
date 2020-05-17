#include "GetUtn.h"
#include "ArrayEmployees.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define E 50

int main()
{
    int i;
    int mayorSalario;
    int contadorSalario;
    int acumuladorSalario;
    int validarNewEmployee;

    char opcion;

    float promedioSalario;

    Employee misEmpleados[E];

    initEmployees(misEmpleados, E);
    initEmployeesWithData(misEmpleados, E);

    do
    {
        printf("(1) ALTA EMPLEADO. \n");
        printf("(2) MODIFICAR EMPLEADO. \n");
        printf("(3) BAJA DE EMPLEADO. \n");
        printf("(4) MOSTRAR LISTADO E INFORMAR. \n");
        printf("(5) SALIR. \n");

        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5')
        {
            printf("Ingrese una opcion valida.\n");
            printf("Elija una opcion: ");
            fflush(stdin);
            scanf("%c", &opcion);
        }

        switch(opcion)
        {
        case '1':
            validarNewEmployee = addEmployeesModificado(misEmpleados, E);
            break;

        case '2':
            modificationEmployee(misEmpleados, E);
            break;

        case '3':
            removeEmployee(misEmpleados, E);
            break;

        case '4':
            contadorSalario = 0;
            acumuladorSalario = 0;
            mayorSalario = 0;
            promedioSalario = 0;

            sortEmployees(misEmpleados, E, 0);

            for (i=0; i<E; i++)
            {
                if (misEmpleados[i].isEmpty == 1)
                {
                    acumuladorSalario = misEmpleados[i].salary + acumuladorSalario;
                    contadorSalario++;
                }
            }
            promedioSalario = (acumuladorSalario / contadorSalario);

            for (i=0; i<E; i++)
            {
                if (misEmpleados[i].isEmpty == 1 && misEmpleados[i].salary > promedioSalario)
                {
                    mayorSalario++;
                }
            }
            printEmployees(misEmpleados, E);

            printf("El promedio es: %f\n", promedioSalario);
            printf("Los empleados que superan el sueldo promedio son: %d\n", mayorSalario);
            break;

        case '5':
            opcion='5';
            break;

        default:
            printf("Ingrese una opcion valida.\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!='5');

    return 0;
}

