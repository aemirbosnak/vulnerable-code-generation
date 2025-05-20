//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct BudgetItem
{
    char name[MAX_NAME_LENGTH];
    double amount;
    struct BudgetItem* next;
} BudgetItem;

void insertBudgetItem(BudgetItem* head, char* name, double amount)
{
    BudgetItem* newNode = malloc(sizeof(BudgetItem));
    strcpy(newNode->name, name);
    newNode->amount = amount;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }
}

double calculateTotalBudget(BudgetItem* head)
{
    double total = 0.0;
    BudgetItem* currentItem = head;

    while (currentItem)
    {
        total += currentItem->amount;
        currentItem = currentItem->next;
    }

    return total;
}

int main()
{
    BudgetItem* head = NULL;

    insertBudgetItem(head, "Groceries", 100.0);
    insertBudgetItem(head, "Dining out", 50.0);
    insertBudgetItem(head, "Entertainment", 25.0);

    double totalBudget = calculateTotalBudget(head);

    printf("Total budget: $%.2lf\n", totalBudget);

    return 0;
}