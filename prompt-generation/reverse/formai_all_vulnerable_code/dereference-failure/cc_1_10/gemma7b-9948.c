//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void compress(char* str) {
    Node* head = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        insertAtTail(head, str[i]);
    }

    char* compressedStr = malloc(MAX_BUFFER_SIZE);

    int index = 0;

    Node* current = head;
    Node* previous = NULL;

    while (current) {
        int count = 1;

        while (previous && current->data == previous->data) {
            count++;
            previous = previous->next;
        }

        compressedStr[index++] = current->data;
        if (count > 1) {
            sprintf(compressedStr + index, "%d", count);
            index += strlen(compressedStr + index);
        }

        previous = current;
        current = current->next;
    }

    printf("%s", compressedStr);
}

int main() {
    char str[] = "aabbbbcccc";
    compress(str);

    return 0;
}