//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

void compress(List* list) {
    Node* current = list->head;
    Node* previous = NULL;
    int count = 0;
    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous = previous->next;
                previous->data = current->data;
                previous->next = NULL;
            } else {
                list->head = malloc(sizeof(Node));
                list->head->data = current->data;
                list->head->next = NULL;
                list->tail = list->head;
            }
            count = 1;
        }
        current = current->next;
    }
    list->tail = previous;
}

int main() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;

    // Add some data to the list
    list->tail = malloc(sizeof(Node));
    list->tail->data = 10;
    list->tail->next = NULL;

    list->tail = malloc(sizeof(Node));
    list->tail->data = 10;
    list->tail->next = NULL;

    list->tail = malloc(sizeof(Node));
    list->tail->data = 20;
    list->tail->next = NULL;

    list->tail = malloc(sizeof(Node));
    list->tail->data = 20;
    list->tail->next = NULL;

    // Compress the list
    compress(list);

    // Print the compressed list
    Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}