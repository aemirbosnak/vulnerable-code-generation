//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    int state;
    char* input;
    int position;
} Parser;

Parser* parser_init(char* input) {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->state = 0;
    parser->input = input;
    parser->position = 0;

    return parser;
}

void parser_parse(Parser* parser) {
    switch (parser->state) {
        case 0:
            if (parser->input[parser->position] == '(') {
                parser->state = 1;
                parser->position++;
            } else if (parser->input[parser->position] == ')') {
                parser->state = 3;
                parser->position++;
            } else {
                printf("Syntax error\n");
            }
            break;

        case 1:
            if (parser->input[parser->position] == ')') {
                parser->state = 2;
                parser->position++;
            } else if (parser->input[parser->position] == ',') {
                parser->state = 1;
                parser->position++;
            } else {
                printf("Syntax error\n");
            }
            break;

        case 2:
            if (parser->input[parser->position] == ')') {
                parser->state = 3;
                parser->position++;
            } else {
                printf("Syntax error\n");
            }
            break;

        case 3:
            printf("Expression parsed successfully\n");
            break;
    }
}

int main() {
    char input[] = "((1,2),3)";
    Parser* parser = parser_init(input);
    parser_parse(parser);

    return 0;
}