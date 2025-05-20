//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct JSONParser {
    Node *root;
    int linenumber;
    char *current_key;
} JSONParser;

JSONParser *parser_init(int linenumber) {
    JSONParser *parser = malloc(sizeof(JSONParser));
    parser->root = NULL;
    parser->linenumber = linenumber;
    parser->current_key = NULL;
    return parser;
}

void parser_add_key(JSONParser *parser, char *key) {
    parser->current_key = key;
}

void parser_add_value(JSONParser *parser, char *value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(value);
    newNode->next = NULL;

    if (parser->root == NULL) {
        parser->root = newNode;
    } else {
        parser->root->next = newNode;
    }
}

void parser_close(JSONParser *parser) {
    free(parser);
}

int main() {
    JSONParser *parser = parser_init(1);

    parser_add_key(parser, "name");
    parser_add_value(parser, "John Doe");

    parser_add_key(parser, "age");
    parser_add_value(parser, "30");

    parser_add_key(parser, "interests");
    parser_add_value(parser, "Reading and Music");

    parser_close(parser);

    return 0;
}