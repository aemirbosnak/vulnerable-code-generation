//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

int main() {
    Node* head = NULL;
    char message[] = "Romeo and Juliet's story is a tragedy.";

    // Insert characters into the linked list
    for (int i = 0; message[i] != '\0'; i++) {
        insertAtTail(head, message[i]);
    }

    // Compress the list
    Node* current = head;
    Node* previous = NULL;
    int count = 0;
    char buffer[MAX_BUFFER_SIZE];

    while (current) {
        int runLength = 1;
        char currentCharacter = current->data;

        // Check if the current character is the same as the previous character
        if (previous) {
            if (currentCharacter == previous->data) {
                runLength++;
            } else {
                buffer[count++] = previous->data;
                buffer[count++] = runLength - 1;
            }
        }

        previous = current;
        current = current->next;
    }

    // Print the compressed message
    buffer[count] = '\0';
    printf("%s", buffer);

    return 0;
}