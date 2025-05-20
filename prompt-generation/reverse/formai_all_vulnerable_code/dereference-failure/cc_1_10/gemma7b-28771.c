//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    char item[MAX];
    int quantity;
    struct Node* next;
} Node;

void insert(Node** head, char item, int quantity)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item[0] = item;
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

void display(Node* head)
{
    while (head)
    {
        printf("%s: %d\n", head->item, head->quantity);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    insert(&head, 'a', 10);
    insert(&head, 'b', 20);
    insert(&head, 'c', 30);

    display(head);

    return 0;
}