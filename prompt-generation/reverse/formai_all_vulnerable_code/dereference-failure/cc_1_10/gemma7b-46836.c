//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_at_tail(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        ((*head)->next = new_node);
        *head = new_node;
    }
}

void compress(Node** head) {
    Node* current = *head;
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

    insert_at_tail(&head, 1);
    insert_at_tail(&head, 1);
    insert_at_tail(&head, 2);
    insert_at_tail(&head, 2);
    insert_at_tail(&head, 3);

    compress(&head);

    Node* iter = head;
    while (iter) {
        printf("%d ", iter->data);
        iter = iter->next;
    }

    return 0;
}