//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Transaction
{
    char name[50];
    int amount;
    char type[20];
    struct Transaction* next;
};

struct Budget
{
    char category[50];
    int target;
    struct Budget* next;
    struct Transaction* transactions;
};

void addTransaction(struct Budget* budget, int amount, char* type, char* name)
{
    struct Transaction* newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));

    strcpy(newTransaction->name, name);
    newTransaction->amount = amount;
    strcpy(newTransaction->type, type);

    if (budget->transactions == NULL)
    {
        budget->transactions = newTransaction;
    }
    else
    {
        budget->transactions->next = newTransaction;
    }
}

void addBudget(struct Budget* budget, char* category, int target)
{
    struct Budget* newBudget = (struct Budget*)malloc(sizeof(struct Budget));

    strcpy(newBudget->category, category);
    newBudget->target = target;

    if (budget == NULL)
    {
        budget = newBudget;
    }
    else
    {
        budget->next = newBudget;
    }
}

int main()
{
    struct Budget* budget = NULL;
    addBudget(&budget, "Groceries", 200);
    addBudget(&budget, "Eating Out", 150);
    addBudget(&budget, "Transportation", 50);

    addTransaction(budget, 25, "Expense", "Groceries");
    addTransaction(budget, 50, "Income", "Salary");
    addTransaction(budget, 30, "Expense", "Eating Out");

    int totalSpending = 0;
    for (struct Budget* currentBudget = budget; currentBudget != NULL; currentBudget = currentBudget->next)
    {
        for (struct Transaction* currentTransaction = currentBudget->transactions; currentTransaction != NULL; currentTransaction = currentTransaction->next)
        {
            totalSpending += currentTransaction->amount;
        }
    }

    printf("Total spending: $%d\n", totalSpending);

    return 0;
}