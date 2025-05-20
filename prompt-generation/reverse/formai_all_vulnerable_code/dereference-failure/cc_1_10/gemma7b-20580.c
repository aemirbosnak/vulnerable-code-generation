//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 255

typedef struct Node {
    char *identifier;
    struct Node *next;
} Node;

Node *parse_c_syntax(char *source) {
    Node *head = NULL;
    char *p = source;
    char identifier[MAX_IDENTIFIER_LENGTH];

    while (*p) {
        // Identifier
        if (*p >= 'a' && *p <= 'z') {
            *identifier = *p;
            p++;
            while (*p >= 'a' && *p <= 'z') {
                *identifier = *p;
                p++;
            }
            Node *node = malloc(sizeof(Node));
            node->identifier = identifier;
            node->next = head;
            head = node;
        }

        // Operators
        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            p++;
        }

        // Comments
        else if (*p == '/' && *(p + 1) == '*') {
            p++;
            while (*p != '*' || *p == '/') {
                p++;
            }
        }

        // Other punctuation
        else if (*p == '(' || *p == ')') {
            p++;
        }
    }

    return head;
}

int main() {
    char *source = "int main() { printf(\"Hello, world!\"); }";
    Node *head = parse_c_syntax(source);

    for (Node *node = head; node; node = node->next) {
        printf("%s ", node->identifier);
    }

    printf("\n");

    return 0;
}