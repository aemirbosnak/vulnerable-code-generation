//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* lastNode = list->head;
        while (lastNode->next!= NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    list->size++;
}

void printLinkedList(LinkedList* list) {
    if (list->head == NULL) {
        printf("Empty List\n");
    } else {
        printf("Linked List:\n");
        Node* currentNode = list->head;
        while (currentNode!= NULL) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

void freeLinkedList(LinkedList* list) {
    if (list->head == NULL) {
        printf("Empty List\n");
    } else {
        Node* currentNode = list->head;
        while (currentNode!= NULL) {
            Node* tempNode = currentNode;
            currentNode = currentNode->next;
            free(tempNode);
        }
        list->head = NULL;
        list->size = 0;
    }
}

int main() {
    LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
    printLinkedList(list);
    freeLinkedList(list);
    return 0;
}