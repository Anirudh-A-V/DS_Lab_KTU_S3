#include <stdio.h>

#define MAX_TERMS 30

typedef struct tuple
{
    int row;
    int column;
    int value;
} tuple;

tuple A[MAX_TERMS], B[MAX_TERMS], C[MAX_TERMS];

void sort_tuple(struct tuple tuple_form[], int n, int no_of_elements)
{
    struct tuple temp;
    for (int i = 0; i < no_of_elements; i++)
    {
        for (int j = i + 1; j < no_of_elements; j++)
        {
            if (n == 1)
            {
                if (tuple_form[i].row > tuple_form[j].row)
                {
                    temp = tuple_form[i];
                    tuple_form[i] = tuple_form[j];
                    tuple_form[j] = temp;
                }
                else if ((tuple_form[i].row == tuple_form[j].row) && (tuple_form[i].column > tuple_form[j].column))
                {
                    temp = tuple_form[i];
                    tuple_form[i] = tuple_form[j];
                    tuple_form[j] = temp;
                }
            }
            if (n == 2)
            {
                if (tuple_form[i].column > tuple_form[j].column)
                {
                    temp = tuple_form[i];
                    tuple_form[i] = tuple_form[j];
                    tuple_form[j] = temp;
                }
                else if ((tuple_form[i].column == tuple_form[j].column) && (tuple_form[i].row > tuple_form[j].row))
                {
                    temp = tuple_form[i];
                    tuple_form[i] = tuple_form[j];
                    tuple_form[j] = temp;
                }
            }
        }
    }
}

void Display_matrix(int matrix[][20], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void Read_matrix(int matrix[][20], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int Conversion(int matrix[][20], int row, int col, struct tuple tuple_form[])
{
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                tuple_form[k].row = i;
                tuple_form[k].column = j;
                tuple_form[k].value = matrix[i][j];
                k++;
            }
        }
    }
    return k;
}

void display_tuple(struct tuple tuple_form[], int no_of_elements, int row, int column)
{
    sort_tuple(tuple_form, 1, no_of_elements);
    printf("(\trow \tcol \tval )\n");
    printf("( \t %d \t %d \t %d )\n\n", row, column, no_of_elements);
    for (int i = 0; i < no_of_elements; i++)
    {
        if (tuple_form[i].value != 0)
        {
            printf("( \t %d \t %d \t %d )\n", tuple_form[i].row, tuple_form[i].column, tuple_form[i].value);
        }
    }
}

void Transpose(struct tuple tuple_form[], int no_of_elements, int row, int column)
{
    sort_tuple(tuple_form, 2, no_of_elements);
    printf("(\trow \tcol \tval )\n");
    printf("( \t %d \t %d \t %d )\n\n", column, row, no_of_elements);
    for (int i = 0; i < no_of_elements; i++)
    {
        printf("( \t %d \t %d \t %d )\n", tuple_form[i].column, tuple_form[i].row, tuple_form[i].value);
    }
    printf("\n");
}

int Add(struct tuple A[], int TupleA, struct tuple B[], int TupleB, struct tuple C[])
{
    int i = 0, j = 0, k = 0;
    sort_tuple(A, 1, TupleA);
    sort_tuple(B, 1, TupleB);

    while (i < TupleA && j < TupleB)
    {
        if (A[i].row == B[j].row && A[i].column == B[j].column)
        {
            C[k].value = A[i].value + B[j].value;
            C[k].row = A[i].row;
            C[k].column = A[i].column;
            i++;
            j++;
            k++;
        }
        else if ((A[i].row < B[j].row) || (A[i].row == B[j].row && A[i].column < B[j].column))
        {
            C[k].value = A[i].value;
            C[k].row = A[i].row;
            C[k].column = A[i].column;
            i++;
            k++;
        }
        else if ((A[i].row > B[j].row) || (A[i].row == B[j].row && A[i].column > B[j].column))
        {
            C[k].value = B[j].value;
            C[k].row = B[j].row;
            C[k].column = B[j].column;
            j++;
            k++;
        }
    }
    if (j >= TupleB)
    {
        while (i < TupleA)
        {
            C[k].value = A[i].value;
            C[k].row = A[i].row;
            C[k].column = A[i].column;
            i++;
            k++;
        }
    }
    if (i >= TupleA)
    {
        while (j < TupleB)
        {
            C[k].value = B[j].value;
            C[k].row = B[j].row;
            C[k].column = B[j].column;
            j++;
            k++;
        }
    }
    return (k);
}

void main()
{
    int m1, m2, n1, n2, tupleA, tupleB, tupleC;

    printf("Enter the order of first matrix (mxn) : ");
    scanf("%d%d", &m1, &n1);
    printf("Enter the order of second matrix (mxn) : ");
    scanf("%d%d", &m2, &n2);

    int matrixA[10][20], matrixB[10][20];

    printf("\nEnter the first matrix : ");
    Read_matrix(matrixA, m1, n1);

    printf("\nEnter the second matrix : ");
    Read_matrix(matrixB, m2, n2);

    printf("\nMatrix A : \n");
    Display_matrix(matrixA, m1, n1);

    printf("\nMatrix B : \n");
    Display_matrix(matrixB, m2, n2);

    int response, choice;
    do
    {
        printf("\n\n\tM E N U\n\n");
        printf("1. Convert the normal matrix into tuple form\n2. Find the transpose of two matrices\n3. Add the two matrices\n\n");
    ch:
        printf("\t->");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            tupleA = Conversion(matrixA, m1, n1, A);
            tupleB = Conversion(matrixB, m2, n2, B);
            printf("\nMatrix A : \n");
            display_tuple(A, tupleA, m1, n1);
            printf("\nMatrix B : \n");
            display_tuple(B, tupleB, m2, n2);
            break;

        case 2:
            printf("\nTranspose of Matrix A : \n");
            Transpose(A, tupleA, m1, n1);
            printf("\nTransponse of Matrix B : \n");
            Transpose(B, tupleB, m2, n2);
            break;

        case 3:
            if (m1 == m2 && n1 == n2)
            {
                tupleC = Add(A, tupleA, B, tupleB, C);
                display_tuple(C, tupleC, m1, n1);
            }
            else
            {
                printf("\nIncompatible Matrices!!!\n\n");
            }
            break;

        default:
            printf("\nEnter a valid option!!!\n");
            goto ch;
        }

        printf("\nDo you want to continue(1 or 0) : ");
        scanf("%d", &response);

    } while (response == 1);
}