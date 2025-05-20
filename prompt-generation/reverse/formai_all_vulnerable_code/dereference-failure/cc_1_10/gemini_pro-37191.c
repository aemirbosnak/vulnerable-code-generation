//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insertNodeAtHead(LinkedList *list, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    if (list->size == 0) {
        list->tail = newNode;
    }
    list->head = newNode;
    list->size++;
}

void insertNodeAtTail(LinkedList *list, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->size == 0) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    list->size++;
}

void deleteNodeAtHead(LinkedList *list) {
    if (list->size == 0) {
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    if (list->size == 1) {
        list->tail = NULL;
    }
    free(temp);
    list->size--;
}

void deleteNodeAtTail(LinkedList *list) {
    if (list->size == 0) {
        return;
    }
    Node *temp = list->head;
    while (temp->next != list->tail) {
        temp = temp->next;
    }
    list->tail = temp;
    temp->next = NULL;
    if (list->size == 1) {
        list->head = NULL;
    }
    list->size--;
}

void printLinkedList(LinkedList *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LinkedList *list = createLinkedList();
    insertNodeAtHead(list, 1);
    insertNodeAtHead(list, 2);
    insertNodeAtHead(list, 3);
    insertNodeAtTail(list, 4);
    insertNodeAtTail(list, 5);
    insertNodeAtTail(list, 6);
    printLinkedList(list);
    deleteNodeAtHead(list);
    deleteNodeAtTail(list);
    printLinkedList(list);
    return 0;
}