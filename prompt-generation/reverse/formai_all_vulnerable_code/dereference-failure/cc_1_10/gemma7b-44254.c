//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertNode(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void compress(char* str) {
    Node* head = NULL;
    insertNode(&head, str[0]);

    for (int i = 1; str[i] != '\0'; i++) {
        if (head->next != NULL && str[i] == head->next->data) {
            insertNode(&head, str[i]);
        } else {
            insertNode(&head, str[i]);
        }
    }

    int i = 0;
    char* compressedStr = (char*)malloc(MAX_BUFFER_SIZE);

    for (Node* node = head; node != NULL; node = node->next) {
        compressedStr[i++] = node->data;
    }

    printf("Compressed string: %s\n", compressedStr);
    free(compressedStr);
}

int main() {
    char str[] = "aabbbbcccc";
    compress(str);

    return 0;
}