//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char name[20];
    int quantity;
    struct Node* next;
};

void insert(struct Node** head, char name, int quantity)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        insert((*head)->next, name, quantity);
    }
}

void search(struct Node* head, char name)
{
    if (head == NULL)
    {
        return;
    }

    if (strcmp(head->name, name) == 0)
    {
        printf("Name: %s, Quantity: %d\n", head->name, head->quantity);
    }
    else
    {
        search(head->next, name);
    }
}

int main()
{
    struct Node* head = NULL;

    insert(&head, "Apple", 10);
    insert(&head, "Banana", 5);
    insert(&head, "Orange", 7);

    search(head, "Orange");

    return 0;
}