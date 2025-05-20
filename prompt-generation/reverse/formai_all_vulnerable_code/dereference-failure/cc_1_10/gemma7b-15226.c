//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: synchronous
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

    while (current) {
        if (previousChar == current->data) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous = previous->next;
                previous->data = count;
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
        previous->data = count;
        previous->next = NULL;
    }
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    printf("Enter a string: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; buffer[i] != '\0'; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = buffer[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    compress(head);

    printf("Compressed string: ");
    for (Node* current = head; current; current = current->next) {
        printf("%c ", current->data);
    }

    printf("\n");

    return 0;
}