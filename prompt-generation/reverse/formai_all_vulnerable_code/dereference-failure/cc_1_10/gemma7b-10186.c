//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

struct Item
{
    char name[20];
    int quantity;
    double price;
    struct Item* next;
};

struct Node
{
    struct Item* item;
    struct Node* next;
};

void insertItem(struct Item** head)
{
    struct Item* newNode = (struct Item*)malloc(sizeof(struct Item));

    printf("Enter item name: ");
    scanf("%s", newNode->name);

    printf("Enter item quantity: ");
    scanf("%d", &newNode->quantity);

    printf("Enter item price: ");
    scanf("%lf", &newNode->price);

    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void printItems(struct Item* head)
{
    while (head)
    {
        printf("%s - %d - %.2lf\n", head->name, head->quantity, head->price);
        head = head->next;
    }
}

int main()
{
    struct Item* head = NULL;

    insertItem(&head);
    insertItem(&head);
    insertItem(&head);

    printItems(head);

    return 0;
}