//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
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

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                previous->next = malloc(sizeof(Node));
                previous = previous->next;
                previous->data = count;
                previous->next = NULL;
            }
            previous = current;
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

    printf("Compressed data: ");
    for (current = head; current; current = current->next) {
        printf("%c ", current->data);
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data = 'a';
    head->next = malloc(sizeof(Node));
    head->next->data = 'a';
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 'b';
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 'b';

    compress(head);

    return 0;
}