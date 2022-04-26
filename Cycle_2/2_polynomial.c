#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct polynomial
{
    int degree;
    int coefficient;
    struct polynomial *link;
};

struct polynomial *add_term(struct polynomial *poly, int degree, int cofficient){
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

struct polynomial *add_poly(struct polynomial *polyA, struct polynomial *polyB){
    
}
void main(){
    struct polynomial *startA=NULL, *startB=NULL, *sum=NULL, *product=NULL;
    int terms, deg, coef;

    printf("Enter the number of terms of first polynomial : ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++)
    {
        printf("Enter the coefficient and degree of the %dth term : ", i+1);
        scanf("%d%d", &coef, &deg);
        startA = add_term(startA,deg,coef);
    }

    printf("Enter the number of terms of second polynomial : ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++)
    {
        printf("Enter the coefficient and degree of the %dth term : ", i+1);
        scanf("%d%d", &coef, &deg);
        startB = add_term(startB,deg,coef);
    }


}
