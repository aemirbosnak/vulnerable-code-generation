//Gemma-7B DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct List {
    struct Node* head;
    struct Node* tail;
} List;

List* list_create() {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void list_append(List* list, char data) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return;
    }
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void list_print(List* list) {
    Node* node = list->head;
    while (node) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    List* list = list_create();
    if (list == NULL) {
        perror("Error creating list");
        return EXIT_FAILURE;
    }

    list_append(list, 'a');
    list_append(list, 'b');
    list_append(list, 'c');
    list_append(list, 'd');

    list_print(list);

    free(list);
    return EXIT_SUCCESS;
}