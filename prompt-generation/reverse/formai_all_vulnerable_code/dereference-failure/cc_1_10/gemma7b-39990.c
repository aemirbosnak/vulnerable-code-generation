//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node
{
    char name[MAX];
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
        insert((*head)->next, name);
    }
}

void display(Node* head)
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

    insert(&head, "John");
    insert(&head, "Mary");
    insert(&head, "Bob");

    display(head);

    insert(&head, "Alice");

    display(head);

    return 0;
}