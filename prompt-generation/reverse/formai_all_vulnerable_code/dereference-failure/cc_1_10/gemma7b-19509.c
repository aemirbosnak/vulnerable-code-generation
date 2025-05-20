//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

List* insert_at_tail(List* list, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    return list;
}

void print_list(List* list) {
    Node* current = list->head;

    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;

    insert_at_tail(list, 'a');
    insert_at_tail(list, 'b');
    insert_at_tail(list, 'c');
    insert_at_tail(list, 'd');

    print_list(list);

    free(list);

    return 0;
}