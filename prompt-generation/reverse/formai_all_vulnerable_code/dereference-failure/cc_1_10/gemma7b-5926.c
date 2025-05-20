//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct BudgetItem
{
    char name[MAX_NAME_LENGTH];
    double amount;
    struct BudgetItem* next;
} BudgetItem;

void insertBudgetItem(BudgetItem** head, char* name, double amount)
{
    BudgetItem* new_item = malloc(sizeof(BudgetItem));
    strcpy(new_item->name, name);
    new_item->amount = amount;
    new_item->next = NULL;

    if (*head == NULL)
    {
        *head = new_item;
    }
    else
    {
        (*head)->next = new_item;
    }
}

void printBudgetItems(BudgetItem* head)
{
    while (head)
    {
        printf("%s: %.2lf\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    BudgetItem* head = NULL;

    insertBudgetItem(&head, "Groceries", 150.0);
    insertBudgetItem(&head, "Rent", 1000.0);
    insertBudgetItem(&head, "Eating Out", 200.0);

    printBudgetItems(head);

    return 0;
}