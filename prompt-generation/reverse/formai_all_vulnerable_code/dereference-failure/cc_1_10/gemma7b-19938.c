//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDENTIFIER_LENGTH 256

typedef struct Node {
    char identifier[MAX_IDENTIFIER_LENGTH];
    struct Node* next;
} Node;

Node* parse_c_syntax(char* source) {
    Node* head = NULL;
    Node* current = NULL;

    // Lexical analysis
    char* identifier = NULL;
    int state = 0; // 0 - normal, 1 - in identifier, 2 - quoted string

    for (int i = 0; source[i] != '\0'; i++) {
        switch (state) {
            case 0:
                if (isalnum(source[i])) {
                    state = 1;
                    identifier = malloc(MAX_IDENTIFIER_LENGTH);
                    identifier[0] = source[i];
                } else if (source[i] == '"') {
                    state = 2;
                } else if (source[i] == ')') {
                    head = insert_node(head, identifier);
                    state = 0;
                }
                break;
            case 1:
                if (isalnum(source[i])) {
                    identifier = realloc(identifier, MAX_IDENTIFIER_LENGTH * (i + 1));
                    identifier[i] = source[i];
                } else if (source[i] == '"') {
                    state = 0;
                    identifier = NULL;
                } else if (source[i] == ')') {
                    head = insert_node(head, identifier);
                    state = 0;
                }
                break;
            case 2:
                if (source[i] == '"') {
                    state = 0;
                }
                break;
        }
    }

    return head;
}

int insert_node(Node* head, char* identifier) {
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->identifier, identifier);
    new_node->next = head;
    head = new_node;
    return head;
}

int main() {
    char* source = "int main() { return 0; }";
    Node* head = parse_c_syntax(source);

    for (Node* current = head; current; current = current->next) {
        printf("%s\n", current->identifier);
    }

    return 0;
}