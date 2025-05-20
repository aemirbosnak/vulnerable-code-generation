//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    Node* head = NULL;
    char buffer[MAX_BUFFER_SIZE];

    // Read data from the input
    printf("Enter data: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Insert data into the linked list
    for (int i = 0; buffer[i] != '\0'; i++) {
        insertAtTail(head, buffer[i]);
    }

    // Compress the data
    Node* current = head;
    int compressedSize = 0;
    char lastChar = '\0';
    while (current) {
        if (current->next == NULL || current->data == lastChar) {
            compressedSize++;
            lastChar = current->data;
        } else {
            compressedSize++;
            lastChar = current->data;
            printf("%c ", current->data);
        }
        current = current->next;
    }

    // Print the compressed data
    printf("\nCompressed data: ");
    for (int i = 0; i < compressedSize; i++) {
        printf("%c ", lastChar);
    }

    return 0;
}