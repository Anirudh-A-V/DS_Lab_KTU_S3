#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;

void insertatbeginning(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = top;
    top = temp;
}

void insertatend(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    struct node *head = top;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
}

void insertatposition(int data, int key)
{
    struct node *temp = malloc(sizeof(struct node));
    bool flag = false;
    struct node *head = top;
    while (head->link != NULL && flag == false)
    {
        if (head->data == key)
        {
            flag = true;
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

void deletefrombeginning()
{
    if (top == NULL)
    {
        printf("\nList is empty : No Deletion\n");
    }
    else
    {
        struct node *head = top;
        struct node *temp = head->link;
        head->link = temp->link;
        temp->link = NULL;
        free(temp);
    }
}

void deletefromend()
{
    if (top == NULL)
    {
        printf("\nList is empty : No Deletion\n");
    }
    else
    {
        struct node *ptr = top;
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

void deletefromposition(int key)
{
    bool flag = false;
    struct node *head1, *head = top;
    while (head->link != NULL && flag == false)
    {
        head1 = head;
        if (head->data == key)
        {
            flag = true;
        }
        head = head->link;
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

void main()
{
}
