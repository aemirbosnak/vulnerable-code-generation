//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node* head, char data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
    head = newNode;
}

void compress(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;
    char previousChar = '\0';
    int count = 1;

    while (current) {
        if (previousChar == current->data) {
            count++;
        } else {
            if (previousChar) {
                insertNode(previous, count);
            }
            previousChar = current->data;
            count = 1;
        }
        current = current->next;
    }

    insertNode(previous, count);
}

int main() {
    struct Node* head = NULL;
    insertNode(head, 'a');
    insertNode(head, 'a');
    insertNode(head, 'b');
    insertNode(head, 'b');
    insertNode(head, 'c');
    insertNode(head, 'c');

    compress(head);

    struct Node* current = head;
    while (current) {
        printf("%c", current->data);
        printf(" (%d)", current->next->data - current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}