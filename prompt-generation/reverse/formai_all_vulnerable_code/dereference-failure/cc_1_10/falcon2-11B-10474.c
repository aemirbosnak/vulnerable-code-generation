//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense
{
    char name[50];
    double amount;
    struct Expense *next;
};

struct Expense *head = NULL;

void addExpense(char *name, double amount)
{
    struct Expense *newExpense = (struct Expense *)malloc(sizeof(struct Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL)
    {
        head = newExpense;
    }
    else
    {
        struct Expense *current = head;
        while (current->next!= NULL)
        {
            current = current->next;
        }
        current->next = newExpense;
    }
}

void printExpenses()
{
    struct Expense *current = head;
    while (current!= NULL)
    {
        printf("%s: $%.2f\n", current->name, current->amount);
        current = current->next;
    }
}

int main()
{
    addExpense("Groceries", 50.00);
    addExpense("Rent", 800.00);
    addExpense("Utilities", 100.00);

    printExpenses();

    return 0;
}