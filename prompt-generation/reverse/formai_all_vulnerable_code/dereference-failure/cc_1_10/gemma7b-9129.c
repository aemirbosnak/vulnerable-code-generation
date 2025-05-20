//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 0;
    char previousChar = '\0';

    while (current) {
        if (previousChar == current->data) {
            count++;
        } else {
            if (previous) {
                printf("%c%d ", previousChar, count);
            }
            previousChar = current->data;
            count = 1;
        }

        previous = current;
        current = current->next;
    }

    if (previous) {
        printf("%c%d ", previousChar, count);
    }
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 'a';
    head->next = malloc(sizeof(Node));
    head->next->data = 'a';
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 'b';
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 'b';
    head->next->next->next->next = NULL;

    compress(head);

    return 0;
}