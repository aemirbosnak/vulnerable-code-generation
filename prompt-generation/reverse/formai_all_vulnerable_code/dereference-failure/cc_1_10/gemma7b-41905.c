//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous->next->data = count;
                previous->next->next = current;
            }
            previous = current;
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