#include <stdio.h>
#include <stdlib.h>

void add_matrix(int *p, int *q, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        printf("\t");
        for (int j = 0; j < column; j++)
        {
            printf("%d ", *(p + i * row + j) + *(q + i * row + j));
        }
        printf("\n");
    }
    printf("\n\n");
}

void Multiply_matrix(int *p, int *q, int n, int m, int l)
{
    int sum;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            sum = 0;
            for (int k = 0; k < l; k++)
            {
                sum += *(p + row * l + k) * *(q + k * m + col);
            }
            printf("%d ", sum);
        }
    }
    printf("\n\n");
}

void Transpose(int *p, int row, int column)
{
    for (int i = 0; i < column; i++)
    {
        printf("\t");
        for (int j = 0; j < row; j++)
        {
            printf("%d ", *(p + column * j + i));
        }
        printf(("\n"));
    }
    printf("\n\n");
}

void upper_triangular(int *q, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (j >= i)
            {
                printf("%d  ", *(q + i * column + j));
            }
        }
    }
    printf("\n\n");
}

void Diagonal(int *p, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == j)
            {
                printf("%d  ", *(p + i * column + j));
            }
        }
    }
    printf("\n\n");
}

void main()
{
    int *p, *q;
    int n1, n2, m1, m2, choice;
    int response;

    // Inputing order of the matrix
    printf("Enter the order of matrix A : ");
    scanf("%d%d", &n1, &n2);

    printf("Enter the order of matrix B : ");
    scanf("%d%d", &m1, &m2);

    int ele1 = n1 * n2;
    int ele2 = m1 * m2;

    // Allocating memory using malloc
    p = (int *)malloc(ele1 * sizeof(int));
    if (p == NULL)
    {
        printf("Error!!! memory not allocated.");
        exit(0);
    }

    q = (int *)malloc(ele2 * sizeof(int));
    if (q == NULL)
    {
        printf("Error!!! memory not allocated.");
        exit(0);
    }

    // Inputting elements of each matrix
    printf("Enter the elements of matrix A : \n");
    for (int i = 0; i < ele1; i++)
    {
        scanf("%d", p + i);
    }

    printf("Enter the elements of matrix B : \n");
    for (int i = 0; i < ele2; i++)
    {
        scanf("%d", q + i);
    }

    // Menu Driven functionalities
    do
    {

        printf("\n\n\t M E N U\n\n");
        printf("1. Add A and B\n2. Multiply A and B\n3. Print transpose of A\n4. Print upper triangular elements of B\n5. Print diagonal elements of A\n\n");
        printf("\t->");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            if (n1 == m1 && n2 == m2)
            {
                printf("The sum of A and B :\n\n");
                add_matrix(p, q, n1, n2);
            }
            else
            {
                printf("Addition of matrices of different order is  not possible!\n\n");
            }
            break;

        case 2:
            if (n2 == m1)
            {
                Multiply_matrix(p, q, n1, m2, n2);
            }
            else
            {
                printf("Multiplication of given matrices are not possible!\n\n");
            }
            break;

        case 3:
            printf("The transpose of matrix A is :\n\n");
            Transpose(p, n1, n2);
            break;

        case 4:
            if (m1 == m2)
            {
                printf("The upper triangular elements of B are : \n");
                upper_triangular(q, m1, m2);
            }
            else
            {
                printf("The matrix is not a square matrix!\n\n");
            }
            break;

        case 5:
            if (n1 == n2)
            {
                printf("The diagonal elements of A are : ");
                Diagonal(p, n1, n2);
            }
            else
            {
                printf("The matrix is not a square matrix!\n\n");
            }
            break;

        default:
            break;
        }

        printf("Do you want to continue( 1 or 0 ) : ");
        scanf("%d", &response);

    } while (response == 1);
    free(p);
    free(q);
}