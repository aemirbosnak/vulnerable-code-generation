//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void compress(char* str) {
    Node* head = NULL;
    Node* tail = NULL;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (head == NULL) {
            head = tail = malloc(sizeof(Node));
            head->data = str[i];
            head->next = NULL;
        } else if (str[i] == tail->data) {
            tail->next = malloc(sizeof(Node));
            tail = tail->next;
            tail->data = str[i];
            tail->next = NULL;
        } else {
            tail->next = malloc(sizeof(Node));
            tail = tail->next;
            tail->data = str[i];
            tail->next = NULL;
            head = tail;
        }
    }

    char* compressed_str = malloc(sizeof(char) * (tail->next - head) + 1);
    int j = 0;

    for (Node* node = head; node->next != NULL; node = node->next) {
        compressed_str[j++] = node->data;
    }

    compressed_str[j] = '\0';

    printf("Compressed string: %s\n", compressed_str);
    free(compressed_str);
    free(head);
}

int main() {
    char str[] = "aabbbbcccccaa";
    compress(str);

    return 0;
}