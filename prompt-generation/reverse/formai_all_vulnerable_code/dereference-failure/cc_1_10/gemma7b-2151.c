//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WINDOW_SIZE 256

typedef struct Node {
    struct Node* next;
    char data;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int windowSize = 0;
    int count = 0;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                printf("%c%d ", previous->data, count);
            }
            previous = current;
            count = 1;
        }
        windowSize++;
        if (windowSize == MAX_WINDOW_SIZE) {
            previous = current;
            windowSize = 0;
        }
    }

    printf("\n");
}

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->next = malloc(sizeof(Node));
    head->next->next = malloc(sizeof(Node));
    head->next->next->next = malloc(sizeof(Node));

    head->data = 'a';
    head->next->data = 'a';
    head->next->next->data = 'b';
    head->next->next->next->data = 'a';

    compress(head);

    return 0;
}