//Falcon2-11B DATASET v1.0 Category: Chess engine ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
} List;

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

void insertNode(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
}

void printList(List* list) {
    Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List* list = createList();
    insertNode(list, 1);
    insertNode(list, 2);
    insertNode(list, 3);
    insertNode(list, 4);
    insertNode(list, 5);
    printList(list);
    return 0;
}