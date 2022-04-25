#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;

void push(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = top;
    top = temp;
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack is empty : No Deletion\n");
    }
    else
    {
        struct node *head = top;
        top = top->link;
        free(head);
    }
}

void traversal(){
    struct node *head = top;
    printf("\nStack : \n\n");
    while (head != NULL)
    {
        printf("\t%d\n", head->data);
        head = head->link;
    }
}

void main()
{
    int choice, data, key;

    do
    {
        printf("\n\n\tM E N U\n\n");
        printf("1. Push\n2. Pop\n3. Display");
        printf("\n4. Exit\n\n");
        printf("\t-> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be pushed : ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            traversal();
            break;

        case 4:
            exit(0);

        default:
            break;
        }
    } while (true);
}
