#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

struct priorityqueue
{
    int element;
    int priority;
} priority_queue[MAX_SIZE];
int rear = -1;

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void sort()
{
    for (int i = 0; i <= rear; i++)
    {
        for (int j = i; j <= rear; j++)
        {
            if (priority_queue[i].priority > priority_queue[j].priority)
            {
                swap(&priority_queue[i].priority, &priority_queue[j].priority);
                swap(&priority_queue[i].element, &priority_queue[j].element);
            }
        }
    }
}

int isEmpty()
{
    if (rear == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void Insert(int element, int priority)
{
    rear++;
    priority_queue[rear].element = element;
    priority_queue[rear].priority = priority;
}

int getHighestPriority()
{
    int priority = -1;
    if (!isEmpty())
    {
        for (int i = 0; i <= rear; i++)
        {
            if (priority_queue[i].priority > priority)
            {
                priority = priority_queue[i].priority;
            }
        }
    }
    return priority;
}

int Delete()
{
    int i, element, priority = getHighestPriority();
    for (i = 0; i <= rear; i++)
    {
        if (priority_queue[i].priority == priority)
        {
            element = priority_queue[i].element;
            break;
        }
    }
    if (i < rear)
    {
        for (int j = i; j < rear; j++)
        {
            priority_queue[j] = priority_queue[j + 1];
        }
    }
    rear--;
    return element;
}

void Display()
{
    int i;
    if (isEmpty())
    {
        printf("\nThe Queue is now empty.\n\n");
    }
    else
    {
        sort();
        printf("\nPriority Queue : \n\tFront -> ");
        for (i = 0; i <= rear; i++)
        {
            printf("%d ", priority_queue[i].element);
        }
        printf("<- Rear\n");
    }
}

void main()
{
    int response, choice, element, priority;
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
            printf("Enter the element to be inserted and its priority : ");
            scanf("%d%d", &element, &priority);
            Insert(element, priority);
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