//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_node(Node** head, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            insert_node(&previous, count);
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    insert_node(&previous, count);
}

int main() {
    Node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 2);
    insert_node(&head, 3);

    compress(head);

    Node* compressed_head = head;

    while (compressed_head) {
        printf("%d ", compressed_head->data);
        compressed_head = compressed_head->next;
    }

    return 0;
}