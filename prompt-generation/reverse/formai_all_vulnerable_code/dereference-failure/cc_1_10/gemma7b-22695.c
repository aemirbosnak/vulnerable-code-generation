//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;
    int previousData = current->data;

    while (current->next) {
        current = current->next;
        if (previousData == current->data) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous = previous->next;
                previous->data = previousData;
                previous->next = NULL;
            }
            previousData = current->data;
            count = 1;
        }
    }

    if (previous) {
        previous->next = malloc(sizeof(Node));
        previous = previous->next;
        previous->data = previousData;
        previous->next = NULL;
    }

    head = previous->next;
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 1;

    head->next = malloc(sizeof(Node));
    head->next->data = 1;

    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 2;

    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 2;

    head->next->next->next->next = malloc(sizeof(Node));
    head->next->next->next->next->data = 3;

    compress(head);

    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}