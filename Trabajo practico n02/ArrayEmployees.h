#include "GetUtn.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);



/** \brief function - add employees
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int addEmployeesModificado(Employee*,int);



/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id);



/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee*, int);



/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);



/** \brief print the content of employees array
 *
 * \param Employee Only Pointer to array of employees
 * \param len int Array length
 * \return int Return
 *
 */
void printEmployeeOnly(Employee);



/** \brief print the content of employees array
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return
 *
 */
int printEmployees(Employee* list, int len);



/** \brief get Space in the content of employees array
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return
 *
 */
int getSpace (Employee*, int);



/**
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * get the first disponible index.
 * return first index disponible
 */
int NextId(Employee*, int);



/** \brief initialize employees with data
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return void
 *
 */
void initEmployeesWithData(Employee* paramEmployee, int );



/** \brief modification of the employees

 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return int > a 0 si se pudo modificar y -1 si se cancelo la modificacion.
 *
 */
int modificationEmployee(Employee*, int);



/** \brief shows the men� of data - Modify
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return int > a 0 si se pudo modificar y -1 si se cancelo la modificacion.
 *
 */
int menuModification(Employee*, int);
