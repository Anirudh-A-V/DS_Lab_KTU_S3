#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root_node = NULL;

struct node *create_Node(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *create_Tree()
{
    int data;

    printf("Enter the value of the node (-1 for no node) : ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct node *new_node = create_Node(data);
    printf("\nEnter the left child of %d : ");
    new_node->left = create_Tree();
    printf("\nEnter the right child of %d : ");
    new_node->right = create_Tree();

    return new_node;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return NULL;

    inorder(root->left);
    printf("&d  ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return NULL;

    printf("&d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return NULL;

    postorder(root->left);
    postorder(root->right);
    printf("&d  ", root->data);
}

struct node *search_key(struct node *root, int key)
{
    struct node *temp = root;
    if (root == NULL)
        return NULL;

    if (temp->data == key)
    {
        return temp;
    }
    else
    {
        search_key(temp->left, key);
        search_key(temp->right, key);
    }
}
void insert_node(int data, int key)
{
    struct node key_node = search_key(root, key);
    if (key_node == NULL)
    {
        printf("\nSearch Unsuccessful : No insertion\n");
        return;
    }
    if (key_node->left == NULL || key_node->right == NULL)
    {
        char choice;
    lh:
        printf("Do you want to insert the child as left child(L) or right child(R) : ");
        scanf("%c", &choice);
        if (choice == 'l' || choice == 'L')
        {
            struct node newnode = create_Node(data);
            key_node->left = newnode;
        }
        else if (choice == 'r' || choice == 'R')
        {
            struct node newnode = create_Node(data);
            key_node->right = newnode;
        }
        else
        {
            printf("Please enter a valid choice!!!");
            goto lh;
        }
    }
    else
    {
        printf("\nInsertion not possible\n");
    }
}

struct node *search_parent(struct node *root, int key, struct node *par)
{
    struct node *temp = root;
    if (root == NULL)
        return NULL;

    if (temp->data == key)
    {
        return par;
    }
    else
    {
        // par = temp;
        search_parent(temp->left, key, temp);
        search_parent(temp->right, key, temp);
    }
}

void delete_node(struct node *root, int key)
{
    struct node *ptr = search_parent(root, key, root);
    if (ptr == NULL)
    {
        printf("\nSearch Unsuccessful : No deletion\n");
        return;
    }
    struct node *ptr_l = ptr->left, *ptr_r = ptr->right;
    
}
void main()
{
}