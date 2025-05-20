//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void compress(char* str) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = str[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int compressedSize = 0;
    for (Node* current = head; current; current = current->next) {
        compressedSize++;
    }

    printf("Original string: %s\n", str);
    printf("Compressed string: ");

    for (Node* current = head; current; current = current->next) {
        printf("%c ", current->data);
    }

    printf("\n");
    printf("Number of characters compressed: %d\n", compressedSize - 1);
}

int main() {
    char str[] = "This is a string to be compressed.";

    compress(str);

    return 0;
}