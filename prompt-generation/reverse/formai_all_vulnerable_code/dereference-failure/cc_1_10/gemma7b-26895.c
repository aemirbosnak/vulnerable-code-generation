//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDENTIFIER_LENGTH 255

typedef struct Node {
    char *identifier;
    struct Node *next;
} Node;

Node *parse_c_syntax(char *source) {
    Node *head = NULL;
    Node *tail = NULL;

    // Lexical analysis
    char *identifier = NULL;
    int i = 0;
    for (; source[i] != '\0'; i++) {
        if (source[i] >= 'a' && source[i] <= 'z') {
            // Identifier start
            identifier = malloc(MAX_IDENTIFIER_LENGTH);
            identifier[0] = source[i];
            i++;
            while (source[i] >= 'a' && source[i] <= 'z') {
                identifier[i] = source[i];
                i++;
            }
            identifier[i] = '\0';

            // Create a new node
            Node *newNode = malloc(sizeof(Node));
            newNode->identifier = identifier;
            newNode->next = NULL;

            // Add the new node to the end of the list
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    return head;
}

int main() {
    char *source = "int main() { printf(\"Hello, world!\"); }";
    Node *head = parse_c_syntax(source);

    // Print the identifier of each node
    for (Node *node = head; node != NULL; node = node->next) {
        printf("%s\n", node->identifier);
    }

    return 0;
}