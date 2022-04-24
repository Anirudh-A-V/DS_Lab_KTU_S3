#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE], n, b, top = -1;

void push(int element);
void pop();
void display();

void main()
{

    printf("Enter the size of the stack : ");
    scanf("%d", &n);

    int response, choice, element;
    do
    {
        printf("\n\nM E N U\n\n1. Pushing elements to the Stack\n2. Popping elements from the Stack\n3. Exit\n\n");
    ch:
        printf("\t  -> ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            printf("Enter the element to be Enqueueed : ");
            scanf("%d", &element);
            push(element);
            display();
            break;

        case 2:
            pop();
            display();
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

void push(int element)
{
    if (top >= n - 1)
    {
        printf("Stack Overflow!!!\n\n");
        return;
    }
    else
    {
        top++;
        stack[top] = element;
        printf("\n\n");
    }
}

void pop()
{
    if (top <= 0)
    {
        printf("\nStack Inflow!!!\n");
    }
    else
    {
        top--;
    }
}

void display()
{
    printf("Stack : \n");
    for (int i = top; i >= 0; i--)
    {
        printf("\t  %d\n", stack[i]);
    }
}
