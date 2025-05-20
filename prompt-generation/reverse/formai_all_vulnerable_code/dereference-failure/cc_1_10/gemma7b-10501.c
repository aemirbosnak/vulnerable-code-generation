//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert_at_tail(Node* head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            insert_at_tail(previous, count);
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    insert_at_tail(previous, count);
}

int main() {
    Node* head = NULL;
    head = insert_at_tail(head, 1);
    head = insert_at_tail(head, 1);
    head = insert_at_tail(head, 2);
    head = insert_at_tail(head, 2);
    head = insert_at_tail(head, 3);

    compress(head);

    Node* compressed_head = head;
    while (compressed_head) {
        printf("%d ", compressed_head->data);
        compressed_head = compressed_head->next;
    }

    return 0;
}