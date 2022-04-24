#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct names // Defining a structure for names
{
    char First_name[20];
    char Middle_name[20];
    char Last_name[30];
} names;

typedef struct customer_details // Defining a structure for customers
{
    names Name;
    int Account_no;
    char Account_type[5];
    int Account_balance;
} customer_details;

int no_of_customers;
struct customer_details *details_ptr;

void search(int acc_number, int function);

void FD_listing();

void sort();

void main()
{
    int response, choice, account_number;

    printf("Enter the number of customers : ");
    scanf("%d", &no_of_customers);

    details_ptr = (struct customer_details *)malloc(no_of_customers * sizeof(customer_details));
    if (details_ptr == NULL)
    {
        printf("Error!!! memory not allocated.(details_ptr)");
        exit(0);
    }

    printf("Please enter the customer details (Name Account_number Account_type Account_balance) : \n\n");
    for (int i = 0; i < no_of_customers; i++)
    {
        printf("Enter the name of customer no. %d (First_name Middle_name Last_name) : \n", i + 1);
        scanf("%s %s %s", (details_ptr + i)->Name.First_name, (details_ptr + i)->Name.Middle_name, (details_ptr + i)->Name.Last_name);
        printf("Enter the Account Number : ");
        scanf("%d", &(details_ptr + i)->Account_no);
        printf("Enter the Account_type (SB , FD or CURR) : \n");
        scanf("%s", (details_ptr + i)->Account_type);
        printf("Enter the Account Balance : ");
        scanf("%d", &(details_ptr + i)->Account_balance);
    }

    for (int i = 0; i < no_of_customers; i++)
    {
        printf("\nAcc_no. - %d\tName - %s %s %s \nAcc_type - %s \tBalance - %d\n", (details_ptr + i)->Account_no, (details_ptr + i)->Name.First_name, (details_ptr + i)->Name.Middle_name, (details_ptr + i)->Name.Last_name, (details_ptr + i)->Account_type, (details_ptr + i)->Account_balance);
    }

    do
    {
        printf("\n\n\t M E N U\n\n");
        printf("1. Search\n2. Retrieve the balance\n3. Display a list of customers\n4. Display the details of Account type FD\n\n");
        printf("\t->");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("To search the customer please enter the account number : ");
            scanf("%d", &account_number);
            search(account_number, 1);
            break;

        case 2:
            printf("To retrieve the balance please enter the account number : ");
            scanf("%d", &account_number);
            search(account_number, 2);
            break;

        case 3:
            sort();
            break;

        case 4:
            FD_listing();
            break;

        default:
            break;
        }

        printf("Do you want to continue( 1 or 0 ) : ");
        scanf("%d", &response);

    } while (response == 1);
}

void search(int acc_number, int function)
{
    int flag = 0;
    for (int i = 0; i < no_of_customers; i++)
    {
        if (acc_number == ((details_ptr + i)->Account_no) && function == 1)
        {
            printf("\nAcc_no. - %d\tName - %s %s %s \nAcc_type - %s \tBalance - %d\n\n", (details_ptr + i)->Account_no, (details_ptr + i)->Name.First_name, (details_ptr + i)->Name.Middle_name, (details_ptr + i)->Name.Last_name, (details_ptr + i)->Account_type, (details_ptr + i)->Account_balance);
            flag++;
        }
        if (acc_number == ((details_ptr + i)->Account_no) && function == 2)
        {
            printf("\nBalance - %d\n\n", (details_ptr + i)->Account_balance);
            flag++;
        }
    }
    if (flag == 0)
    {
        printf("\nEnter a valid Account no.!!!\n");
    }
}

void FD_listing()
{
    char type[] = "FD";
    int value, flag = 0;
    for (int i = 0; i < no_of_customers; i++)
    {
        value = strcmp(type, (details_ptr + i)->Account_type);
        if (value == 0)
        {
            printf("\nAcc_no. - %d\tName - %s %s %s \nAcc_type - %s \tBalance - %d\n\n", (details_ptr + i)->Account_no, (details_ptr + i)->Name.First_name, (details_ptr + i)->Name.Middle_name, (details_ptr + i)->Name.Last_name, (details_ptr + i)->Account_type, (details_ptr + i)->Account_balance);
            flag++;
        }
    }
    if (flag == 0)
    {
        printf("\nNo customer have FD type account.\n");
    }
}

void sort()
{
    customer_details t;
    int value, flag = 0;

    for (int i = 0; i < no_of_customers; i++)
    {
        for (int j = i + 1; j < no_of_customers; j++)
        {
            value = strcasecmp((details_ptr + i)->Name.First_name, (details_ptr + j)->Name.First_name);
            if (value > 0)
            {
                t = details_ptr[i];
                details_ptr[i] = details_ptr[j];
                details_ptr[j] = t;
                flag++;
            }
        }
    }
    if (flag > 0)
    {
        for (int i = 0; i < no_of_customers; i++)
        {
            printf("\nAcc_no. - %d\tName - %s %s %s \nAcc_type - %s \tBalance - %d\n", (details_ptr + i)->Account_no, (details_ptr + i)->Name.First_name, (details_ptr + i)->Name.Middle_name, (details_ptr + i)->Name.Last_name, (details_ptr + i)->Account_type, (details_ptr + i)->Account_balance);
        }
        printf("\n");
    }
    else
    {
        printf("Sorting unsuccessful!!\n\n");
    }
}