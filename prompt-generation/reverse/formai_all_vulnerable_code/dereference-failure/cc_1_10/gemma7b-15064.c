//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void compress(char* str) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = str[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    char* compressedStr = (char*)malloc(MAX_BUFFER_SIZE);

    int index = 0;
    tail = head;

    while (tail) {
        int count = 0;
        char currentChar = tail->data;

        while (tail && tail->data == currentChar) {
            count++;
            tail = tail->next;
        }

        compressedStr[index++] = currentChar;
        compressedStr[index++] = count - 1;
    }

    printf("%s", compressedStr);
}

int main() {
    char str[] = "AABBCCDD";
    compress(str);

    return 0;
}