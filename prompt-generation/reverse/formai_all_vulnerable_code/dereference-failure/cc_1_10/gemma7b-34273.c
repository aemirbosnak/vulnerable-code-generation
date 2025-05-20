//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct Expense
{
    char name[50];
    int amount;
    char category[50];
    struct Expense* next;
} Expense;

void insertExpense(Expense** head, char* name, int amount, char* category)
{
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    strcpy(newExpense->category, category);
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
        printf("%s - %d - %s\n", head->name, head->amount, head->category);
        head = head->next;
    }
}

int main()
{
    Expense* head = NULL;

    insertExpense(&head, "Groceries", 50, "Food");
    insertExpense(&head, "Clothing", 20, "Fashion");
    insertExpense(&head, "Electronics", 100, "Technology");
    insertExpense(&head, "Dining out", 30, "Entertainment");

    printExpenses(head);

    return 0;
}