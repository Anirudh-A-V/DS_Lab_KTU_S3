#include <stdio.h>
#include <string.h>
struct substring
{
    int length;
    char substring[10];
} substr[20], temp;

int main()
{
    char string[20], check[20];
    int i = 0, j = 0, k = 0, count = 0;

    printf("\nEnter a string : ");
    scanf(" %[^\n]", string);

    check[0] = string[0];
    check[1] = '\0';
    for (i = 1; string[i] != '\0'; i++)
    {
        for (j = 0; check[j] != '\0'; j++)
        {
            if (check[j] == string[i])
            {
                strcpy(substr[k].substring, check);
                substr[k].length = strlen(check);
                k++;
                check[0] = string[i];
                check[1] = '\0';
                count = 0;
                break;
            }
            else
                count++;
        }
        if (count > 0)
        {
            check[count] = string[i];
            check[count + 1] = '\0';
            count = 0;
        }
    }
    strcpy(substr[k].substring, check);
    substr[k].length = strlen(check);
    k++;
    for (i = 1; i < k; i++)
    {
        for (j = 0; j < k - i; j++)
        {
            if (substr[j].length < substr[j + 1].length)
            {
                temp = substr[j];
                substr[j] = substr[j + 1];
                substr[j + 1] = temp;
            }
        }
    }
    printf("The longest substring is %s with the length of %d.\n", substr[0].substring, substr[0].length);
}