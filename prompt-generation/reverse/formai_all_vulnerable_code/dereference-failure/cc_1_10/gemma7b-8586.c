//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: multivariable
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
    int i = 0;
    char prev = '\0';
    int count = 1;

    for (; str[i] != '\0'; i++) {
        if (prev == str[i]) {
            count++;
        } else {
            if (head == NULL) {
                head = malloc(sizeof(Node));
                head->data = str[i];
                head->next = NULL;
            } else {
                Node* newNode = malloc(sizeof(Node));
                newNode->data = str[i];
                newNode->next = NULL;
                head->next = newNode;
                head = newNode;
            }
            prev = str[i];
            count = 1;
        }
    }

    int compressedSize = 0;
    for (Node* node = head; node; node = node->next) {
        compressedSize++;
    }

    printf("Compressed size: %d\n", compressedSize);

    // Convert the linked list back to a string
    char* compressedStr = malloc(compressedSize);
    int j = 0;
    for (Node* node = head; node; node = node->next) {
        compressedStr[j++] = node->data;
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