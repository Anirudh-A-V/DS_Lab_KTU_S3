#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

int Queue[MAX_TERMS];
int front = -1, rear = -1;

void Enqueue(int element)
{
    if (rear == MAX_TERMS - 1)
    {
        printf("\nThe Queue is Full!!!\n");
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            front = 0;
        }
        rear++;
        Queue[rear] = element;
    }
}

int Delete()
{
    int element;
    if (front < 0)
    {
        printf("\nThe Queue is empty!!!\n");
    }
    else
    {
        element = Queue[front];
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front++;
        }
    }
    return element;
}

void Display()
{
    printf("\nQueue : \n\tFront -> ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", Queue[i]);
    }
    printf("<- Rear\n");
}

void main()
{
    int response, choice, element;
    do
    {
        printf("\n\nM E N U\n\n1. Enqueue elements to the Queue.\n2. Delete elements from the Queue.\n3. Exit\n\n");
    ch:
        printf("\t  -> ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            printf("Enter the element to be Enqueueed : ");
            scanf("%d", &element);
            Enqueue(element);
            Display();
            break;

        case 2:
            Delete();
            Display();
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