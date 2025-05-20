//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node
{
    char name[MAX_SIZE];
    struct Node* next;
} Node;

void insert(Node** head, char* name)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
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

void search(Node* head, char* name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            printf("Found: %s\n", head->name);
            return;
        }
        head = head->next;
    }

    printf("Not found: %s\n", name);
}

int main()
{
    Node* head = NULL;

    insert(&head, "John Doe");
    insert(&head, "Jane Doe");
    insert(&head, "Peter Pan");

    search(head, "Jane Doe");

    return 0;
}