//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
    Node* tail;
    int size;
    int maxSize;
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

void printList(struct LinkedList* list) {
    Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->maxSize = MAX_SIZE;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    insertAtTail(list, 10);
    insertAtTail(list, 20);
    insertAtTail(list, 30);

    printList(list);

    return 0;
}