//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Expense
{
    char name[50];
    float amount;
    struct Expense* next;
} Expense;

void addExpense(Expense* head, char* name, float amount)
{
    Expense* newExpense = malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL)
    {
        head = newExpense;
    }
    else
    {
        head->next = newExpense;
    }
}

void printExpenses(Expense* head)
{
    while (head)
    {
        printf("%s: %.2f\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    Expense* head = NULL;

    addExpense(head, "Groceries", 50.0);
    addExpense(head, "Clothing", 20.0);
    addExpense(head, "Electronics", 100.0);
    addExpense(head, "Eating out", 30.0);

    printExpenses(head);

    return 0;
}