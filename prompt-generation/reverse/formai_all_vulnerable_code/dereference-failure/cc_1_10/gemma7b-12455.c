//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: intelligent
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
    char* str = "This is a string to be compressed";
    int strLen = strlen(str);

    // Create a linked list to store the characters of the string
    Node* head = NULL;
    for (int i = 0; i < strLen; i++) {
        insertAtTail(head, str[i]);
    }

    // Traverse the linked list and count the occurrences of each character
    int characterCounts[256] = {0};
    Node* current = head;
    while (current) {
        characterCounts[current->data]++;
        current = current->next;
    }

    // Create a compressed string
    char* compressedStr = (char*)malloc(strLen);
    int compressedStrIndex = 0;
    for (int i = 0; i < 256; i++) {
        if (characterCounts[i] > 0) {
            compressedStr[compressedStrIndex++] = (char)i;
            compressedStr[compressedStrIndex++] = (char)characterCounts[i];
        }
    }

    // Print the compressed string
    printf("Compressed string: %s", compressedStr);

    return 0;
}