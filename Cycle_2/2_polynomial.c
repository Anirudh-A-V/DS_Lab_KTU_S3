#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct polynomial
{
    int degree;
    int coefficient;
    struct polynomial *link;
};

// Function to create a new node
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

// function to add two polynomials
struct polynomial *add_poly(struct polynomial *poly1, struct polynomial *poly2)
{
    struct polynomial *poly3 = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->degree == poly2->degree)
        {
            poly3 = add_term(poly3, poly1->degree, poly1->coefficient + poly2->coefficient);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        else if (poly1->degree > poly2->degree)
        {
            poly3 = add_term(poly3, poly1->degree, poly1->coefficient);
            poly1 = poly1->link;
        }
        else
        {
            poly3 = add_term(poly3, poly2->degree, poly2->coefficient);
            poly2 = poly2->link;
        }
    }
    while (poly1 != NULL)
    {
        poly3 = add_term(poly3, poly1->degree, poly1->coefficient);
        poly1 = poly1->link;
    }
    while (poly2 != NULL)
    {
        poly3 = add_term(poly3, poly2->degree, poly2->coefficient);
        poly2 = poly2->link;
    }
    return poly3;
}

// function to multiply two polynomials
struct polynomial *multiply_poly(struct polynomial *poly1, struct polynomial *poly2)
{
    struct polynomial *poly3 = NULL;
    while (poly1 != NULL)
    {
        struct polynomial *temp = poly2;
        while (temp != NULL)
        {
            poly3 = add_term(poly3, poly1->degree + temp->degree, poly1->coefficient * temp->coefficient);
            temp = temp->link;
        }
        poly1 = poly1->link;
    }
    return poly3;
}

void display_poly(struct polynomial *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->degree);
        if (poly->link != NULL)
        {
            printf(" + ");
        }
        poly = poly->link;
    }
    printf("");
}

int main()
{
    struct polynomial *polyA = NULL;
    struct polynomial *polyB = NULL;
    struct polynomial *sum = NULL;
    struct polynomial *product = NULL;
    int degree, coefficient;

    // polyA = add_term(polyA, 2, 3);
    // polyA = add_term(polyA, 1, 2);
    // polyA = add_term(polyA, 0, 1);

    // polyB = add_term(polyB, 2, 2);
    // polyB = add_term(polyB, 1, 1);
    // polyB = add_term(polyB, 0, 1);

    // Take user input for polynomial A
    printf("Enter the polynomial A: ");
    while (true)
    {
        printf("Enter the degree of the term: ");
        scanf("%d", &degree);
        if (degree < 0)
        {
            break;
        }
        printf("Enter the coefficient of the term: ");
        scanf("%d", &coefficient);
        polyA = add_term(polyA, degree, coefficient);
    }

    // Take user input for polynomial A
    printf("Enter the polynomial B: ");
    while (true)
    {
        printf("Enter the degree of the term: ");
        scanf("%d", &degree);
        if (degree < 0)
        {
            break;
        }
        printf("Enter the coefficient of the term: ");
        scanf("%d", &coefficient);
        polyA = add_term(polyB, degree, coefficient);
    }

    // Display the polynomials
    printf("\nPolynomial A: ");
    display_poly(polyA);
    printf("\nPolynomial B: ");
    display_poly(polyB);

    // Add the polynomials
    sum = add_poly(polyA, polyB);
    printf("\n\nSum: ");
    display_poly(sum);

    // Multiply the polynomials
    product = multiply_poly(polyA, polyB);
    printf("\n\nProduct: ");
    display_poly(product);

    return 0;
}