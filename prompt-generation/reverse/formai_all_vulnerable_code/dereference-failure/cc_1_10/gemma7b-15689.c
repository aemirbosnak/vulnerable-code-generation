//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;
    char previousChar = current->data;

    while (current->next) {
        if (current->data == previousChar) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous->next->data = count;
                previous->next->next = NULL;
            }
            previousChar = current->data;
            count = 1;
        }
        current = current->next;
    }

    if (previous) {
        previous->next = malloc(sizeof(Node));
        previous->next->data = count;
        previous->next->next = NULL;
    }
}

int main() {
    // Create a sample linked list
    Node* head = malloc(sizeof(Node));
    head->data = 'a';
    head->next = malloc(sizeof(Node));
    head->next->data = 'a';
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 'b';
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 'b';

    // Compress the list
    compress(head);

    // Print the compressed list
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}