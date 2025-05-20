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
    char* buffer = NULL;
    int bufferSize = 0;
    int count = 0;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (buffer) {
                free(buffer);
            }

            buffer = malloc(MAX_BUFFER_SIZE);
            bufferSize = MAX_BUFFER_SIZE;

            buffer[0] = previous->data;
            buffer[1] = count;

            current->data = buffer[0];
            current->next = (Node*)buffer;

            previous = current;
            count = 1;
        }

        current = current->next;
    }

    if (buffer) {
        free(buffer);
    }
}

int main() {
    Node* head = NULL;

    // Create a few nodes
    head = malloc(sizeof(Node));
    head->data = 'a';
    head->next = malloc(sizeof(Node));
    head->next->data = 'a';
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 'b';
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 'b';

    // Compress the nodes
    compress(head);

    // Print the compressed nodes
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}