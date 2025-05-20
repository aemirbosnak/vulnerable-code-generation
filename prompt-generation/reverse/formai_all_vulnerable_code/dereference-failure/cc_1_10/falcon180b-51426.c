//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void addNodeToLinkedList(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printLinkedList(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteLinkedList(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}

void main() {
    LinkedList* list = createLinkedList();
    addNodeToLinkedList(list, 1);
    addNodeToLinkedList(list, 2);
    addNodeToLinkedList(list, 3);
    addNodeToLinkedList(list, 4);
    addNodeToLinkedList(list, 5);
    printLinkedList(list);
    deleteLinkedList(list);
}