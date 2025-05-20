//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
    }
}

char* compress(char* str) {
    Node* head = NULL;
    char* compressedStr = malloc(MAX_BUFFER_SIZE);
    int i = 0;

    for (char* p = str; *p != '\0'; p++) {
        insertAtTail(&head, *p);
    }

    for (Node* node = head; node != NULL; node++) {
        compressedStr[i++] = node->data;

        if (node->next != NULL) {
            compressedStr[i++] = (node->next->data - node->data) + 1;
        }
    }

    return compressedStr;
}

int main() {
    char* str = "aabbbbcccc";
    char* compressedStr = compress(str);

    printf("%s", compressedStr);

    return 0;
}