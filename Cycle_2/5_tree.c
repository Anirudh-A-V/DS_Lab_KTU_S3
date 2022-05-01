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
    printf("\nEnter the left child of %d : ", data);
    new_node->left = create_Tree();
    printf("\nEnter the right child of %d : ", data);
    new_node->right = create_Tree();

    // return new_node;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
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
    // return temp;
}
void insert_node(struct node *root, int data, int key)
{
    struct node *key_node = search_key(root, key);
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
            struct node *newnode = create_Node(data);
            key_node->left = newnode;
        }
        else if (choice == 'r' || choice == 'R')
        {
            struct node *newnode = create_Node(data);
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
    struct node *temp;
    if (root == NULL)
        return NULL;

    else if ((root->right != NULL && root->right->data == key) || (root->left != NULL && root->left->data == key))
    {
        return root;
    }
    else
    {
        temp = search_parent(root->right, key, root);
        if (temp == NULL)
        {
            temp = search_parent(root->left, key, root);
        }
        return temp;
    }
}

void delete_node(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    printf("\n1\n");
    struct node *ptr = search_parent(root, key, root);
    printf("\n2");
    if (ptr == NULL)
    {
        printf("\nSearch Unsuccessful : No Deletion\n");
    }
    else
    {
        printf("\n3");
        struct node *ptr_l = ptr->left, *ptr_r = ptr->right;
        if (ptr_l != NULL)
        {
            printf("\n%d", ptr_l->data);
            if (ptr_l->data == key)
            {
                if (ptr_l->left == NULL && ptr_l->right == NULL)
                {
                    printf("\n5");
                    ptr->left = NULL;
                    free(ptr_l);
                }
                else
                {
                    printf("\nInquired node is not a leaf node : No Deletion");
                }
            }
        }
        else if (ptr_r != NULL)
        {
            if (ptr_r->data == key)
            {
                if (ptr_r->left == NULL && ptr_r->right == NULL)
                {
                    ptr->right = NULL;
                    free(ptr_r);
                }
                else
                {
                    printf("\nInquired node is not a leaf node : No Deletion");
                }
            }
        }
    }
}
void main()
{
    root_node = create_Tree();

    int response = 1, choice, element, data, node;
    do
    {
        printf("\n\nM E N U\n\n1. Insert a node to the tree\n2. Delete a node to the tree\n3. Preorder Traversal\n4. Inorder Traversal");
        printf("\n5. Postorder Traversal\n6. Exit\n\n");
    ch:
        printf("\t  -> ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            printf("Enter the number to be inserted : ");
            scanf("%d", &data);
            printf("Enter the node after which you need to insert : ");
            scanf("%d", &node);

            insert_node(root_node, data, node);
            break;

        case 2:
            printf("Enter the node which needs to be deleted : ");
            scanf("%d", &node);
            delete_node(root_node, node);
            break;

        case 3:
            preorder(root_node);
            break;

        case 4:
            inorder(root_node);
            break;

        case 5:
            postorder(root_node);
            break;

        case 6:
            exit(0);

        default:
            printf("Enter a valid Choice!!!!\n\n");
            goto ch;
        }
    } while (response == 1);
}