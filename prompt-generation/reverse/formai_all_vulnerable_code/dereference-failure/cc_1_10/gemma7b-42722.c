//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char item[20];
    int quantity;
    struct node* next;
};

void insert(struct node** head, char item, int quantity)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->item, item);
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

void search(struct node* head, char item)
{
    while (head)
    {
        if (strcmp(head->item, item) == 0)
        {
            printf("Item: %s, Quantity: %d\n", head->item, head->quantity);
            return;
        }
        head = head->next;
    }

    printf("Item not found.\n");
}

int main()
{
    struct node* head = NULL;

    insert( &head, "Apple", 10);
    insert( &head, "Banana", 5);
    insert( &head, "Orange", 20);

    search(head, "Orange");

    return 0;
}