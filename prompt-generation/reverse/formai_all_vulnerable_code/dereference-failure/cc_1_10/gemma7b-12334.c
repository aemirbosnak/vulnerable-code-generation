//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
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

    for (i = 0; str[i] != '\0'; i++) {
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

    int compressedSize = 0;
    for (head = head; head->next != NULL; head = head->next) {
        char count = 1;
        for (Node* current = head->next; current && current->data == head->data; current = current->next) {
            count++;
        }

        if (count > 1) {
            char buffer[MAX_BUFFER_SIZE];
            sprintf(buffer, "%c%d", head->data, count);
            strcat(str, buffer);
            compressedSize++;
        } else {
            str[compressedSize++] = head->data;
        }
    }

    str[compressedSize] = '\0';
}

int main() {
    char str[] = "aabbbbcccc";
    compress(str);
    printf("%s", str);

    return 0;
}