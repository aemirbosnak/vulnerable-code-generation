//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: recursive
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
        (*head)->next = newNode;
    }
}

void search(struct Node* head, char name)
{
    if (head == NULL)
    {
        printf("Item not found.\n");
        return;
    }

    if (strcmp(head->name, name) == 0)
    {
        printf("Item found: %s, Quantity: %d\n", head->name, head->quantity);
        return;
    }

    search(head->next, name);
}

void update(struct Node* head, char name, int newQuantity)
{
    if (head == NULL)
    {
        printf("Item not found.\n");
        return;
    }

    if (strcmp(head->name, name) == 0)
    {
        head->quantity = newQuantity;
        printf("Item updated: %s, Quantity: %d\n", head->name, head->quantity);
        return;
    }

    update(head->next, name, newQuantity);
}

void delete(struct Node* head, char name)
{
    if (head == NULL)
    {
        printf("Item not found.\n");
        return;
    }

    if (strcmp(head->name, name) == 0)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Item deleted: %s\n", name);
        return;
    }

    delete(head->next, name);
}

int main()
{
    struct Node* head = NULL;

    insert(&head, "A", 10);
    insert(&head, "B", 20);
    insert(&head, "C", 30);

    search(head, "A");
    update(head, "B", 35);
    delete(head, "C");

    search(head, "A");
    search(head, "B");

    return 0;
}