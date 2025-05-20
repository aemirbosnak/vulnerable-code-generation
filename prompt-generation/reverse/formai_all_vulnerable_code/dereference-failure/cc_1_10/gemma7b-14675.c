//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: irregular
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
    char* str1 = "This is a sample string to be compressed.";
    char* str2;
    int strLen = strlen(str1);

    // Create a linked list to store the unique characters in str1
    Node* head = NULL;
    for (int i = 0; i < strLen; i++) {
        insertAtTail(head, str1[i]);
    }

    // Calculate the number of unique characters
    int uniqueChars = head->next == NULL ? 1 : head->next->next == NULL ? 2 : head->next->next->next == NULL ? 3 : -1;

    // Allocate memory for str2
    str2 = (char*)malloc(uniqueChars + 1);

    // Compress str1 into str2
    int i = 0;
    for (Node* node = head; node; node = node->next) {
        str2[i++] = node->data;
    }

    str2[i] = '\0';

    // Print str2
    printf("%s\n", str2);

    return 0;
}