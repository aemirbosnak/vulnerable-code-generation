//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ Mailing_LIST_SIZE 100

typedef struct Node
{
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

Node* InsertNode(Node* head, char* name)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

void PrintList(Node* head)
{
    Node* current = head;
    while (current)
    {
        printf("%s ", current->name);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Node* head = NULL;

    InsertNode(head, "John Doe");
    InsertNode(head, "Jane Doe");
    InsertNode(head, "Bob Smith");

    PrintList(head);

    return 0;
}