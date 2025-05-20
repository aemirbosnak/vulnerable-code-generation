//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a protected linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Define a protected linked list
typedef struct LinkedList {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

// Protected operations on the linked list
void insertAtTail(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

void deleteAtTail(LinkedList* list) {
    if (list->size == 0) {
        return;
    }

    Node* tailNode = list->tail;
    list->tail = tailNode->prev;

    free(tailNode);
    list->size--;
}

void traverse(LinkedList* list) {
    Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    insertAtTail(list, 10);
    insertAtTail(list, 20);
    insertAtTail(list, 30);
    insertAtTail(list, 40);

    traverse(list);

    deleteAtTail(list);

    traverse(list);

    return 0;
}