//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;
    char previousChar = '\0';

    while (current) {
        if (previousChar == current->data) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous->next->data = count;
                previous = previous->next;
            }
            previousChar = current->data;
            count = 1;
        }

        current = current->next;
    }

    if (previous) {
        previous->next = malloc(sizeof(Node));
        previous->next->data = count;
    }
}

int main() {
    // Create a linked list
    Node* head = malloc(sizeof(Node));
    head->data = 'a';

    head->next = malloc(sizeof(Node));
    head->next->data = 'a';

    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 'b';

    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 'b';

    head->next->next->next->next = malloc(sizeof(Node));
    head->next->next->next->next->data = 'c';

    // Compress the list
    compress(head);

    // Print the compressed list
    Node* compressedHead = head;
    while (compressedHead) {
        printf("%c ", compressedHead->data);
        compressedHead = compressedHead->next;
    }

    return 0;
}