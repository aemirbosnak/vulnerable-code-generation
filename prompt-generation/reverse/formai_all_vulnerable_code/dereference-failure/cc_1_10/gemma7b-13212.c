//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: visionary
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
    char previousChar = '\0';
    int count = 1;

    while (current) {
        if (previousChar == current->data) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous = previous->next;
                previous->data = previousChar;
                previous->next = NULL;
            }

            previousChar = current->data;
            count = 1;
        }

        current = current->next;
    }

    if (previous) {
        previous->next = malloc(sizeof(Node));
        previous = previous->next;
        previous->data = previousChar;
        previous->next = NULL;
    }

    printf("Compressed data: ");
    for (current = head; current; current = current->next) {
        printf("%c (%d) ", current->data, count);
    }

    printf("\n");
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
    head->next->next->next->next = NULL;

    // Compress the list
    compress(head);

    return 0;
}