//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 255

typedef struct Node {
    char *identifier;
    struct Node *next;
} Node;

Node *parse_c_syntax(char *c_code) {
    Node *head = NULL;
    char *identifier = NULL;
    char *current_position = c_code;
    int state = 0;

    while (current_position && *current_position) {
        switch (state) {
            case 0:
                if (*current_position == '{' || *current_position == '}' || *current_position == ';') {
                    state = 1;
                } else if (isalnum(*current_position)) {
                    identifier = malloc(MAX_IDENTIFIER_LENGTH);
                    identifier[0] = *current_position;
                    state = 2;
                }
                break;
            case 1:
                if (identifier) {
                    Node *new_node = malloc(sizeof(Node));
                    new_node->identifier = identifier;
                    new_node->next = head;
                    head = new_node;
                }
                state = 0;
                break;
            case 2:
                if (identifier) {
                    identifier[strlen(identifier) - 1] = '\0';
                    Node *new_node = malloc(sizeof(Node));
                    new_node->identifier = identifier;
                    new_node->next = head;
                    head = new_node;
                }
                state = 0;
                break;
        }

        current_position++;
    }

    return head;
}

int main() {
    char *c_code = "int main() { printf(\"Hello, world!\"); }";
    Node *head = parse_c_syntax(c_code);

    for (Node *node = head; node; node = node->next) {
        printf("%s\n", node->identifier);
    }

    return 0;
}