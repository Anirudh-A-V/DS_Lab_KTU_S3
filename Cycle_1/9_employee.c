#include <stdio.h>
#include <stdlib.h>

typedef struct names // Defining a structure for names
{
    char First_name[20];
    char Middle_name[20];
    char Last_name[30];
} names;

typedef struct employee_details // Defining a structure for employees
{
    names Name;
    int Employee_ID;
    int Salary;
} employee_details;

int no_of_employees;
struct employee_details *details_ptr;

void Display(int i);
int search(int ID);

void main()
{
    int response, choice, employee_id;

    printf("Enter the number of employees : ");
    scanf("%d", &no_of_employees);

    details_ptr = (struct employee_details *)malloc(no_of_employees * sizeof(employee_details));
    if (details_ptr == NULL)
    {
        printf("Error!!! memory not allocated.(details_ptr)");
        exit(0);
    }

    printf("Please enter the employee details (Name Employee_ID Salary) : \n\n");
    for (int i = 0; i < no_of_employees; i++)
    {
        printf("Enter the name of employee no. %d (First_name Middle_name Last_name) : \n", i + 1);
        scanf("%s %s %s", (details_ptr + i)->Name.First_name, (details_ptr + i)->Name.Middle_name, (details_ptr + i)->Name.Last_name);
        printf("Enter the Employee ID : ");
        scanf("%d", &(details_ptr + i)->Employee_ID);
        printf("Enter the Salary : ");
        scanf("%d", &(details_ptr + i)->Salary);
    }

    do
    {
        printf("\n\n\t M E N U\n\n");
        printf("1. Search\n2. Display details of all employees\n3. Exit\n\n");
    ch:
        printf("\t->");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("To search the employee please enter the employee ID : ");
            scanf("%d", &employee_id);
            Display(search(employee_id));
            break;

        case 2:
            for (int i = 0; i < no_of_employees; i++)
            {
                printf("\nEmployee_ID. - %d  \nName - %s %s %s \tSalary - %d\n", (details_ptr + i)->Employee_ID, (details_ptr + i)->Name.First_name, (details_ptr + i)->Name.Middle_name, (details_ptr + i)->Name.Last_name, (details_ptr + i)->Salary);
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\nEnter a valid Choice!!!\n");
            goto ch;
        }

        printf("\nDo you want to continue( 1 or 0 ) : ");
        scanf("%d", &response);

    } while (response == 1);
}

void Display(int i)
{
    printf("\nEmployee_ID. - %d\nName - %s %s %s \tSalary - %d\n", (details_ptr + i)->Employee_ID, (details_ptr + i)->Name.First_name, (details_ptr + i)->Name.Middle_name, (details_ptr + i)->Name.Last_name, (details_ptr + i)->Salary);
}

int search(int ID)
{
    int flag;
    for (int i = 0; i < no_of_employees; i++)
    {
        if ((details_ptr + i)->Employee_ID == ID)
        {
            flag = i;
            break;
        }
    }
    return flag;
}