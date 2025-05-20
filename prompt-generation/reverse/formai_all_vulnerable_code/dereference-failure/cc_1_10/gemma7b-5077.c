//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_DESCRIPTION_LENGTH 1024

typedef struct PersonalFinanceItem
{
    char name[MAX_NAME_LENGTH];
    double amount;
    char description[MAX_DESCRIPTION_LENGTH];
    struct PersonalFinanceItem* next;
} PersonalFinanceItem;

PersonalFinanceItem* insertItem(PersonalFinanceItem* head, char* name, double amount, char* description)
{
    PersonalFinanceItem* newNode = malloc(sizeof(PersonalFinanceItem));

    strcpy(newNode->name, name);
    newNode->amount = amount;
    strcpy(newNode->description, description);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

void printItems(PersonalFinanceItem* head)
{
    PersonalFinanceItem* currentItem = head;

    printf("Items:\n");

    while (currentItem)
    {
        printf("Name: %s\n", currentItem->name);
        printf("Amount: %.2lf\n", currentItem->amount);
        printf("Description: %s\n", currentItem->description);
        printf("\n");

        currentItem = currentItem->next;
    }
}

int main()
{
    PersonalFinanceItem* head = NULL;

    insertItem(head, "Groceries", 100.0, "Purchased groceries for the week.");
    insertItem(head, "Rent", 500.0, "Paid rent for the month.");
    insertItem(head, "Dining", 200.0, "Spent money on dining out.");

    printItems(head);

    return 0;
}