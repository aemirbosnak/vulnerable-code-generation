//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int compress(Node* head) {
    Node* current = head;
    int count = 0;
    int previous = -1;
    int run_length = 1;

    while (current) {
        if (previous == current->data) {
            run_length++;
        } else {
            if (previous != -1) {
                printf("%d ", run_length);
            }
            previous = current->data;
            run_length = 1;
        }
        current = current->next;
    }

    if (previous != -1) {
        printf("%d ", run_length);
    }

    return 0;
}

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 1;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 2;
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 2;
    head->next->next->next->next = NULL;

    compress(head);

    return 0;
}