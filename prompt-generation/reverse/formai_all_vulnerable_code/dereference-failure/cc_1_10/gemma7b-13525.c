//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: portable
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
                previous->next->next = current;
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
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;

    // Fill the buffer with some data
    buffer[i++] = 'a';
    buffer[i++] = 'a';
    buffer[i++] = 'b';
    buffer[i++] = 'b';
    buffer[i++] = 'c';
    buffer[i++] = 'c';
    buffer[i++] = '\0';

    // Create a linked list from the buffer
    Node* head = malloc(sizeof(Node));
    head->data = buffer[0];
    head->next = NULL;
    for (i = 1; buffer[i] != '\0'; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = buffer[i];
        newNode->next = NULL;
        head->next = newNode;
        head = newNode;
    }

    // Compress the linked list
    compress(head);

    // Print the compressed data
    Node* current = head;
    while (current) {
        printf("%c", current->data);
        if (current->next) {
            printf("%d", current->next->data);
        }
        current = current->next;
    }

    return 0;
}