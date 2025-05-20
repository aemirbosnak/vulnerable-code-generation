//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSE_ITEMS 10

typedef struct ExpenseItem
{
    char name[50];
    float amount;
    struct ExpenseItem* next;
} ExpenseItem;

ExpenseItem* insertExpenseItem(ExpenseItem* head, char* name, float amount)
{
    ExpenseItem* newItem = (ExpenseItem*)malloc(sizeof(ExpenseItem));
    strcpy(newItem->name, name);
    newItem->amount = amount;
    newItem->next = NULL;

    if (head == NULL)
    {
        return newItem;
    }

    head->next = insertExpenseItem(head->next, name, amount);
    return newItem;
}

void printExpenseItems(ExpenseItem* head)
{
    ExpenseItem* currentItem = head;
    printf("Expenses:\n");
    while (currentItem)
    {
        printf("  %s: %.2f\n", currentItem->name, currentItem->amount);
        currentItem = currentItem->next;
    }
}

int main()
{
    ExpenseItem* head = NULL;
    head = insertExpenseItem(head, "Groceries", 50.0);
    head = insertExpenseItem(head, "Eating out", 25.0);
    head = insertExpenseItem(head, "Clothing", 10.0);
    head = insertExpenseItem(head, "Electronics", 75.0);

    printExpenseItems(head);

    return 0;
}