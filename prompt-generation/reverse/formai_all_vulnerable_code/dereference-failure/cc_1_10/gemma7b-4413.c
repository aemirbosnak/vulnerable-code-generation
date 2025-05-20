//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 255

typedef struct Node {
    char* identifier;
    struct Node* next;
} Node;

Node* parse_c_syntax(char* source) {
    // 1. Lexical Analysis
    char* identifier = NULL;
    Node* head = NULL;
    int i = 0;

    // Loop over the source code
    for (; source[i] != '\0'; i++) {
        // Identify an identifier
        if (source[i] >= 'a' && source[i] <= 'z') {
            if (identifier) {
                free(identifier);
            }
            identifier = malloc(MAX_IDENTIFIER_LENGTH);
            identifier[0] = source[i];
            i++;
            // Collect the identifier
            while (source[i] >= 'a' && source[i] <= 'z') {
                identifier[i - 0] = source[i];
                i++;
            }
            identifier[i - 0] = '\0';
            // Create a new node
            Node* new_node = malloc(sizeof(Node));
            new_node->identifier = identifier;
            new_node->next = head;
            head = new_node;
        }
    }

    return head;
}

int main() {
    char* source = "int main() { printf(\"Hello, world!\"); }";
    Node* head = parse_c_syntax(source);

    // Print the identifiers
    for (Node* node = head; node; node = node->next) {
        printf("%s\n", node->identifier);
    }

    return 0;
}