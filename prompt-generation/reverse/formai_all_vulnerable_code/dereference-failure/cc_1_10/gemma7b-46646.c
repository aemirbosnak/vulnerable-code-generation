//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
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
    char previousChar = current->data;

    while (current->next) {
        current = current->next;
        if (previousChar == current->data) {
            count++;
        } else {
            previousChar = current->data;
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous = previous->next;
                previous->data = count;
            }
            count = 1;
        }
    }

    if (previous) {
        previous->next = malloc(sizeof(Node));
        previous = previous->next;
        previous->data = count;
    }

    free(head);
    head = NULL;
}

int main() {
    char buffer[] = "aabbbbcaaa";
    int length = strlen(buffer);

    Node* head = malloc(sizeof(Node));
    head->data = buffer[0];
    head->next = NULL;

    for (int i = 1; i < length; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = buffer[i];
        newNode->next = NULL;

        head->next = newNode;
        head = newNode;
    }

    compress(head);

    return 0;
}