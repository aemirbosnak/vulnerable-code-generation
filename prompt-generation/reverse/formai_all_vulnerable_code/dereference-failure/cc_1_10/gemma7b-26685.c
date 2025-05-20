//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct Expense
{
    char name[50];
    int amount;
    struct Expense* next;
} Expense;

void addExpense(Expense** head, char* name, int amount)
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

int main()
{
    Expense* head = NULL;

    addExpense(&head, "Groceries", 50);
    addExpense(&head, "Electronics", 200);
    addExpense(&head, "Clothing", 25);
    addExpense(&head, "Dining", 10);

    int totalAmount = 0;
    Expense* currentExpense = head;

    while (currentExpense)
    {
        totalAmount += currentExpense->amount;
        printf("%s: %d\n", currentExpense->name, currentExpense->amount);
        currentExpense = currentExpense->next;
    }

    printf("Total expenses: %d\n", totalAmount);
    printf("Average expense: %.2f\n", (float)totalAmount / MAX_EXPENSES);

    return 0;
}