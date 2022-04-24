#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item)
{
    if (top >= SIZE - 1)
    {
        printf("\nStack Overflow.\n");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

char pop()
{
    char item;

    if (top < 0)
    {
        printf("stack under flow: invalid infix expression");
        getchar();
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item, x;

    push('(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    item = infix_exp[i];

    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        putchar(item);
        exit(1);
    }
    postfix_exp[j] = '\0';
}

int calculation(int a, int b, char O)
{
    int mult = 1;
    if (O == '+')
    {
        return a + b;
    }
    else if (O == '-')
    {
        return a - b;
    }
    else if (O == '*')
    {
        return a * b;
    }
    else if (O == '/' && b != 0)
    {
        return a / b;
    }
    else if (O == '^')
    {
        for (int i = 1; i <= b; i++)
        {
            mult = a * mult;
        }
        return mult;
    }
}
int evaluation(char postfix_exp[])
{
    char a;
    int i = 0, result;
    do
    {
        if (isdigit(postfix_exp[i]))
        {
            push(postfix_exp[i]);
        }
        else if (is_operator(postfix_exp[i]))
        {
            a = pop();
            push(calculation(pop() - '0', a - '0', postfix_exp[i]) + '0');
        }
        else if (isalpha(postfix_exp[i]))
        {
            printf("The expression contains a variable!!!");
            getchar();
            exit(1);
        }
        else
        {
            printf("\nInvalid Expression!!!\n\n");
            getchar();
            exit(1);
        }
        i++;
    } while (postfix_exp[i] != '\0');
    return pop();
}

int main()
{
    char infix[SIZE], postfix[SIZE];

    printf("\nEnter Infix expression : ");
    gets(infix);

    // InfixToPostfix(infix, postfix);
    // printf("Postfix Expression: ");
    // puts(postfix);
    // printf("The postfix expression equates to %c\n", evaluation(postfix));

    int response, choice, element;
    do
    {
        printf("\n\nM E N U\n\n1. Convert the Infix Expression into Postfix\n2. Evaluate the postfix expression\n3. Exit\n\n");
    ch:
        printf("\t  -> ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            InfixToPostfix(infix, postfix);
            printf("\nPostfix Expression: ");
            puts(postfix);
            break;

        case 2:
            printf("\nThe postfix expression equates to %c\n", evaluation(postfix));
            break;

        case 3:
            exit(0);

        default:
            printf("Enter a valid Choice!!!!\n\n");
            goto ch;
        }
        printf("\nDo you want to continue (1 or 0) : ");
        scanf("%d", &response);
    } while (response == 1);

    return 0;
}