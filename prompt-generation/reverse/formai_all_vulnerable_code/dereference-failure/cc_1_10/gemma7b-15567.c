//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node
{
    char name[MAX_SIZE];
    struct Node* next;
} Node;

void insert(Node** head, char* name)
{
    Node* newNode = malloc(sizeof(Node));
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

void printList(Node* head)
{
    while (head)
    {
        printf("%s ", head->name);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    insert(&head, "John Doe");
    insert(&head, "Jane Doe");
    insert(&head, "Peter Pan");

    printList(head);

    return 0;
}