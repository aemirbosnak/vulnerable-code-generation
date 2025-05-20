//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <pthread.h>
#define LINK_SIZE 10
#define NULL ((void*)0)

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int isEmpty(LinkedList* list) {
    if (list->size == 0) {
        printf("\nOh noes! The list is empty!\n");
        exit(EXIT_FAILURE);
    }
    return 1;
}

void printList(LinkedList* list) {
    Node* currentNode = list->head;
    printf("\n-----Shocking List-------\n");
    while (currentNode != NULL) {
        printf("| %d |-> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

void insertAtHead(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void insertAtTail(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->tail == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }

    list->tail = newNode;
    list->size++;
}

void deleteNode(LinkedList* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("\nInvalid position! Position should be between 0 and %d\n", list->size - 1);
        exit(EXIT_FAILURE);
    }

    if (position == 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else {
        Node* currentNode = list->head;
        for (int i = 0; i < position - 1; i++) {
            currentNode = currentNode->next;
        }
        Node* temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        free(temp);
    }
    list->size--;
}

int main() {
    LinkedList* list = createList();

    insertAtHead(list, 1);
    insertAtHead(list, 2);
    insertAtTail(list, 3);
    insertAtTail(list, 4);

    printList(list);

    deleteNode(list, 1);

    printList(list);

    return 0;
}