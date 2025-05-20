//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char** yytext;
    int yyline;
    int yylex_lineno;
} Parser;

Parser* parser_init() {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->yytext = NULL;
    parser->yyline = 0;
    parser->yylex_lineno = 0;
    return parser;
}

void parser_parse(Parser* parser, char* str) {
    Node* node = malloc(sizeof(Node));
    node->data = str[0];
    node->next = NULL;

    if (parser->head == NULL) {
        parser->head = node;
    } else {
        parser->head->next = node;
        parser->head = node;
    }

    parser->yytext = &str;
    parser->yyline++;
    parser->yylex_lineno++;
}

void parser_print(Parser* parser) {
    Node* node = parser->head;
    while (node) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Parser* parser = parser_init();
    parser_parse(parser, "abc");
    parser_parse(parser, "123");
    parser_print(parser);

    return 0;
}