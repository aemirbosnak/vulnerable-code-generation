//FormAI DATASET v1.0 Category: Linked list operations ; Style: decentralized
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

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

bool isEmpty(LinkedList* list) {
    return list->head == NULL;
}

void insertAtBeginning(LinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(list)) {
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;
}

void insertAtEnd(LinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(list)) {
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

void insertAt(LinkedList* list, int index, int value) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds");
        return;
    }
    if (index == 0) {
        insertAtBeginning(list, value);
    } else if (index == list->size) {
        insertAtEnd(list, value);
    } else {
        Node* newNode = createNode(value);
        Node* current = list->head;
        Node* previous = NULL;
        int currentIndex = 0;
        while (currentIndex != index) {
            previous = current;
            current = current->next;
            currentIndex++;
        }
        previous->next = newNode;
        newNode->next = current;
        list->size++;
    }
}

void removeFromBeginning(LinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty");
        return;
    }
    Node* nodeToRemove = list->head;
    list->head = list->head->next;
    free(nodeToRemove);
    list->size--;
}

void removeFromEnd(LinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty");
        return;
    }
    Node* current = list->head;
    Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        list->head = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
    list->size--;
}

void removeFrom(LinkedList* list, int index) {
    if (isEmpty(list)) {
        printf("List is empty");
        return;
    }
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds");
        return;
    }
    if (index == 0) {
        removeFromBeginning(list);
    } else if (index == list->size - 1) {
        removeFromEnd(list);
    } else {
        Node* current = list->head;
        Node* previous = NULL;
        int currentIndex = 0;
        while (currentIndex != index) {
            previous = current;
            current = current->next;
            currentIndex++;
        }
        previous->next = current->next;
        free(current);
        list->size--;
    }
}

void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList* list = createLinkedList();
    insertAtBeginning(list, 5);
    insertAtEnd(list, 4);
    insertAt(list, 1, 3);
    removeFromBeginning(list);
    removeFromEnd(list);
    removeFrom(list, 0);
    printList(list);
    return 0;
}