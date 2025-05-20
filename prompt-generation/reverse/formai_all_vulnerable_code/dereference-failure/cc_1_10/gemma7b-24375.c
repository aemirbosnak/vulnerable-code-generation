//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    char item[MAX];
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
        if (head->item[0] == item)
        {
            printf("Item found!\n");
            return;
        }
        head = head->next;
    }

    printf("Item not found.\n");
}

int main()
{
    Node* head = NULL;

    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');

    search(head, 'b');

    return 0;
}