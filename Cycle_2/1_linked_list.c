#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;

void insertAtFront(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = start;
    start = temp;
}

void insertAtEnd(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    struct node *head = start;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
}

void insertAtPosition(int data, int key)
{
    struct node *temp = malloc(sizeof(struct node));
    bool flag = false;
    struct node *head = start;
    while (head->link != NULL && flag == false)
    {
        if (head->data == key)
        {
            flag = true;
            break;
        }
        head = head->link;
    }
    if (flag == true)
    {
        temp->data = data;
        temp->link = head->link;
        head->link = temp;
    }
    else
    {
        printf("\nKey doesn't exist : No Insertion\n");
    }
}

void deleteFromFront()
{
    if (start == NULL)
    {
        printf("\nList is empty : No Deletion\n");
    }
    else
    {
        struct node *head = start;
        start = start->link;
        // temp->link = NULL;
        free(head);
    }
}

void deleteFromEnd()
{
    if (start == NULL)
    {
        printf("\nList is empty : No Deletion\n");
    }
    else
    {
        struct node *ptr = start;
        struct node *ptr1;
        while (ptr->link != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = NULL;
        free(ptr);
    }
}

void deleteFromPosition(int key)
{
    bool flag = false;
    struct node *head1, *head = start;
    while (head->link != NULL && flag == false)
    {
        head1 = head;
        head = head->link;
        if (head->data == key)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        head1->link = head->link;
        head->link = NULL;
        free(head);
    }
    else
    {
        printf("\nKey doesn't exist : No Deletion\n");
    }
}

void Traverse()
{
    struct node *head = start;
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
    int choice, element, key;
    do
    {
        printf("\n\nM E N U\n\n1. Insert to the Front of the Linked list.\n2. Insert to the Rear of the Linked list.\n3. Insert after any node\n");
        printf("4. Delete the First element of the Linked list.\n5. Delete last element of the Linked list.\n6. Delete any node.\n7. Display\n8. Exit\n\n");
    ch:
        printf("\t  -> ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &element);
            insertAtFront(element);
            break;

        case 2:
            printf("Enter the element to be inserted : ");
            scanf("%d", &element);
            insertAtEnd(element);
            break;

        case 3:
            printf("Enter the element and key position to be inserted : ");
            scanf("%d%d", &element, &key);
            insertAtPosition(element, key);
            break;

        case 4:
            deleteFromFront();
            break;

        case 5:
            deleteFromEnd();
            break;

        case 6:
            printf("Enter the data of the node to be deleted : ");
            scanf("%d", &key);
            deleteFromPosition(key);
            break;

        case 7:
            Traverse();
            break;

        case 8:
            exit(0);

        default:
            printf("Enter a valid Choice!!!!\n\n");
            goto ch;
        }
    } while (true);
}