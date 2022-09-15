#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
int n, cur;
void display()
{
    struct node *p = head;
    if (p == NULL)
    {
        return;
    }
    printf("Memory blocks available is/are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void allocate()
{
    int val;
    struct node *p = head;
    if (head == NULL)
    {
        printf("There is no memory blocks to be allocated!!!!\n");
        return;
    }
    printf("Enter the memory block size to be allocated: ");
    scanf("%d", &val);
    if (head->data >= val)
    {
        if (head->next != NULL)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
            head = NULL;
        printf("A memory block of size %d was allocated\n", p->data);
        --cur;
        display();
    }
    else if (head->data < val && head->next == NULL)
    {
        printf("No memory blocks are available to be allocated!!!\n");
        return;
    }
    else
    {
        while (p->next != NULL)
        {
            if (p->next->data >= val)
            {
                --cur;
                printf("A memory block of size %d was allocated\n", p->next->data);
                if (p->next->next != NULL)
                {
                    p->next->next->prev = p;
                    p->next = p->next->next;
                }
                else
                    p->next = NULL;
                display();
                return;
            }
            p = p->next;
        }
        printf("No memory blocks are available to be allocated!!!\n");
        return;
    }
}
void deallocate()
{
    if (cur == n)
    {
        printf("No memory blocks available to be deallocated!!!\n");
        return;
    }
    printf("Enter the memory block size to be deallocated: ");
    int val;
    scanf("%d", &val);
    struct node *p = head;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = p;
    newnode->next = NULL;
    if (p == NULL)
    {
        head = newnode;
        p = newnode;
        ++cur;
        display();
        return;
    }
    while (p->next != NULL)
        p = p->next;
    newnode->prev = p;
    p->next = newnode;
    ++cur;
    display();
}

int main()
{
    printf("Enter number of memory blocks available: ");
    scanf("%d", &n);
    cur = n;
    struct node *p = NULL;
    printf("Enter %d memory block sizes\n", n);
    for (int i = 0; i < n; i++)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        int val;
        printf("Enter block size: ");
        scanf("%d", &val);
        newnode->data = val;
        newnode->prev = p;
        newnode->next = NULL;
        if (head == NULL)
            head = newnode, p = newnode;
        else
            p->next = newnode, p = newnode;
    }
    do
    {
        printf("\n1. Allocate memory block\n2. Deallocate memory blocks\n3. Exit\nChooseyour option:");
        int opt;
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            allocate();
            break;
        case 2:
            deallocate();
            break;
        case 3:
            exit(0);
        default:
            printf("Enter a valid option!!!!\n");
        }
    } while (1);
}