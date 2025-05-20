//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;
    char previousCharacter = '\0';

    while (current) {
        if (previousCharacter == current->data) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous = previous->next;
                previous->data = count;
                previous->next = NULL;
            }
            previousCharacter = current->data;
            count = 1;
        }
        current = current->next;
    }

    return head;
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
    head->next->next->next->data = 'a';

    // Compress the list
    head = compress(head);

    // Print the compressed list
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}