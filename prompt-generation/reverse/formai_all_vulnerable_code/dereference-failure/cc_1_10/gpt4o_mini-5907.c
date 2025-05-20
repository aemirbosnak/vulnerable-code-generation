//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LENGTH 100

typedef struct {
    char *expression;
    int currentPos;
} Parser;

void initParser(Parser *parser, const char *expr) {
    parser->expression = malloc(strlen(expr) + 1);
    strcpy(parser->expression, expr);
    parser->currentPos = 0;
}

void freeParser(Parser *parser) {
    free(parser->expression);
}

char getCurrentChar(Parser *parser) {
    return parser->expression[parser->currentPos];
}

void advanceParser(Parser *parser) {
    parser->currentPos++;
}

int isAtEnd(Parser *parser) {
    return getCurrentChar(parser) == '\0';
}

void skipWhitespace(Parser *parser) {
    while (isspace(getCurrentChar(parser))) {
        advanceParser(parser);
    }
}

int parseNumber(Parser *parser) {
    int start = parser->currentPos;

    while (isdigit(getCurrentChar(parser))) {
        advanceParser(parser);
    }

    int length = parser->currentPos - start;
    char numStr[length + 1];
    strncpy(numStr, &parser->expression[start], length);
    numStr[length] = '\0';

    return atoi(numStr);
}

int parseFactor(Parser *parser);

int parseTerm(Parser *parser) {
    int result = parseFactor(parser);

    while (!isAtEnd(parser)) {
        skipWhitespace(parser);
        char op = getCurrentChar(parser);
        if (op == '*' || op == '/') {
            advanceParser(parser);
            skipWhitespace(parser);
            int nextFactor = parseFactor(parser);
            result = (op == '*') ? result * nextFactor : result / nextFactor;
        } else {
            break;
        }
    }

    return result;
}

int parseFactor(Parser *parser) {
    skipWhitespace(parser);
    char c = getCurrentChar(parser);

    if (isdigit(c)) {
        return parseNumber(parser);
    } else if (c == '(') {
        advanceParser(parser);
        int result = parseTerm(parser);
        advanceParser(parser); // Skipping the closing ')'
        return result;
    }

    fprintf(stderr, "Unexpected character: %c\n", c);
    exit(EXIT_FAILURE);
}

int parseExpression(Parser *parser) {
    skipWhitespace(parser);
    
    int result = parseTerm(parser);

    while (!isAtEnd(parser)) {
        skipWhitespace(parser);
        char op = getCurrentChar(parser);
        if (op == '+' || op == '-') {
            advanceParser(parser);
            skipWhitespace(parser);
            int nextTerm = parseTerm(parser);
            result = (op == '+') ? result + nextTerm : result - nextTerm;
        } else {
            break;
        }
    }

    return result;
}

int main() {
    char input[MAX_EXPR_LENGTH];

    printf("Enter a mathematical expression (e.g., 3 + 5 * (2 - 8)): ");
    fgets(input, MAX_EXPR_LENGTH, stdin);

    Parser parser;
    initParser(&parser, input);

    int result = parseExpression(&parser);
    printf("Result: %d\n", result);

    freeParser(&parser);

    return 0;
}