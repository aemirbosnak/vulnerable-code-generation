//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define DATA_SIZE sizeof(int)

typedef struct Node {
    int data;
    size_t size;
    struct Node* next;
} Node;

Node* create_node(int data, size_t size) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->size = size;
    new_node->next = NULL;

    return new_node;
}

void print_node(Node* node) {
    printf("Node data: %d, Size: %ld\n", node->data, node->size);
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

void append(Node** head, int data, size_t size) {
    Node* new_node = create_node(data, size);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

int main(void) {
    Node* head = NULL;
    int i;

    for (i = 0; i < 10; i++) {
        int data = rand() % 50 + 1;
        size_t size = rand() % 10 + 1;
        append(&head, data, size);
    }

    print_list(head);

    return 0;
}