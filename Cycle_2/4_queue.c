#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *link;
};
struct node *front = NULL;

void enqueue()
{
    int data;
    printf("Enter the data to be enqueued : ");
    scanf("%d", &data);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (front == NULL)
    {
        front = temp;
    }
    else
    {
        struct node *head = front;
        while (head->link != NULL)
        {
            head = head->link;
        }
        head->link = temp;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue Empty : No deletion\n");
    }
    else
    {
        struct node *temp = front;
        front = front->link;
        free(temp);
    }
}

void traversal()
{
    struct node *head = front;
    printf("\nFront -> ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->link;
    }
    printf("<- Rear");
}

void main()
{
    int choice;

    do
    {
        printf("\n\n\tM E N U\n\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display");
        printf("\n4. Exit\n\n");
        printf("\t-> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
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