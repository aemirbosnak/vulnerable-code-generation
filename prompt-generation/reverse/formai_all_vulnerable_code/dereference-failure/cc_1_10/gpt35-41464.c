//FormAI DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct linkedList {
    int size;
    Node* head;
} LinkedList;

void add(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void printList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->head;
    printf("Size: %d\n", list->size);
    printf("Values: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList list = { 0, NULL };

    add(&list, 1);
    add(&list, 2);
    add(&list, 3);

    printList(&list);

    return 0;
}