//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: innovative
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
    char prevChar = '\0';
    char count = 1;

    for (i = 0; str[i] != '\0'; i++) {
        if (prevChar == str[i]) {
            count++;
        } else {
            if (head == NULL) {
                head = tail = malloc(sizeof(Node));
                head->data = str[i];
                head->next = NULL;
            } else {
                tail->next = malloc(sizeof(Node));
                tail = tail->next;
                tail->data = str[i];
                tail->next = NULL;
            }
            prevChar = str[i];
            count = 1;
        }
    }

    if (tail) {
        tail->next = NULL;
    }

    int compressedSize = 0;
    for (head = head; head; head = head->next) {
        compressedSize++;
    }

    printf("Original string: %s\n", str);
    printf("Compressed string: ");
    for (head = head; head; head = head->next) {
        printf("%c", head->data);
    }
    printf("\n");
    printf("Compressed size: %d\n", compressedSize);
}

int main() {
    char str[] = "aabbbbcccccaaa";
    compress(str);

    return 0;
}