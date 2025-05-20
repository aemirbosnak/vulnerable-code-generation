//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct ExpenseItem
{
    char name[256];
    double amount;
    char category[256];
    struct ExpenseItem* next;
} ExpenseItem;

ExpenseItem* CreateItem(char* name, double amount, char* category)
{
    ExpenseItem* item = (ExpenseItem*)malloc(sizeof(ExpenseItem));
    strcpy(item->name, name);
    item->amount = amount;
    strcpy(item->category, category);
    item->next = NULL;
    return item;
}

void AddItem(ExpenseItem** head, char* name, double amount, char* category)
{
    ExpenseItem* item = CreateItem(name, amount, category);
    if (*head == NULL)
    {
        *head = item;
    }
    else
    {
        (*head)->next = item;
    }
}

void PrintItems(ExpenseItem* head)
{
    while (head)
    {
        printf("%s - %.2lf - %s\n", head->name, head->amount, head->category);
        head = head->next;
    }
}

int main()
{
    ExpenseItem* head = NULL;

    AddItem(&head, "Coffee", 2.50, "Beverages");
    AddItem(&head, "Lunch", 15.00, "Food");
    AddItem(&head, "Dinner", 20.00, "Food");
    AddItem(&head, "Groceries", 5.00, "Other");

    PrintItems(head);

    return 0;
}