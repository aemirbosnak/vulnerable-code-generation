//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct Expense
{
    char name[50];
    int amount;
    struct Expense* next;
} Expense;

Expense* createExpense(char* name, int amount)
{
    Expense* newExpense = malloc(sizeof(Expense));

    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    return newExpense;
}

void addExpense(Expense* head, char* name, int amount)
{
    Expense* newExpense = createExpense(name, amount);

    if (head == NULL)
    {
        head = newExpense;
    }
    else
    {
        head->next = newExpense;
    }
}

int main()
{
    Expense* head = NULL;

    addExpense(head, "Groceries", 50);
    addExpense(head, "Rent", 1000);
    addExpense(head, "Dining", 200);

    printf("Expenses:");
    for (Expense* currentExpense = head; currentExpense; currentExpense = currentExpense->next)
    {
        printf("\n%s: %d", currentExpense->name, currentExpense->amount);
    }

    return 0;
}