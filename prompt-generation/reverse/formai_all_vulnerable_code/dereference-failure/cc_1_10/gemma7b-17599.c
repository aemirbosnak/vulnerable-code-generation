//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
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
    int count = 1;

    while (str[i] != '\0') {
        if (head == NULL) {
            head = malloc(sizeof(Node));
            head->data = str[i];
            head->next = NULL;
        } else if (str[i] == str[i-1]) {
            count++;
        } else {
            Node* newNode = malloc(sizeof(Node));
            newNode->data = str[i];
            newNode->next = NULL;
            head->next = newNode;
            head = newNode;
            count = 1;
        }
        i++;
    }

    return head;
}

void decompress(Node* node) {
    char* str = malloc(MAX_BUFFER_SIZE);
    int i = 0;

    while (node) {
        str[i] = node->data;
        node = node->next;
        i++;
    }

    str[i] = '\0';

    printf("%s", str);
    free(str);
}

int main() {
    char* str = "aabbbbcccc";
    Node* node = compress(str);
    decompress(node);

    return 0;
}