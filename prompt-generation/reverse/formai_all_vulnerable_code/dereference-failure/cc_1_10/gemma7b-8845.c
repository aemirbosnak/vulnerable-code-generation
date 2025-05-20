//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: expert-level
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

    // Create a linked list to store the unique characters
    while (str[i] != '\0') {
        char currentChar = str[i];
        Node* newNode = malloc(sizeof(Node));
        newNode->data = currentChar;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        // Increment the count of occurrences of the character
        while (str[i] == currentChar) {
            count++;
            i++;
        }

        // Insert the character and its count into the compressed string
        char compressedChar = currentChar + count - 1;
        str[i] = compressedChar;
        i++;
    }

    // Free the memory allocated for the linked list
    free(head);
}

int main() {
    char str[] = "aabbbbcccc";
    compress(str);
    printf("%s", str);

    return 0;
}