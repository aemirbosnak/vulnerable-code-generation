//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

void initList(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void addNode(List *list, int data) {
    Node *newNode = malloc(sizeof(Node));
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

void printList(List *list) {
    Node *current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void freeList(List *list) {
    Node *current = list->head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int main() {
    List list;

    initList(&list);

    for (int i = 0; i < 100; i++) {
        addNode(&list, rand() % 100);
    }

    printList(&list);

    freeList(&list);

    return 0;
}