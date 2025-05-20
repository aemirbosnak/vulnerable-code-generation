//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node* insertNode(struct Node* head, char data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void compress(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            insertNode(previous, (char)count);
            previous = current;
            count = 1;
        }

        current = current->next;
    }

    insertNode(previous, (char)count);

    printf("Compressed data: ");
    struct Node* iterator = head;
    while (iterator) {
        printf("%c", iterator->data);
        iterator = iterator->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = insertNode(NULL, 'a');
    insertNode(head, 'a');
    insertNode(head, 'b');
    insertNode(head, 'b');
    insertNode(head, 'c');
    insertNode(head, 'c');

    compress(head);

    return 0;
}