//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;
}

void printLinkedList(LinkedList* list) {
    Node* current = list->head;
    printf("Linked List: ");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteLinkedList(LinkedList* list) {
    Node* current = list->head;
    while (current!= NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int searchNode(LinkedList* list, int data) {
    Node* current = list->head;
    while (current!= NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);

    printf("Linked List after adding nodes: ");
    printLinkedList(list);

    int searchData = 3;
    if (searchNode(list, searchData)) {
        printf("Data found in linked list.\n");
    } else {
        printf("Data not found in linked list.\n");
    }

    deleteLinkedList(list);
    return 0;
}