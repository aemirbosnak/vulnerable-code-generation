//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
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
    int count = 1;
    char currentCharacter = str[0];

    for (; str[i] != '\0'; i++) {
        if (str[i] == currentCharacter) {
            count++;
        } else {
            if (head == NULL) {
                head = tail = malloc(sizeof(Node));
                head->data = currentCharacter;
                head->next = NULL;
            } else {
                tail->next = malloc(sizeof(Node));
                tail = tail->next;
                tail->data = currentCharacter;
                tail->next = NULL;
            }
            currentCharacter = str[i];
            count = 1;
        }
    }

    if (tail) {
        tail->next = NULL;
    }

    int compressedSize = 0;
    for (Node* node = head; node; node = node->next) {
        compressedSize++;
    }

    printf("Compressed size: %d\n", compressedSize);

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