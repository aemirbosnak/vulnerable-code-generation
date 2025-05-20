//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* compress(char* str) {
    Node* head = NULL;
    int i = 0;
    char currentChar = str[0];
    int count = 1;

    for (i = 1; str[i] != '\0'; i++) {
        if (str[i] == currentChar) {
            count++;
        } else {
            if (head == NULL) {
                head = malloc(sizeof(Node));
                head->data = currentChar;
                head->next = NULL;
            } else {
                Node* newNode = malloc(sizeof(Node));
                newNode->data = currentChar;
                newNode->next = NULL;
                head->next = newNode;
                head = newNode;
            }
            currentChar = str[i];
            count = 1;
        }
    }

    return head;
}

int main() {
    char str[] = "aabbbbcccc";
    Node* head = compress(str);

    printf("Compressed string:");
    for (Node* node = head; node; node = node->next) {
        printf("%c", node->data);
    }

    printf("\n");

    return 0;
}