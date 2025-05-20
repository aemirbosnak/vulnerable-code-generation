//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
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
        char currentChar = current->data;
        int occurrences = 1;
        for (Node* previous = head; previous && currentChar == previous->data; previous = previous->next) {
            occurrences++;
        }

        if (occurrences > 1) {
            sprintf(str, "%s%d", str, occurrences);
            compressedSize++;
        } else {
            str[compressedSize++] = currentChar;
        }
    }

    str[compressedSize] = '\0';
}

int main() {
    char str[] = "aabbbbcccc";
    compress(str);
    printf("%s", str);

    return 0;
}