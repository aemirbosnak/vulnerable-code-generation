//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
#define TOKEN_EOF           0
#define TOKEN_IDENTIFIER    1
#define TOKEN_CONSTANT      2
#define TOKEN_KEYWORD       3
#define TOKEN_OPERATOR       4
#define TOKEN_PUNCTUATOR    5

// Keywords
static const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while"
};

// Operators
static const char *operators[] = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^",
    "<<", ">>", "++", "--", ",", ";", ":", "?", "#", "##"
};

// Punctuators
static const char *punctuators[] = {
    "{", "}", "(", ")", "[", "]", ".", "&.", "->", "*", "&", ",", ";", ":", "?", "#", "##"
};

// Scanner
typedef struct {
    const char *source;
    const char *current;
    int line;
    int column;
} Scanner;

// Token
typedef struct {
    int type;
    char *value;
} Token;

// Scanner functions
Scanner *scanner_create(const char *source) {
    Scanner *scanner = malloc(sizeof(Scanner));
    scanner->source = source;
    scanner->current = source;
    scanner->line = 1;
    scanner->column = 1;
    return scanner;
}

void scanner_destroy(Scanner *scanner) {
    free(scanner);
}

Token *scanner_next(Scanner *scanner) {
    while (*scanner->current) {
        // Skip whitespace
        while (*scanner->current == ' ' || *scanner->current == '\t' || *scanner->current == '\r' || *scanner->current == '\n') {
            if (*scanner->current == '\n') {
                scanner->line++;
                scanner->column = 1;
            } else {
                scanner->column++;
            }
            scanner->current++;
        }

        // Check for end of file
        if (*scanner->current == '\0') {
            return NULL;
        }

        // Check for identifier
        if (isalpha(*scanner->current) || *scanner->current == '_') {
            char *value = malloc(1024);
            int size = 0;
            while (isalnum(*scanner->current) || *scanner->current == '_') {
                value[size++] = *scanner->current++;
            }
            value[size] = '\0';
            return malloc(sizeof(Token));
        }

        // Check for constant
        if (isdigit(*scanner->current)) {
            char *value = malloc(1024);
            int size = 0;
            while (isdigit(*scanner->current)) {
                value[size++] = *scanner->current++;
            }
            value[size] = '\0';
            return malloc(sizeof(Token));
        }

        // Check for keyword
        for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
            if (strcmp(scanner->current, keywords[i]) == 0) {
                return malloc(sizeof(Token));
            }
        }

        // Check for operator
        for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
            if (strcmp(scanner->current, operators[i]) == 0) {
                return malloc(sizeof(Token));
            }
        }

        // Check for punctuator
        for (int i = 0; i < sizeof(punctuators) / sizeof(punctuators[0]); i++) {
            if (strcmp(scanner->current, punctuators[i]) == 0) {
                return malloc(sizeof(Token));
            }
        }

        // Unknown token
        scanner->current++;
    }

    return NULL;
}

// Parser
typedef struct {
    Scanner *scanner;
    Token *current;
} Parser;

// Parser functions
Parser *parser_create(Scanner *scanner) {
    Parser *parser = malloc(sizeof(Parser));
    parser->scanner = scanner;
    parser->current = NULL;
    return parser;
}

void parser_destroy(Parser *parser) {
    free(parser);
}

Token *parser_next(Parser *parser) {
    if (parser->current == NULL) {
        parser->current = scanner_next(parser->scanner);
    }
    return parser->current;
}

Token *parser_current(Parser *parser) {
    return parser->current;
}

// Main function
int main(void) {
    // Create scanner
    Scanner *scanner = scanner_create("int main(void) { return 0; }");

    // Create parser
    Parser *parser = parser_create(scanner);

    // Parse tokens
    while (parser_current(parser) != NULL) {
        Token *token = parser_next(parser);
        printf("%s\n", token->value);
        free(token);
    }

    // Destroy parser
    parser_destroy(parser);

    // Destroy scanner
    scanner_destroy(scanner);

    return 0;
}