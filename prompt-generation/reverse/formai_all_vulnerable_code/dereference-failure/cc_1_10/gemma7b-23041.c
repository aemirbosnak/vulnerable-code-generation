//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
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
    char* ptr = str;
    int count = 1;

    while (*ptr) {
        if (head == NULL) {
            head = tail = malloc(sizeof(Node));
            head->data = *ptr;
            head->next = NULL;
        } else if (*ptr == tail->data) {
            count++;
        } else {
            tail->next = malloc(sizeof(Node));
            tail = tail->next;
            tail->data = *ptr;
            tail->next = NULL;
            count = 1;
        }

        ptr++;
    }

    int compressed_size = 0;
    for (Node* node = head; node; node = node->next) {
        compressed_size++;
    }

    printf("Compressed size: %d\n", compressed_size);

    char* compressed_str = malloc(compressed_size);
    ptr = compressed_str;

    for (Node* node = head; node; node = node->next) {
        *ptr++ = node->data;
    }

    printf("Compressed string: %s\n", compressed_str);

    free(head);
    free(compressed_str);
}

int main() {
    char str[] = "aabbbbcccccaa";
    compress(str);

    return 0;
}