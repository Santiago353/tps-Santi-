#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len)
{
    int retornar;
    int i;
    if(list != NULL)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty= 0;
        }
        retornar= 0;
    }
    else
    {
        retornar= -1;
    }
    return retornar;
}


int addEmployeesModificado(Employee* paramEmployee,int len)
{
    char auxSector[50];
    char auxSalary[50];
    float salary;
    int retorno= -1;
    int sector;
    int id;
    int i;

    id= NextId(paramEmployee, len);
    i= getSpace(paramEmployee, len);

    if(i>=0)
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(paramEmployee[i].name);
        //VALIDACION
        while(isOnlyLetters(paramEmployee[i].name) == 0)
        {
            printf("Intente nuevamente: ");
            fflush(stdin);
            gets(paramEmployee[i].name);
        }
        stringToUpper(paramEmployee[i].name);


        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(paramEmployee[i].lastName);
        //VALIDACION
        while(isOnlyLetters(paramEmployee[i].lastName) == 0)
        {
            printf("Intente nuevamente: ");
            fflush(stdin);
            gets(paramEmployee[i].lastName);
        }
        stringToUpper(paramEmployee[i].lastName);


        printf("Ingrese el salario: ");
        fflush(stdin);
        gets(auxSalary);
        //VALIDACION
        while(isNumeric(auxSalary) == 0)
        {
            printf("Intente nuevamente: ");
            fflush(stdin);
            gets(auxSalary);
        }
        salary=atoi(auxSalary);
        paramEmployee[i].salary=salary;


        printf("Ingrese el sector: ");
        fflush(stdin);
        gets(auxSector);
        //VALIDACION
        while(isNumeric(auxSector)==0)
        {
            printf("Intente nuevamente: ");
            fflush(stdin);
            gets(auxSector);
        }
        sector= atoi(auxSector);
        paramEmployee[i].sector= sector;

        paramEmployee[i].isEmpty =1;
        paramEmployee[i].id =id;

        retorno =0;

        printf("\nExito.\n");
    }
    else
    {
        printf("\nNo hay espacio libre.\n");
    }
    return retorno;
}


int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1 && list[i].id==id)
        {
            return i;
        }
    }
    return -1;
}


int removeEmployee(Employee* paramEmployee, int len)
{
    int opcion;
    int idUser;
    int i;

    printEmployees(paramEmployee, len);

    printf("\nIngrese el id del empleado para dar de baja.\n");
    scanf("%d",&idUser);

    for(i=0; i<len; i++)
    {
        if(idUser==paramEmployee[i].id)
        {
            printf("Desea dar de baja? Ingrese(0-s/1-n)\n");
            scanf("%d",&opcion);

            if (opcion == 0)
            {
                paramEmployee[i].isEmpty = 0;
                paramEmployee[i].id= 0;
                printf("Se ha dado de baja.\n");
                break;
            }
            else if (opcion == 1)
            {
                printf("No se ha dado de baja.\n");
                break;
            }
            else
            {
                printf("Intente nuevamente: ");
                break;
            }
        }
    }
}


int sortEmployees(Employee* paramEmployee, int len, int order)
{
    Employee auxEmployee;
    char auxOpcion[50];
    int opcion;

    int i;
    int j;

    printf("\nComo desea ordenar la lista?\n");
    printf("(1) Por apellido.\n");
    printf("(2) Por sector.\n");

    printf("\nElija una opcion: ");
    fflush(stdin);
    gets(auxOpcion);

    while(isNumeric(auxOpcion)==0)
    {
        printf("Intente nuevamente: ");
        fflush(stdin);
        gets(auxOpcion);
    }
    opcion=atoi(auxOpcion);

    if(opcion==1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(paramEmployee[i].lastName,paramEmployee[j].lastName) > order)
                {
                    auxEmployee=paramEmployee[i];
                    paramEmployee[i]=paramEmployee[j];
                    paramEmployee[j]=auxEmployee;
                }
            }
        }
    }
    else if(opcion==2)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(paramEmployee[i].sector > paramEmployee[j].sector)
                {
                    auxEmployee=paramEmployee[i];
                    paramEmployee[i]=paramEmployee[j];
                    paramEmployee[j]=auxEmployee;
                }
            }
        }
    }
    else
    {
        printf("Intente nuevamente: ");
    }
}


void printEmployeeOnly(Employee paramEmployee)
{
    printf("%d -- %10s %15s %20f %10d\n\n", paramEmployee.id, paramEmployee.name, paramEmployee.lastName, paramEmployee.salary, paramEmployee.sector);
}


