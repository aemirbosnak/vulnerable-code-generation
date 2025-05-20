//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
    Node* tail;
    int size;
};

void insertAtTail(struct LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

int main() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    insertAtTail(list, 10);
    insertAtTail(list, 20);
    insertAtTail(list, 30);
    insertAtTail(list, 40);

    Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}