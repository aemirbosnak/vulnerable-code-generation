//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct List
{
    Node* head;
    Node* tail;
} List;

void insertAtTail(List* list, int data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

int main()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;

    insertAtTail(list, 10);
    insertAtTail(list, 20);
    insertAtTail(list, 30);

    Node* current = list->head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}