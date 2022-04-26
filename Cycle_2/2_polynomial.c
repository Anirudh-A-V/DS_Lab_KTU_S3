#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct polynomial
{
    int degree;
    int coefficient;
    struct polynomial *link;
};

struct polynomial *add_term(struct polynomial *poly, int degree, int cofficient)
{
    struct polynomial *temp = malloc(sizeof(struct polynomial));
    temp->coefficient = cofficient;
    temp->degree = degree;
    temp->link = NULL;
    if (poly == NULL)
    {
        poly = temp;
    }
    else
    {
        struct polynomial *head = poly;
        while (head->link != NULL)
        {
            head = head->link;
        }
        head->link = temp;
    }
    return poly;
}

struct polynomial *add_poly(struct polynomial *polyA, struct polynomial *polyB, struct polynomial *sum)
{
    while (polyA != NULL && polyB != NULL)
    {
        if (polyA->degree < polyB->degree)
        {
            sum = add_term(sum, polyA->degree, polyA->coefficient);
            polyA = polyA->link;
            if (polyA == NULL)
            {
                break;
            }
        }
        if (polyA->degree > polyB->degree)
        {
            sum = add_term(sum, polyB->degree, polyB->coefficient);
            polyB = polyB->link;
            if (polyB == NULL)
            {
                break;
            }
        }
        if (polyA->degree = polyB->degree)
        {
            sum = add_term(sum, polyB->degree, (polyB->coefficient + polyA->coefficient));
            polyA = polyA->link;
            polyB = polyB->link;
            if (polyA == NULL || polyB == NULL)
            {
                break;
            }
        }
    }
    while (polyA != NULL)
    {
        sum = add_term(sum, polyA->degree, polyA->coefficient);
        polyA = polyA->link;
    }
    while (polyB != NULL)
    {
        sum = add_term(sum, polyB->degree, polyB->coefficient);
        polyB = polyB->link;
    }

    return sum;
}

struct polynomial *mult_poly(struct polynomial *polyA, struct polynomial *polyB, struct polynomial *prod)
{
    struct polynomial *product = prod;
    while (polyA != NULL)
    {
        while (polyB != NULL)
        {
            struct polynomial *ptr1, *temp = malloc(sizeof(struct polynomial));
            temp->degree = polyA->degree + polyB->degree;
            temp->coefficient = polyA->coefficient * polyB->coefficient;
            temp->link = NULL;
            if (product == NULL)
            {
                product = temp;
                continue;
            }
            
            while (product != NULL)
            {
                ptr1 = product;
                if (product->degree < temp->degree && product->link != NULL)
                {
                    product = product->link;
                    continue;
                }
                else if (product->degree < temp->degree)
                {
                    temp = product->link;
                    product->link = temp;
                    break;
                }
                else if (product->degree == temp->degree)
                {
                    product->coefficient = product->coefficient + temp->coefficient;
                    free(temp);
                    break;
                }
                product = product->link;
            }
            polyB = polyB->link;
        }
        polyA = polyA->link;
    }
    // product = prod;
    return prod;
}

void traversal(struct polynomial *poly)
{
    struct polynomial *head = poly;
    if (poly == NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
        while (head->link != NULL)
        {
            printf("%dX^%d + ", head->coefficient, head->degree);
            head = head->link;
        }
        printf("%dX^%d\n", head->coefficient, head->degree);
    }
}

void main()
{
    struct polynomial *startA = NULL, *startB = NULL, *sum = NULL, *product = NULL;
    int terms, deg, coef;

    printf("\nEnter the number of terms of first polynomial : ");
    scanf("%d", &terms);
    printf("\n");

    for (int i = 0; i < terms; i++)
    {
        printf("Enter the coefficient and degree of the %dth term : ", i + 1);
        scanf("%d%d", &coef, &deg);
        startA = add_term(startA, deg, coef);
    }

    printf("\nEnter the number of terms of second polynomial : ");
    scanf("%d", &terms);
    printf("\n");

    for (int i = 0; i < terms; i++)
    {
        printf("Enter the coefficient and degree of the %dth term : ", i + 1);
        scanf("%d%d", &coef, &deg);
        startB = add_term(startB, deg, coef);
    }

    printf("\nPolynomial A : ");
    traversal(startA);
    printf("Polynomial B : ");
    traversal(startB);

    sum = add_poly(startA, startB, sum);

    printf("\nSum of two polynomials : ");
    traversal(sum);

    product = mult_poly(startA, startB, product);

    printf("\nProduct of two polynomials : ");
    traversal(product);
}
