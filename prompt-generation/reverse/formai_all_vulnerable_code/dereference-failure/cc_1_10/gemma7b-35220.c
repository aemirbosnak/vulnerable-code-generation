//Gemma-7B DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* newNode(char data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    Node* head = NULL;
    char input[MAX_SIZE];

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Malformed input handling
    if (input[0] == '\0' || input[0] == '\n') {
        perror("Input error: string is empty");
        exit(1);
    }

    // Memory allocation error handling
    head = newNode(input[0]);
    if (head == NULL) {
        perror("Memory error: unable to allocate memory for node");
        exit(1);
    }

    // Build the linked list
    for (int i = 1; input[i] != '\0'; i++) {
        newNode(input[i])
            ->next = head;
        head = newNode(input[i]);
    }

    // Print the linked list
    head = newNode(input[0]);
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }

    return 0;
}