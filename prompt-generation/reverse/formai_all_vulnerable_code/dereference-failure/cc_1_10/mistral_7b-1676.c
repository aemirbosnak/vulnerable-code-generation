//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    int size;
} List;

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void addNode(List* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
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

void printList(List* list) {
    Node* current = list->head;

    printf("Surprising Linked List:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void surpriseElement(List* list) {
    srand(time(NULL));
    int index = rand() % list->size;
    Node* current = list->head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    int temp = current->data;
    int swap = current->next->data;

    current->data = swap;
    current->next->data = temp;

    printf("Surprise! Elements %d and %d swapped!\n", temp, swap);
}

int main() {
    List* list = createList();

    addNode(list, 5);
    addNode(list, 10);
    addNode(list, 15);
    addNode(list, 20);
    addNode(list, 25);

    printList(list);

    surpriseElement(list);

    printList(list);

    free(list);

    return 0;
}