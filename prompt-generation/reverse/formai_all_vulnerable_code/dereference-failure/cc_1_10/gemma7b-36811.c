//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_DESCRIPTION_LENGTH 512

typedef struct BudgetItem
{
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int amount;
    struct BudgetItem* next;
} BudgetItem;

void insertBudgetItem(BudgetItem** head, BudgetItem* newItem)
{
    if (*head == NULL)
    {
        *head = newItem;
    }
    else
    {
        (*head)->next = newItem;
        *head = newItem;
    }
}

void printBudgetItems(BudgetItem* head)
{
    while (head)
    {
        printf("%s: %s, %d\n", head->name, head->description, head->amount);
        head = head->next;
    }
}

int main()
{
    BudgetItem* head = NULL;

    // Insert some budget items
    insertBudgetItem(&head, malloc(sizeof(BudgetItem)));
    strcpy(head->name, "Groceries");
    strcpy(head->description, "Purchased groceries for the week.");
    head->amount = 200;

    insertBudgetItem(&head, malloc(sizeof(BudgetItem)));
    strcpy(head->name, "Eating out");
    strcpy(head->description, "Dinner at a restaurant.");
    head->amount = 50;

    insertBudgetItem(&head, malloc(sizeof(BudgetItem)));
    strcpy(head->name, "Electronics");
    strcpy(head->description, "Purchased a new television.");
    head->amount = 1000;

    // Print the budget items
    printBudgetItems(head);

    return 0;
}