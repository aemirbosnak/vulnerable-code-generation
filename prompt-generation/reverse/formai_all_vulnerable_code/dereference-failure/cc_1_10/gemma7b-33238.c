//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
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
    tail = head;
    while (tail) {
        char currentChar = tail->data;
        int count = 1;
        Node* previousNode = tail;

        while (previousNode && previousNode->data == currentChar) {
            count++;
            previousNode = previousNode->next;
        }

        if (count > 1) {
            sprintf(str + compressedSize, "%c%d", currentChar, count);
            compressedSize += 2;
        } else {
            str[compressedSize] = currentChar;
            compressedSize++;
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