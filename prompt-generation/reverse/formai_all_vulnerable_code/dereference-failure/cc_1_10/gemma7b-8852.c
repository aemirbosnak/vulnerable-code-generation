//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

void insertAtTail(struct LinkedList* list, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;

    insertAtTail(list, 10);
    insertAtTail(list, 20);
    insertAtTail(list, 30);
    insertAtTail(list, 40);

    struct Node* current = list->head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}