//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
    struct Node* next;
    char data;
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
    Node* head = malloc(sizeof(Node));
    head->data = 'a';

    Node* second = malloc(sizeof(Node));
    second->data = 'a';

    Node* third = malloc(sizeof(Node));
    third->data = 'b';

    Node* fourth = malloc(sizeof(Node));
    fourth->data = 'a';

    head->next = second;
    second->next = third;
    third->next = fourth;

    compress(head);

    return 0;
}