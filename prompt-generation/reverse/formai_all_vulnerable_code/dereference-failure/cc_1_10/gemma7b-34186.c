//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void parseJson(char *jsonString) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    strcpy(buffer, jsonString);

    Node *head = NULL;
    Node *tail = NULL;

    // Tokenize the JSON string
    char *token = strtok(buffer, ":");

    // Parse each token
    while (token) {
        // Create a new node
        Node *newNode = malloc(sizeof(Node));
        newNode->data = strdup(token);
        newNode->next = NULL;

        // If the head is NULL, make it the head of the list
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        // Get the next token
        token = strtok(NULL, ":");
    }

    // Free the memory allocated for the buffer and the nodes
    free(buffer);
    free(head);
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(jsonString);

    return 0;
}