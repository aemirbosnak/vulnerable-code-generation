//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Calculator
{
    char operator;
    double number;
    struct Calculator* next;
} Calculator;

void insert(Calculator**, double num, char op);
double calculate(Calculator*);

int main()
{
    Calculator* head = NULL;
    char input[MAX];
    double num;

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            num = calculate(head);
            insert(head, num, input[i]);
        }
    }

    num = calculate(head);
    printf("The result is: %.2lf\n", num);

    return 0;
}

void insert(Calculator** head, double num, char op)
{
    Calculator* newNode = malloc(sizeof(Calculator));
    newNode->operator = op;
    newNode->number = num;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

double calculate(Calculator* head)
{
    double result = head->number;

    while (head->next)
    {
        switch (head->operator)
        {
            case '+':
                result += head->next->number;
                break;
            case '-':
                result -= head->next->number;
                break;
            case '*':
                result *= head->next->number;
                break;
            case '/':
                result /= head->next->number;
                break;
        }

        head = head->next;
    }

    return result;
}