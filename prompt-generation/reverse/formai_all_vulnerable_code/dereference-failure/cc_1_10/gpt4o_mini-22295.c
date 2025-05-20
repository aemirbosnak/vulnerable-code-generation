//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Token {
    char type[20];
    char value[MAX_SIZE];
} Token;

typedef struct Parser {
    int position;
    Token tokens[MAX_SIZE];
    int tokenCount;
} Parser;

// Function to initialize parser
void initParser(Parser* parser) {
    parser->position = 0;
    parser->tokenCount = 0;
}

// Function to add a token to the parser
void addToken(Parser* parser, const char* type, const char* value) {
    strcpy(parser->tokens[parser->tokenCount].type, type);
    strcpy(parser->tokens[parser->tokenCount].value, value);
    parser->tokenCount++;
}

// Function to display tokens
void displayTokens(Parser* parser) {
    printf("Tokens:\n");
    for (int i = 0; i < parser->tokenCount; i++) {
        printf("Type: %s, Value: %s\n", parser->tokens[i].type, parser->tokens[i].value);
    }
}

// A simple function to check if a character is a digit
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// A simple function to check if a character is an alphabetic
bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to tokenize input string
void tokenize(Parser* parser, const char* input) {
    char buffer[MAX_SIZE];
    int bufIndex = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\n') {
            if (bufIndex > 0) {
                buffer[bufIndex] = '\0';
                if (isDigit(buffer[0])) {
                    addToken(parser, "NUMBER", buffer);
                } else if (isAlpha(buffer[0])) {
                    addToken(parser, "IDENTIFIER", buffer);
                } else {
                    addToken(parser, "UNKNOWN", buffer);
                }
                bufIndex = 0; // reset buffer index for next token
            }
        } else {
            buffer[bufIndex++] = input[i];
        }
    }
    
    // Handle the last token if there is no trailing space
    if (bufIndex > 0) {
        buffer[bufIndex] = '\0';
        if (isDigit(buffer[0])) {
            addToken(parser, "NUMBER", buffer);
        } else if (isAlpha(buffer[0])) {
            addToken(parser, "IDENTIFIER", buffer);
        } else {
            addToken(parser, "UNKNOWN", buffer);
        }
    }
}

// Function to parse expressions
void parseExpression(Parser* parser) {
    printf("Parsing Expression:\n");
    for (int i = 0; i < parser->tokenCount; i++) {
        if (strcmp(parser->tokens[i].type, "IDENTIFIER") == 0) {
            printf("Found Identifier: %s\n", parser->tokens[i].value);
        } else if (strcmp(parser->tokens[i].type, "NUMBER") == 0) {
            printf("Found Number: %s\n", parser->tokens[i].value);
        } else {
            printf("Found Unknown Token: %s\n", parser->tokens[i].value);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s '<input_string>'\n", argv[0]);
        return EXIT_FAILURE;
    }

    Parser parser;
    initParser(&parser);
    
    tokenize(&parser, argv[1]);
    displayTokens(&parser);
    parseExpression(&parser);

    return EXIT_SUCCESS;
}