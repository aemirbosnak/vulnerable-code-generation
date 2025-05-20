//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct Expense
{
    char *name;
    int amount;
    struct Expense *next;
} Expense;

void addExpense(Expense **head, char *name, int amount)
{
    Expense *newExpense = malloc(sizeof(Expense));
    newExpense->name = name;
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
    Expense *head = NULL;

    addExpense(&head, "Coffee", 5);
    addExpense(&head, "Pizza", 10);
    addExpense(&head, "Groceries", 20);
    addExpense(&head, "Video games", 30);
    addExpense(&head, "Alcohol", 40);

    printf("Total expenses: $");
    int totalExpense = 0;
    for (Expense *currentExpense = head; currentExpense; currentExpense = currentExpense->next)
    {
        printf("%s ($%d) ", currentExpense->name, currentExpense->amount);
        totalExpense += currentExpense->amount;
    }

    printf("\nTotal expenses: $%d\n", totalExpense);

    return 0;
}