int printEmployees(Employee* paramEmployee, int len)
{
    printf("\n\nID -- \t NAME \t\tLASTNAME \tSALARY \t\tSECTOR\n\n");

    int i;
    for(i=0; i<len; i++)
    {
        if (paramEmployee[i].isEmpty == 1)
        {
            printEmployeeOnly(paramEmployee[i]);
        }
    }
}


int getSpace(Employee* paramEmployee, int len)
{
    int i;
    int index= -1;
    for (i=0; i<len; i++)
    {
        if (paramEmployee[i].isEmpty == 0)
        {
            index= i;
            break;
        }
    }
    return index;
}


int NextId(Employee* paramEmployee, int len)
{
    int i;
    int retorno= 0;
    if(len > 0 && paramEmployee != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(paramEmployee[i].isEmpty == 1)
            {
                if(paramEmployee[i].id > retorno)
                {
                    retorno = paramEmployee[i].id;
                }
            }
        }
    }
    return retorno+1;
}

void initEmployeesWithData(Employee* paramEmployee, int len)
{
    int i;

    int id[5] = {1,2,3,4,5};
    char name[5][51] = {"Santiago","Alejo","Agustin","Maximo","Tomas"};
    char lastName[5][51] = {"Ramos","Gomez","Ramos","Gonzalez","Moreno"};
    float salary[5] = {1000,2000,3000,4000,5000};
    int sector[5] = {5,10,15,20,25};

    for (i=0; i<5; i++)
    {
        paramEmployee[i].id = id[i];
        strcpy(paramEmployee[i].name, name[i]);
        strcpy(paramEmployee[i].lastName, lastName[i]);
        paramEmployee[i].salary = salary[i];
        paramEmployee[i].sector = sector[i];
        paramEmployee[i].isEmpty = 1;
    }
}


int modificationEmployee(Employee* paramEmployee, int len)
{
    char auxId[20];

    int retorno= -2;
    int index;
    int rt;
    int id;

    if(len >0 && paramEmployee!= NULL)
    {
        retorno=-1;

        printEmployees(paramEmployee, len);

        printf("Ingrese el ID: ");
        fflush(stdin);
        gets(auxId);

        while(isNumeric(auxId)==0)
        {
            printf("Intente nuevamente: ");
            fflush(stdin);
            gets(auxId);
        }
        id=atoi(auxId);

        index=findEmployeeById(paramEmployee, len, id);

        if(index>=0)
        {
            rt=menuModification(paramEmployee, index);
            retorno=rt;
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}


int menuModification(Employee* paramEmployee, int index)
{
    float salary;

    char auxSector[30];
    char auxSalary[30];
    char auxLastName[30];
    char auxName[30];
    char auxOpcion[30];

    int retorno=-1;
    int sector;
    int opcion;

    printf("\n¿Que desea modificar?\n");
    printf("(1) Nombre.\n");
    printf("(2) Apellido.\n");
    printf("(3) Salario.\n");
    printf("(4) Sector.\n");

    printf("Elija una opcion: ");
    fflush(stdin);
    gets(auxOpcion);

    while(isNumeric(auxOpcion)==0)
    {
        printf("Intente nuevamente: ");
        fflush(stdin);
        gets(auxOpcion);
    }
    opcion=atoi(auxOpcion);

    if(opcion>=1&&opcion<=6)
    {
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre:");
            fflush(stdin);
            gets(auxName);
            while(isOnlyLetters(auxName)==0)
            {
                printf("Intente nuevamente: ");
                fflush(stdin);
                gets(auxName);
            }
            stringToUpper(auxName);
            strcpy(paramEmployee[index].name, auxName);
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        case 2:
            printf("Ingrese el nuevo apellido:");
            fflush(stdin);
            gets(auxLastName);
            while(isOnlyLetters(auxLastName)==0)
            {
                printf("Intente nuevamente: ");
                fflush(stdin);
                gets(auxLastName);
            }
            stringToUpper(auxLastName);
            strcpy(paramEmployee[index].lastName, auxLastName);
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        case 3:
            printf("Ingrese el nuevo salario:");
            fflush(stdin);
            gets(auxSalary);
            while(isNumeric(auxSalary)==0)
            {
                printf("Intente nuevamente: ");
                fflush(stdin);
                gets(auxSalary);
            }
            salary = atoi(auxSalary);
            paramEmployee[index].salary = salary;
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        case 4:
            printf("Ingrese el nuevo sector:");
            fflush(stdin);
            gets(auxSector);
            while(isNumeric(auxSector)==0)
            {
                printf("Intente nuevamente: ");
                fflush(stdin);
                gets(auxSector);
            }
            sector = atoi(auxSector);
            paramEmployee[index].sector = sector;
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        default:
            printf("Intente nuevamente: ");
            return -2;
            break;
        }
    }
    else
    {
        printf("Intente nuevamente: ");
        return -2;
    }
    return retorno;
}
