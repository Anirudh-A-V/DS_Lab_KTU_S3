// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define N 20

// // Graph Object
// struct Graph
// {
//     // Array of pointer to nodes of Adjacency list
//     struct node *head[N];
// };

// // node Data structure
// struct node
// {
//     int dest;
//     struct node *next;
// };

// // Edge between two nodes
// struct edge
// {
//     int src, dest;
// };

// // Function to create an adjacency list from an array of edges
// struct Graph *create_Graph(struct edge edges[], int n)
// {
//     // Allocating memory for the graph
//     struct Graph *graph = malloc(sizeof(struct Graph));

//     // Intialising all pointers in the Graph
//     for (int i = 0; i < N; i++)
//         graph->head[i] = NULL;

//     // adding edges to the digraph one by one
//     for (int i = 0; i < n; i++)
//     {
//         // getting source and destination
//         int src = edges[i].src, dest = edges[i].dest;

//         // allocate a new nde of adjacency list
//         struct node *new_node = malloc(sizeof(struct node));
//         new_node->dest = dest;

//         // point the new node to the current head node
//         new_node->next = graph->head[src];

//         // point header pointer to new node
//         graph->head[src] = new_node;
//     }
//     return graph;
// }

// void print_Graph(struct Graph *graph, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         struct node *ptr = graph->head[i];
//         while (ptr != NULL)
//         {
//             printf("( %d -> %d ) ", i + 1, ptr->dest);
//             ptr = ptr->next;
//         }
//         printf("\n");
//     }
// }

// void setMatrix(int arr[][100], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             arr[i][j] = 0;
//         }
//     }
// }

// void main()
// {
//     int n;
//     printf("Enter the number of nodes in the graph : ");
//     scanf("%d", &n);
//     // int adj[n][n];
//     // setMatrix(adj, n);
//     int count = 0;
//     struct edge edges[50];
//     for (int i = 0; i < n; i++)
//     {
//         int ad;
//         printf("Enter the no. of adjacent vertices of %d : ", i + 1);
//         scanf("%d", &ad);

//         count += ad;

//         for (int j = 0; j < ad; j++)
//         {
//             printf("Enter the %dth neighbour", j + 1);
//             scanf("%d", edges[i].dest);
//             edges[i].src = i;
//         }
//     }

//     struct Graph *graph = create_Graph(edges, count);

//     int response = 1, choice, element, data, node;
//     do
//     {
//         printf("\n\nM E N U\n\n1. Adajcency Matrix Representation\n2. Linked Representation\n3. Depth First Search\n4. Breadth First Search");
//         printf("\n5. Exit\n\n");
//     ch:
//         printf("\t  -> ");
//         scanf("%d", &choice);
//         printf("\n\n");
//         switch (choice)
//         {
//         case 1:
//             printf("Adjacency Matrix\n");
//             // DisplayMatrix(n);
//             break;

//         case 2:
//             printf("Linked Representation\n");
//             print_Graph(graph, n);
//             break;

//         case 3:
//             printf("Depth First Search\n");
//             // DFS(header, n);
//             break;

//         case 4:
//             printf("Breadth First Search\n");
//             // BFS(header, n);
//             break;

//         case 5:
//             exit(0);

//         default:
//             printf("Enter a valid Choice!!!!\n\n");
//             goto ch;
//         }
//     } while (response == 1);
// }

#include <stdio.h>
#include <stdlib.h>

struct AdjList
{
    struct NodeGraph *dest;
    struct AdjList *link;
};

struct NodeGraph
{
    int value;
    struct NodeGraph *next;
    struct AdjList *adj;
};

int arr[100];
int AdjMatrix[100][100];

// Functions to implement a graph

struct AdjList *get_AdjList()
{
    struct AdjList *new = malloc(sizeof(struct AdjList));
    new->dest = NULL;
    new->link = NULL;
    return new;
}

struct NodeGraph *get_NodeGraph()
{
    struct NodeGraph *new = malloc(sizeof(struct NodeGraph));
    // new->value = 0;
    new->adj = NULL;
    new->next = NULL;
    return new;
}

struct NodeGraph *search_link(struct NodeGraph *header, int n)
{
    struct NodeGraph *ptr = header;
    while (ptr != NULL)
    {
        if (ptr->value == n)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

struct NodeGraph *create_Graph(int n)
{
    int a, data;
    struct NodeGraph *header = get_NodeGraph();
    struct NodeGraph *currNodeGraph = get_NodeGraph();
    header->next = currNodeGraph;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            struct NodeGraph *newnode = get_NodeGraph();
            currNodeGraph->next = newnode;
            currNodeGraph = newnode;
        }

        printf("Enter the data in the %dth vertex : ", i + 1);
        scanf("%d", &arr[i]);
        currNodeGraph->value = arr[i];
    }
    currNodeGraph = header->next;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the number of links of vertex %d : ", arr[i]);
        scanf("%d", &a);
        struct AdjList *AdjHeader = get_AdjList();
        struct AdjList *currAdjList = AdjHeader;

        if (a == 0)
        {
            AdjHeader = NULL;
        }
        else
        {
            printf("Enter the links : ");
        }
        for (int j = 0; j < a; j++)
        {
            if (j != 0)
            {
                struct AdjList *newnode = get_AdjList();
                currAdjList->link = newnode;
                currAdjList = newnode;
            }

            scanf("%d", &data);
            currAdjList->dest = search_link(header, data);

            /* Code for calling Update matrix */
        }

        currNodeGraph->adj = currAdjList;
        currNodeGraph = currNodeGraph->next;
    }
    return header;
}

void print_Graph(struct NodeGraph *header)
{

    header = header->next;

    while (header != NULL)
    {
        struct AdjList *adj = get_AdjList();
        adj = header->adj;

        printf("%d : ", header->value);

        if (header->adj != NULL)
        {
            while (adj != NULL)
            {
                printf("%d ", (adj->dest)->value);
                adj = adj->link;
            }
        }

        printf("\n");
        header = header->next;
    }
}

int main()
{
    int n;
    printf("Enter the no. of nodes of the graph : ");
    scanf("%d", &n);
    struct NodeGraph *header = create_Graph(n);
    print_Graph(header);
    return 0;
}
