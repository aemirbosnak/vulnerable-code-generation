//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LEN 256

typedef struct {
    char *expression;
    int currentIndex;
} Parser;

// Function prototypes
Parser *createParser(char *expression);
void freeParser(Parser *parser);
int parseExpression(Parser *parser);
int parseTerm(Parser *parser);
int parseFactor(Parser *parser);
void skipWhitespace(Parser *parser);
int getCurrentChar(Parser *parser);
int match(Parser *parser, char expected);
void handleError(const char *message);

// Create a new parser
Parser *createParser(char *expression) {
    Parser *parser = (Parser *)malloc(sizeof(Parser));
    parser->expression = strdup(expression);
    parser->currentIndex = 0;
    return parser;
}

// Free the parser memory
void freeParser(Parser *parser) {
    free(parser->expression);
    free(parser);
}

// Parse the entire expression and return the result
int parseExpression(Parser *parser) {
    int value = parseTerm(parser);
    while (1) {
        skipWhitespace(parser);
        char currentChar = getCurrentChar(parser);
        if (currentChar == '+' || currentChar == '-') {
            match(parser, currentChar);
            int nextTerm = parseTerm(parser);
            value = (currentChar == '+') ? value + nextTerm : value - nextTerm;
        } else {
            break;
        }
    }
    return value;
}

// Parse a term (factor * factor or factor / factor)
int parseTerm(Parser *parser) {
    int value = parseFactor(parser);
    while (1) {
        skipWhitespace(parser);
        char currentChar = getCurrentChar(parser);
        if (currentChar == '*' || currentChar == '/') {
            match(parser, currentChar);
            int nextFactor = parseFactor(parser);
            value = (currentChar == '*') ? value * nextFactor : value / nextFactor;
        } else {
            break;
        }
    }
    return value;
}

// Parse a factor (number or (expression))
int parseFactor(Parser *parser) {
    skipWhitespace(parser);
    char currentChar = getCurrentChar(parser);
    
    if (isdigit(currentChar)) {
        int start = parser->currentIndex;
        while (isdigit(getCurrentChar(parser))) {
            match(parser, getCurrentChar(parser));
        }
        char *numberStr = strndup(parser->expression + start, parser->currentIndex - start);
        int number = atoi(numberStr);
        free(numberStr);
        return number;
    } else if (currentChar == '(') {
        match(parser, '(');
        int value = parseExpression(parser);
        match(parser, ')');
        return value;
    } else {
        handleError("Unexpected character in input");
        return 0; // Unreachable, but avoids warnings
    }
}

// Skip whitespace characters
void skipWhitespace(Parser *parser) {
    while (isspace(getCurrentChar(parser))) {
        parser->currentIndex++;
    }
}

// Get current character from the expression
int getCurrentChar(Parser *parser) {
    return parser->expression[parser->currentIndex];
}

// Match the current character with the expected one
int match(Parser *parser, char expected) {
    if (getCurrentChar(parser) == expected) {
        parser->currentIndex++;
        return 1;
    } else {
        handleError("Unexpected character encountered");
        return 0; // Unreachable, but avoids warnings
    }
}

// Handle error and print message
void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Main function
int main() {
    char expression[MAX_EXPR_LEN];
    
    printf("Enter an arithmetic expression: ");
    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        handleError("Failed to read input");
    }
    
    // Remove trailing newline character from input
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    Parser *parser = createParser(expression);
    int result = parseExpression(parser);
    printf("Result: %d\n", result);
    
    freeParser(parser);
    return 0;
}