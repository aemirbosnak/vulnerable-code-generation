//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 42

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    char buffer[MAX_BUFFER_SIZE];

    printf("Welcome to the C Compression Algorithms Lab!\n");

    // Insert a bunch of data into the linked list
    for (int i = 0; i < 10; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = i + 1;
        newNode->next = head;
        head = newNode;
    }

    // Compress the data
    int compressedSize = compress(buffer, head);

    // Print the compressed data
    printf("Compressed data: ");
    for (int i = 0; i < compressedSize; i++) {
        printf("%c ", buffer[i]);
    }

    // Decompress the data
    int originalSize = decompress(buffer, head);

    // Print the original data
    printf("\nOriginal data: ");
    for (int i = 0; i < originalSize; i++) {
        printf("%d ", head->data);
    }

    return 0;
}

int compress(char* buffer, Node* head) {
    int index = 0;
    buffer[index++] = head->data;

    Node* current = head->next;
    while (current) {
        if (current->data == head->data) {
            buffer[index++] = 0;
        } else {
            buffer[index++] = current->data;
            head = current;
        }
    }

    return index;
}

int decompress(char* buffer, Node* head) {
    int index = 0;
    head->data = buffer[index++];

    Node* current = head->next;
    while (current) {
        if (buffer[index] == 0) {
            current->data = head->data;
            head = current;
        } else {
            current->data = buffer[index++];
            head = current;
        }
    }

    return index;
}