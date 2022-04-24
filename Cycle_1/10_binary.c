#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int first = 0, middle, last, no_of_words = 0;

void sort(char str[][100], int n)
{
    char temp[100];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcasecmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}

void binary_search(char key[100], char string[][100]);

void main()
{
    char string[10][100], a_string[100], key[100];

    FILE *file_ptr;
    file_ptr = fopen("file.txt", "r");

    if (file_ptr == NULL)
    {
        printf("\nThe file failed to open!!!\n\n");
        exit(0);
    }
    else
    {
        while (!feof(file_ptr))
        {
            fgets(a_string, 100, file_ptr);
            int len = strlen(a_string);
            if (no_of_words != 9)
            {
                a_string[len - 1] = '\0';
            }
            // len = strlen(a_string);
            // printf("%d\n", len);
            // printf("%c\n", a_string[len - 1]);
            strcpy(string[no_of_words], a_string);
            no_of_words++;
        }
        fclose(file_ptr);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", string[i]);
    }
    // printf("\n%s", string[0]);
    // printf("\nEnter the string to search : ");
    // scanf("%s", key);
    // binary_search(key, string);

    int response, choice;
    do
    {
        printf("\n\nM E N U\n\n1. Search\n2. Sort\n3. Exit\n\n");
    ch:
        printf("\t  -> ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            printf("\nEnter the string to search : ");
            scanf("%s", key);
            binary_search(key, string);
            break;

        case 2:
            sort(string, no_of_words);
            for (int i = 0; i < 10; i++)
            {
                printf("%s ", string[i]);
                printf("\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Enter a valid Choice!!!!\n\n");
            goto ch;
        }
        printf("\nDo you want to continue (1 or 0) : ");
        scanf("%d", &response);
    } while (response == 1);
}

void binary_search(char key[100], char string[][100])
{
    last = no_of_words - 1;
    middle = (first + last) / 2;
    sort(string, no_of_words);

    while (first <= last)
    {
        if (strcasecmp(string[middle], key) < 0)
        {
            first = middle + 1;
        }
        else if (strcasecmp(string[middle], key) == 0)
        {
            printf("\n'%s' is found at location %d.\n", key, middle + 1);
            break;
        }
        else
        {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }

    if (first > last)
        printf("String not found!!! %s isn't present in the list.\n", key);
}