#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct node
{
    int key;
    struct node *next;
};
struct node *table[TABLE_SIZE] = {NULL};
struct node *temp;
void search()
{
    printf("Enter the data you want to search for : ");
    int data;
    scanf("%d", &data);
    int i = data % TABLE_SIZE;
    if (table[i] == NULL)
    {
        printf("The element is not present !!!");
    }
    else
    {
        for (temp = table[i]; temp != NULL; temp = temp->next)
        {
            if (temp->key == data)
            {
                printf("The elements has been found at index %d", i);
                break;
            }
        }
        if (temp == NULL)
        {
            printf("The element is not present !!!");
        }
    }
}
void display()
{
    printf("Displaying the elements of the hash map :\n\n\n\n\n");
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
            temp = table[i];
            for (temp = table[i]; temp != NULL; temp = temp->next)
            {
                printf("%d->", temp->key);
            }
            printf("\n");
        }
    }
}
void main()
{
    printf("Enter the 10 values into the hash table \n");
    int a = 10;
    int data;
    while (a)
    {
        printf("Enter the data to enter into the hash table : ");
        scanf("%d", &data);
        int i = data % TABLE_SIZE;
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->key = data;
        newnode->next = NULL;
        if (table[i] == NULL)
        {
            table[i] = newnode;
        }
        else
        {
            temp = table[i];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        a--;
    }
    while (1)
    {
        printf("\n\n1.Search the hash map\n2.Display the hash map\n3.Exit\nEnter your choice : ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            search();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        }
    }
}