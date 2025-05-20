//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                previous->next = newNode(count);
            }
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    if (previous) {
        previous->next = newNode(count);
    }
}

int main() {
    Node* head = newNode('a');
    head->next = newNode('a');
    head->next->next = newNode('b');
    head->next->next->next = newNode('a');
    head->next->next->next->next = newNode('b');

    compress(head);

    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}