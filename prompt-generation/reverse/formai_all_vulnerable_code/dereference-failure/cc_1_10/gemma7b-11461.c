//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LL long long

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    int state;
    char current_symbol;
} Parser;

void initializeParser(Parser* parser) {
    parser->head = NULL;
    parser->state = 0;
    parser->current_symbol = '\0';
}

void addSymbolToParser(Parser* parser, char symbol) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = symbol;
    newNode->next = NULL;

    if (parser->head == NULL) {
        parser->head = newNode;
    } else {
        parser->head->next = newNode;
        parser->head = newNode;
    }
}

void parseExpression(Parser* parser) {
    switch (parser->state) {
        case 0:
            if (parser->current_symbol == '(') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 1;
            } else if (parser->current_symbol == ')') {
                parser->state = 2;
            } else if (parser->current_symbol == '+') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == '-') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == '*') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 4;
            } else if (parser->current_symbol == '/') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 4;
            } else {
                printf("Error: invalid syntax\n");
            }
            break;
        case 1:
            if (parser->current_symbol == ')') {
                parser->state = 0;
            } else if (parser->current_symbol == '+') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == '-') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == '*') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 4;
            } else if (parser->current_symbol == '/') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 4;
            } else {
                printf("Error: invalid syntax\n");
            }
            break;
        case 2:
            if (parser->current_symbol == ')') {
                parser->state = 0;
            } else {
                printf("Error: invalid syntax\n");
            }
            break;
        case 3:
            if (parser->current_symbol == '+') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == '-') {
                addSymbolToParser(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == ')') {
                parser->state = 2;
            } else {
                printf("Error: invalid syntax\n");
            }
            break;
        case 4:
            if (parser->current_symbol == ')') {
                parser->state = 2;
            } else {
                printf("Error: invalid syntax\n");
            }
            break;
    }
}

int main() {
    Parser parser;
    initializeParser(&parser);

    printf("Enter an expression: ");
    scanf("%c", &parser.current_symbol);

    parseExpression(&parser);

    if (parser.state == 0) {
        printf("Expression parsed successfully!\n");
    } else {
        printf("Error: invalid syntax\n");
    }

    return 0;
}