//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define TRUE 1
#define FALSE 0

// Node structure
typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node* next;
} Node;

// Linked list structure
typedef struct list {
    Node* head;
    Node* tail;
    int size;
} List;

// Function prototypes
Node* createNode(char* data, int size);
List* createList();
void append(List* list, char* data, int size);
void prepend(List* list, char* data, int size);
void deleteNode(List* list, Node* node);
void printList(List* list);

int main() {
    List* list = createList();

    append(list, "My love for you is like a red, red rose", 34);
    prepend(list, "O, my Luve is like a red, red rose", 29);
    append(list, "That's newly sprung in June", 25);
    prepend(list, "O, my Luve is like the melody", 30);

    printList(list);

    deleteNode(list, list->head);
    deleteNode(list, list->tail);

    printList(list);

    return 0;
}

Node* createNode(char* data, int size) {
    Node* node = (Node*) malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    strcpy(node->data, data);
    node->size = size;
    node->next = NULL;

    return node;
}

List* createList() {
    List* list = (List*) malloc(sizeof(List));

    if (list == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void append(List* list, char* data, int size) {
    Node* node = createNode(data, size);

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}

void prepend(List* list, char* data, int size) {
    Node* node = createNode(data, size);

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head = node;
    }

    list->size++;
}

void deleteNode(List* list, Node* node) {
    if (node == list->head) {
        list->head = node->next;
    } else if (node == list->tail) {
        list->tail = node->next;
    } else {
        Node* prev = list->head;

        while (prev->next!= node) {
            prev = prev->next;
        }

        prev->next = node->next;
    }

    free(node);
    list->size--;
}

void printList(List* list) {
    Node* node = list->head;

    while (node!= NULL) {
        printf("%s\n", node->data);
        node = node->next;
    }
}