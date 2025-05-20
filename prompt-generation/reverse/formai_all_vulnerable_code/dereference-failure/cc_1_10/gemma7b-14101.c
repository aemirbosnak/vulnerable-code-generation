//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE 10

typedef struct Expense
{
    char name[50];
    int amount;
    struct Expense* next;
} Expense;

void insertExpense(Expense** head, char* name, int amount)
{
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (*head == NULL)
    {
        *head = newExpense;
    }
    else
    {
        (*head)->next = newExpense;
    }
}

void printExpenses(Expense* head)
{
    while (head)
    {
        printf("%s - %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    Expense* head = NULL;

    insertExpense(&head, "Groceries", 50);
    insertExpense(&head, "Electronics", 200);
    insertExpense(&head, "Clothing", 75);
    insertExpense(&head, "Dining", 125);

    printExpenses(head);

    return 0;
}