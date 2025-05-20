//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VARIABLE_NUMBER 10

typedef struct Variable
{
    char name[20];
    double value;
    struct Variable* next;
} Variable;

Variable* insertVariable(Variable* head, char* name, double value)
{
    Variable* newVariable = (Variable*)malloc(sizeof(Variable));
    strcpy(newVariable->name, name);
    newVariable->value = value;
    newVariable->next = NULL;

    if (head == NULL)
    {
        head = newVariable;
    }
    else
    {
        head->next = newVariable;
    }

    return head;
}

void printVariables(Variable* head)
{
    Variable* currentVariable = head;

    while (currentVariable)
    {
        printf("%s: %.2lf\n", currentVariable->name, currentVariable->value);
        currentVariable = currentVariable->next;
    }
}

int main()
{
    Variable* variables = NULL;

    insertVariable(variables, "a", 10.0);
    insertVariable(variables, "b", 20.0);
    insertVariable(variables, "c", 30.0);

    printVariables(variables);

    return 0;
}