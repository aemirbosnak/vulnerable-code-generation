//Gemma-7B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Error {
    char* message;
    int code;
} Error;

Error* createError(int code, char* message) {
    Error* error = malloc(sizeof(Error));
    error->message = strdup(message);
    error->code = code;
    return error;
}

void handleError(Error* error) {
    fprintf(stderr, "Error: %s (code: %d)\n", error->message, error->code);
    exit(error->code);
}

Node* insertNode(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    head->next = newNode;
    return newNode;
}

int main() {
    Node* head = NULL;

    char data = 'a';
    insertNode(head, data);

    data = 'b';
    insertNode(head, data);

    data = 'c';
    insertNode(head, data);

    data = 'd';
    insertNode(head, data);

    return 0;
}