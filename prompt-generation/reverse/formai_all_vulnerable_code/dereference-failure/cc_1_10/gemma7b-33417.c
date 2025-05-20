//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct LinkedList* next;
};

void insertAtTail(struct LinkedList* list, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        struct Node* tail = list->head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    list->next = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->next->head = newNode;
    list->next->next = NULL;
}

int main()
{
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->next = NULL;

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