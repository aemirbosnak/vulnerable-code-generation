//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
} List;

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addNode(List* list, int data) {
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
}

void printList(List* list) {
    Node* currentNode = list->head;

    if (currentNode == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");

    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

void deleteList(List* list) {
    Node* currentNode = list->head;
    Node* nextNode;

    while (currentNode!= NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(list);
}

int main() {
    List* list = createList();

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);

    printList(list);

    deleteList(list);

    return 0;
}