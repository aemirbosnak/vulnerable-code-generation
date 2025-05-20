//Gemma-7B DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
} List;

List *myList = NULL;

void insertAtTail(char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (myList == NULL)
    {
        myList = (List *)malloc(sizeof(List));
        myList->head = newNode;
        myList->tail = newNode;
    }
    else
    {
        myList->tail->next = newNode;
        myList->tail = newNode;
    }
}

void printList()
{
    Node *current = myList->head;
    while (current)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    insertAtTail("John Doe");
    insertAtTail("Jane Doe");
    insertAtTail("Bill Smith");
    printList();

    insertAtTail("Mary Johnson");
    printList();

    return 0;
}