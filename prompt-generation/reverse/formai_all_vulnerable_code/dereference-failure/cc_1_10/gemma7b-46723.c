//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: configurable
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
    int i = 0;
    char currentChar = str[0];
    int count = 1;

    for (i = 1; str[i] != '\0'; i++) {
        if (str[i] == currentChar) {
            count++;
        } else {
            if (head == NULL) {
                head = tail = malloc(sizeof(Node));
                head->data = currentChar;
                head->next = NULL;
            } else {
                tail->next = malloc(sizeof(Node));
                tail = tail->next;
                tail->data = currentChar;
                tail->next = NULL;
            }

            currentChar = str[i];
            count = 1;
        }
    }

    // Insert the final character
    if (tail) {
        tail->next = malloc(sizeof(Node));
        tail = tail->next;
        tail->data = str[i];
        tail->next = NULL;
    }

    // Calculate the compressed size
    int compressedSize = head->next ? head->next->data : 0;

    // Print the compressed size
    printf("Compressed size: %d\n", compressedSize);

    // Print the compressed string
    char* compressedStr = malloc(compressedSize);
    tail = head->next;
    i = 0;
    while (tail) {
        compressedStr[i++] = tail->data;
        tail = tail->next;
    }

    printf("Compressed string: %s\n", compressedStr);

    free(compressedStr);
    free(head);
}

int main() {
    char str[] = "aabbbbcccc";
    compress(str);

    return 0;
}