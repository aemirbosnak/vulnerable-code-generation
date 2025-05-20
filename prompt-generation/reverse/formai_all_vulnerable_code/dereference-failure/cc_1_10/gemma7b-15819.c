//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    char* str = "HELLO, WORLD!";
    int strLen = strlen(str);

    Node* head = NULL;
    for (int i = 0; i < strLen; i++) {
        insertAtTail(head, str[i]);
    }

    int compressedLen = 0;
    Node* current = head;
    char previous = '\0';
    char currentChar = '\0';
    while (current) {
        currentChar = current->data;
        if (previous == currentChar) {
            compressedLen++;
        } else {
            previous = currentChar;
            compressedLen++;
        }
        current = current->next;
    }

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", str);
    printf("Number of characters compressed: %d\n", compressedLen - strLen);

    return 0;
}