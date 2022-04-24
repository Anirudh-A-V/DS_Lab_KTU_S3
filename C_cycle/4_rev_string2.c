#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_list(char str[][100], int n)
{
    char temp[100];
    for (int i = 0; i < n / 2; i++)
    {
        strcpy(temp, str[i]);
        strcpy(str[i], str[n - 1 - i]);
        strcpy(str[n - 1 - i], temp);
    }
}

void order(char str[][100], int n, int a)
{
    char temp[100];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcasecmp(str[i], str[j]) * a > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}

void reverse_string(char *str)
{
    int i, j = 0, l = 0;
    char tmp[10];

    while (*str)
    {
        l++;
        str++;
    }
    str--;

    for (i = l; i > 0; i--, j++)
    {
        tmp[j] = *str;
        str--;
    }

    tmp[j] = '\0';
    str++;
    
    strcpy(str, tmp);
}

void main()
{
    int n;

    printf("Enter the number of strings to be entered : ");
    scanf("%d", &n);

    char strings[n][100];

    printf("Please enter the strings : \n");
    for (int i = 0; i < n; i++)
    {
        printf("String %d - ", i + 1);
        scanf("%s", strings[i]);
        reverse_string(strings[i]);
    }

    // Reversing the list
    // reverse_list(strings, n);

    printf("\nThe Reversed list : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", strings[i]);
    }

    int response, choice;

    do
    {
        printf("\n\n\t M E N U\n\n");
        printf("1. Sort in Alphabetical order\n2. Sort in Reverse Alphabetical order\n\n");
        printf("\t->");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1: // Sorting in Alphabetical Order
            order(strings, n, 1);
            break;

        case 2: // Sorting in Reverse-alphabetical Order
            order(strings, n, -1);
            break;

        default:
            break;
        }

        printf("\n\nList after sorting : \n\n");
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", strings[i]);
        }

        printf("\n");
        printf("Do you want to continue( 1 or 0 ) : ");
        scanf("%d", &response);

    } while (response == 1);
}