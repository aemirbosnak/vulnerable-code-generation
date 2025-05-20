//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

void insertAtTail(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        list->head->next = newNode;
    }

    list->size++;
}

void printList(LinkedList* list) {
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
    list->size = 0;

    insertAtTail(list, 10);
    insertAtTail(list, 20);
    insertAtTail(list, 30);

    printList(list);

    return 0;
}