//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: statistical
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
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int compressedSize = tail->next == NULL ? 1 : tail->next->next == NULL ? 2 : tail->next->next->next == NULL ? 3 : MAX_BUFFER_SIZE;

    str = malloc(compressedSize);
    head = tail = NULL;

    for (int i = 0; head->data != '\0'; i++) {
        str[i] = head->data;
        free(head);
        head = tail->next;
    }

    free(tail);
}

int main() {
    char str[] = "aabbbbcccccaa";
    compress(str);
    printf("%s", str);

    return 0;
}