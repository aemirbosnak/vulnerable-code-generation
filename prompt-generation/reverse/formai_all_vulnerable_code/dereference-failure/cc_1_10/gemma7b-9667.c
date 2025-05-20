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
        insert(head, name, quantity);
    }
}

int search(struct Node* head, char name)
{
    if (head == NULL)
    {
        return -1;
    }

    if (strcmp(head->name, name) == 0)
    {
        return head->quantity;
    }

    return search(head->next, name);
}

int main()
{
    struct Node* head = NULL;

    insert(&head, "Apple", 10);
    insert(&head, "Banana", 20);
    insert(&head, "Orange", 30);

    int quantity = search(head, "Banana");

    if (quantity != -1)
    {
        printf("Quantity of %s is %d", "Banana", quantity);
    }
    else
    {
        printf("Item not found");
    }

    return 0;
}