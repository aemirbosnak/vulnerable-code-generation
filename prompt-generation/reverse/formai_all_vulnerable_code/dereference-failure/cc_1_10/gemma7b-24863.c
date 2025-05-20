//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node
{
    char item[20];
    struct Node* next;
} Node;

void insert(Node** head, char item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item[0] = item;
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

void search(Node* head, char item)
{
    while (head)
    {
        if (strcmp(head->item, item) == 0)
        {
            printf("Item found: %s\n", item);
            return;
        }
        head = head->next;
    }

    printf("Item not found: %s\n", item);
}

int main()
{
    Node* head = NULL;

    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    search(head, 'c');
    search(head, 'f');

    return 0;
}