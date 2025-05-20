//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node
{
    char item[MAX];
    struct Node* next;
} Node;

void insertAtTail(Node** head, char item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->item, item);
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

void searchItem(Node* head, char item)
{
    if (head == NULL)
    {
        return;
    }

    if (strcmp(head->item, item) == 0)
    {
        printf("Item found: %s\n", head->item);
    }
    else if (head->next != NULL)
    {
        searchItem(head->next, item);
    }
}

int main()
{
    Node* head = NULL;

    insertAtTail(&head, "Apple");
    insertAtTail(&head, "Banana");
    insertAtTail(&head, "Orange");

    searchItem(head, "Banana");

    return 0;
}