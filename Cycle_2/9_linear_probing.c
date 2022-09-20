#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
int table[TABLE_SIZE] = {NULL};
void insert()
{
    int data;
    int i;
    printf("Enter data into the hash table : ");
    scanf("%d", &data);
    int index = data % TABLE_SIZE;
    if (table[index] == NULL)
    {
        table[index] = data;
    }
    else
    {
        i = index + 1;
        if (i == TABLE_SIZE)
            i = 0;
        while (i != index)
        {
            if (table[i] == NULL)
            {
                table[i] = data;
                break;
            }
            i++;
            if (i == TABLE_SIZE)
            {
                i = 0;
            }
        }
    }
    if (i == index)
    {
        printf("The table was full and thus element couldnt be inserted ");
    }
}
void search()
{
    int data;
    int i;
    printf("Enter the data to search for : ");
    scanf("%d", &data);
    int index = data % TABLE_SIZE;
    if (table[index] == data)
        printf("Data entered found at index %d", index);
    else
    {
        i = index + 1;
        while (i != index)
        {
            if (table[i] == data)
            {
                printf("Data found at index %d", index);
                break;
            }
            i++;
            if (i == TABLE_SIZE)
            {
                i = 0;
            }
        }
    }

    if (i == index)
    {
        printf("The element was not found within the given hash table ");
    }
}
void display()
{
    printf("Displaying the elements of the hash table :\n\n\n\n\n");
    printf("INDEX\tKEY\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] == NULL)
        {
            printf("%d", i);
            printf("\t");
            printf("\n");
            continue;
        }
        else
        {
            printf("%d", i);
            printf("\t");
            printf("%d", table[i]);
            printf("\n");
        }
    }
}
int main()
{
    while (1)
    {
        printf("\n\n1.Enter into the hash table\n2.Search the hash table\n3.Display the hash table\n4.Exit\nEnter your choice : ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}