#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 5

int Queue[MAX_TERMS], front = -1, rear = -1;

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(int element)
{
    if ((rear == front - 1) || (front == 0 && rear == MAX_TERMS - 1))
    {
        printf("\nThe Queue is Full!!!\n\n");
        return;
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX_TERMS;
        Queue[rear] = element;
    }
}

int Dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nThe Queue is empty!!!\n\n");
    }
    else
    {
        int value = Queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_TERMS;
        }
        return value;
    }
}

void Display()
{
    if (isEmpty())
    {
        printf("\nThe Queue is now empty.\n\n");
    }
    else
    {
        if (rear >= front)
        {
            printf("\nQueue : \n\tFront -> ");
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", Queue[i]);
            }
            printf("<- Rear\n");
        }
        else
        {
            printf("\nQueue : \n\tFront -> ");
            for (int i = front; i < MAX_TERMS; i++)
            {
                printf("%d ", Queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", Queue[i]);
            }
            printf("<- Rear\n");
        }
    }
}

void main()
{
    int response, choice, element;
    do
    {
        printf("\n\nM E N U\n\n1. Enqueue elements to the Queue.\n2. Dequeue elements from the Queue.\n3. Exit\n\n");
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
            Dequeue();
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