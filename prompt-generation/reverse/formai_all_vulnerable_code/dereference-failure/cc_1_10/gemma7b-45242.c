//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

int main() {
    char str[] = "ROMEO AND JULIET";
    Node* head = NULL;
    Node* tail = NULL;

    // Convert the string into a linked list
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

    // Compress the linked list
    tail = head;
    int count = 1;
    while (tail->next) {
        int currentLetterCount = 0;
        Node* currentNode = head;

        while (currentNode && currentNode->data == tail->data) {
            currentLetterCount++;
            currentNode = currentNode->next;
        }

        if (currentLetterCount > 1) {
            tail->data = currentLetterCount - 1 + 'a';
            count++;
        } else {
            tail = tail->next;
        }
    }

    // Print the compressed linked list
    Node* compressedHead = head;
    while (compressedHead) {
        printf("%c ", compressedHead->data);
        compressedHead = compressedHead->next;
    }

    // Calculate the compression ratio
    int compressionRatio = (count - 1) * 100 / strlen(str);

    // Print the compression ratio
    printf("\nCompression ratio: %d%%", compressionRatio);

    return 0;
}