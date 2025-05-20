//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct Expense
{
    char name[50];
    double amount;
    char category[50];
    struct Expense* next;
} Expense;

Expense* insertExpense(Expense* head, char* name, double amount, char* category)
{
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    strcpy(newExpense->category, category);
    newExpense->next = NULL;

    if (head == NULL)
    {
        head = newExpense;
    }
    else
    {
        head->next = newExpense;
    }

    return head;
}

void printExpenses(Expense* head)
{
    while (head)
    {
        printf("%s: %.2lf - %s\n", head->name, head->amount, head->category);
        head = head->next;
    }
}

int main()
{
    Expense* head = NULL;

    insertExpense(head, "Groceries", 50.0, "Food");
    insertExpense(head, "Dining out", 25.0, "Entertainment");
    insertExpense(head, "Clothing", 10.0, "Shopping");

    printExpenses(head);

    return 0;
}