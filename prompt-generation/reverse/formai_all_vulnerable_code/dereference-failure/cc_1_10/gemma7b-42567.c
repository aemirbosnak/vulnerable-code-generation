//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
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
    int previous = current->data;
    int runs = 1;

    while (current->next) {
        current = current->next;
        if (previous == current->data) {
            runs++;
        } else {
            printf("%d ", previous);
            printf("%d ", runs);
            previous = current->data;
            runs = 1;
        }
    }

    printf("%d ", previous);
    printf("%d ", runs);

    return 0;
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 1;

    Node* second = malloc(sizeof(Node));
    second->data = 1;

    Node* third = malloc(sizeof(Node));
    third->data = 2;

    Node* fourth = malloc(sizeof(Node));
    fourth->data = 2;

    head->next = second;
    second->next = third;
    third->next = fourth;

    compress(head);

    return 0;
}