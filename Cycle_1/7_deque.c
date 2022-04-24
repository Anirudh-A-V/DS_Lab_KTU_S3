#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

int Queue[MAX_TERMS];
int front = -1, rear = -1, terms = 0;

void Insert_rear(int element)
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
        terms++;
    }
}

void Insert_front(int element)
{
    if (front == 0 && rear == MAX_TERMS - 1)
    {
        printf("\nInsertion not possible!!!\n");
    }
    else if (front == 0)
    {
        int i = terms - 1;
        while (i >= 0)
        {
            Queue[i + 1] = Queue[i];
            i--;
        }
        // printf("\nHello\n");
        Queue[front] = element;
        rear++;
        terms++;
        return;
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            front = 0;
            rear = 0;
            Queue[front] = element;
            terms++;
            return;
        }
        front--;
        Queue[front] = element;
        terms++;
    }
}

int Delete_front()
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
        terms--;
    }
    return element;
}

int Delete_rear()
{
    int element;
    if (front < 0)
    {
        printf("\nThe Queue is empty!!!\n");
    }
    else
    {
        element = Queue[rear];
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear != 0)
            {
                rear--;
            }
        }
        terms--;
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
        printf("\n\nM E N U\n\n1. Insert elements to the Front of the queue.\n2. Insert elements to the Rear of the queue.\n");
        printf("3. Delete elements from the Front of the queue.\n4. Delete elements from the Rear of the queue.\n5. Exit\n\n");
    ch:
        printf("\t  -> ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &element);
            Insert_front(element);
            Display();
            break;

        case 2:
            printf("Enter the element to be inserted : ");
            scanf("%d", &element);
            Insert_rear(element);
            Display();
            break;

        case 3:
            Delete_front();
            Display();
            break;

        case 4:
            Delete_rear();
            Display();
            break;

        case 5:
            exit(0);

        default:
            printf("Enter a valid Choice!!!!\n\n");
            goto ch;
        }
        printf("\nDo you want to continue (1 or 0) : ");
        scanf("%d", &response);
    } while (response == 1);
}