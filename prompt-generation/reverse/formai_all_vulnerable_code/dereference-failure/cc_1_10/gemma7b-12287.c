//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    // Create a sample linked list
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

    // Compress the list
    compress(head);

    // Print the compressed list
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}