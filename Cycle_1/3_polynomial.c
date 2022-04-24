#include <stdio.h>
#include <math.h>

#define MAX_TERMS 30

typedef struct polynomial
{
    int coef;
    int expon;
} polynomial;

polynomial A[MAX_TERMS], B[MAX_TERMS], C[MAX_TERMS];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Add(struct polynomial A[30], struct polynomial B[30], int termsA, int termsB, struct polynomial C[30]);
void displayPoly(struct polynomial p[30], int term);

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void sort(struct polynomial C[30], int termsC)
{
    for (int i = 0; i < termsC; i++)
    {
        for (int j = i + 1; j < termsC; j++)
        {
            if (C[i].expon < C[j].expon)
            {
                swap(&C[i].expon, &C[j].expon);
                swap(&C[i].coef, &C[j].coef);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main()
{
    int termsA, termsB, termsC;

    printf("\nEnter the number of terms of the first polynomial : ");
    scanf("%d", &termsA);

    for (int i = 0; i < termsA; i++)
    {
        printf("Enter the coefficient and degree of term (%d) : ", i + 1);
        scanf("%d%d", &A[i].coef, &A[i].expon);
    }

    printf("Enter the number of terms of the second polynomial : ");
    scanf("%d", &termsB);

    for (int i = 0; i < termsB; i++)
    {
        printf("Enter the coefficient and degree of term (%d) : ", i + 1);
        scanf("%d%d", &B[i].coef, &B[i].expon);
    }

    printf("\nFirst Polynomial : \n");
    displayPoly(A, termsA);

    printf("\nSecond Polynomial : \n");
    displayPoly(B, termsB);

    termsC = Add(A, B, termsA, termsB, C);

    sort(C, termsC);

    printf("\nThe resultant polynomial : \n");
    displayPoly(C, termsC);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Add(struct polynomial A[30], struct polynomial B[30], int termsA, int termsB, struct polynomial C[30])
{
    int i = 0, j = 0, k = 0;

    while (i < termsA || j < termsB)
    {
        if (A[i].expon == B[j].expon)
        {
            C[k].coef = A[i].coef + B[j].coef;
            C[k].expon = A[i].expon;
            i++;
            j++;
            k++;
        }
        else if (A[i].expon > B[j].expon)
        {
            C[k].coef = A[i].coef;
            C[k].expon = A[i].expon;
            i++;
            k++;
        }
        else if (A[i].expon < B[j].expon)
        {
            C[k].coef = B[j].coef;
            C[k].expon = B[j].expon;
            j++;
            k++;
        }
    }
    if (j >= termsB)
    {
        while (i < termsA)
        {
            C[k].coef = A[i].coef;
            C[k].expon = A[i].expon;
            i++;
            k++;
        }
    }
    if (i >= termsA)
    {
        while (j < termsB)
        {
            C[k].coef = B[j].coef;
            C[k].expon = B[j].expon;
            j++;
            k++;
        }
    }
    return (k);
}

void displayPoly(struct polynomial p[30], int term)
{
    for (int i = 0; i < term - 1; i++)
    {
        printf("%d(x^%d) + ", p[i].coef, p[i].expon);
    }
    printf("%d(x^%d)", p[term - 1].coef, p[term - 1].expon);
}