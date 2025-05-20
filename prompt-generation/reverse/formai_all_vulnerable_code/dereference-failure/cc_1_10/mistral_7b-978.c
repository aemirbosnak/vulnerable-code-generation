//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 255

typedef struct Node {
    char data[MAX_CHAR];
    struct Node *next;
} Node;

void sanitizeInput(char *input) {
    int i;

    // Remove leading and trailing whitespaces
    for (i = 0; isspace(input[i]); i++) {
        input[i] = '\0';
    }
    for (i = strlen(input) - 1; isspace(input[i]); i--) {
        input[i] = '\0';
    }

    // Sanitize input
    for (i = 0; input[i]; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            // Uppercase character
            continue;
        }
        if (input[i] >= 'a' && input[i] <= 'z') {
            // Lowercase character
            continue;
        }
        if (input[i] == '.' || input[i] == '-' || input[i] == '_') {
            // Valid characters for URLs
            continue;
        }
        if (input[i] == ' ') {
            // Space character
            continue;
        }

        // Invalid character
        printf("Invalid character '%c' detected! Exiting...\n", input[i]);
        exit(EXIT_FAILURE);
    }
}

int main() {
    Node *inputList = NULL;
    char userInput[MAX_CHAR];

    while (1) {
        printf("Enter your input: ");
        fgets(userInput, sizeof(userInput), stdin);

        // Remove newline character from fgets()
        userInput[strcspn(userInput, "\n")] = '\0';

        // Sanitize user input
        sanitizeInput(userInput);

        // Allocate memory for user input and store it in the linked list
        Node *newNode = (Node *)malloc(sizeof(Node));
        strcpy(newNode->data, userInput);
        newNode->next = inputList;
        inputList = newNode;

        printf("Input sanitized and stored successfully.\n");
    }

    return 0;
}