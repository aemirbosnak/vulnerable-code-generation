//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 20
#define MAX_STATEMENT_LENGTH 200

typedef struct Node {
    char *identifier;
    struct Node *next;
} Node;

typedef struct Statement {
    char *statement;
    struct Statement *next;
} Statement;

void parse_c_syntax(char *source) {
    // Lexical analysis
    Node *identifier_list = NULL;
    Statement *statement_list = NULL;
    char *token = strtok(source, " ");
    while (token) {
        // Identifier
        if (isupper(token[0])) {
            Node *new_node = malloc(sizeof(Node));
            new_node->identifier = strdup(token);
            new_node->next = identifier_list;
            identifier_list = new_node;
        }
        // Statement
        else if (islower(token[0])) {
            Statement *new_statement = malloc(sizeof(Statement));
            new_statement->statement = strdup(token);
            new_statement->next = statement_list;
            statement_list = new_statement;
        }
        token = strtok(NULL, " ");
    }

    // Syntax analysis
    // ...

    // Free memory
    free(identifier_list);
    free(statement_list);
}

int main() {
    char *source = "int main() { printf(\"Hello, world!\"); }";
    parse_c_syntax(source);

    return 0;
}