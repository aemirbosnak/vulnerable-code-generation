//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
enum Token_Type {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD,
    TOKEN_PUNCTUATOR
};

// Token structure
typedef struct Token {
    enum Token_Type type;
    char *value;
} Token;

// Lexer state
typedef struct Lexer {
    char *input;
    char *current;
    int line;
    int column;
} Lexer;

// Create a new lexer
Lexer *new_lexer(char *input) {
    Lexer *lexer = malloc(sizeof(Lexer));
    lexer->input = input;
    lexer->current = input;
    lexer->line = 1;
    lexer->column = 0;
    return lexer;
}

// Get the next token
Token *next_token(Lexer *lexer) {
    Token *token = malloc(sizeof(Token));

    // Skip whitespace
    while (*lexer->current == ' ' || *lexer->current == '\t' || *lexer->current == '\n' || *lexer->current == '\r') {
        if (*lexer->current == '\n') {
            lexer->line++;
            lexer->column = 0;
        }
        lexer->current++;
        lexer->column++;
    }

    // Check for end of file
    if (*lexer->current == '\0') {
        token->type = TOKEN_EOF;
        token->value = NULL;
        return token;
    }

    // Check for identifiers
    if (isalpha(*lexer->current) || *lexer->current == '_') {
        char *start = lexer->current;
        while (isalnum(*lexer->current) || *lexer->current == '_') {
            lexer->current++;
            lexer->column++;
        }
        int length = lexer->current - start;
        char *value = malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
        token->type = TOKEN_IDENTIFIER;
        token->value = value;
        return token;
    }

    // Check for numbers
    if (isdigit(*lexer->current)) {
        char *start = lexer->current;
        while (isdigit(*lexer->current)) {
            lexer->current++;
            lexer->column++;
        }
        int length = lexer->current - start;
        char *value = malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
        token->type = TOKEN_NUMBER;
        token->value = value;
        return token;
    }

    // Check for strings
    if (*lexer->current == '"') {
        lexer->current++;
        lexer->column++;
        char *start = lexer->current;
        while (*lexer->current != '"' && *lexer->current != '\0') {
            lexer->current++;
            lexer->column++;
        }
        int length = lexer->current - start;
        char *value = malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
        token->type = TOKEN_STRING;
        token->value = value;
        lexer->current++;
        lexer->column++;
        return token;
    }

    // Check for operators
    if (*lexer->current == '+' || *lexer->current == '-' || *lexer->current == '*' || *lexer->current == '/' || *lexer->current == '%') {
        char *value = malloc(2);
        value[0] = *lexer->current;
        value[1] = '\0';
        token->type = TOKEN_OPERATOR;
        token->value = value;
        lexer->current++;
        lexer->column++;
        return token;
    }

    // Check for keywords
    if (strcmp(lexer->current, "int") == 0 || strcmp(lexer->current, "float") == 0 || strcmp(lexer->current, "double") == 0 || strcmp(lexer->current, "char") == 0 || strcmp(lexer->current, "void") == 0) {
        char *value = malloc(strlen(lexer->current) + 1);
        strcpy(value, lexer->current);
        token->type = TOKEN_KEYWORD;
        token->value = value;
        lexer->current += strlen(lexer->current);
        lexer->column += strlen(lexer->current);
        return token;
    }

    // Check for punctuators
    if (*lexer->current == ',' || *lexer->current == ';' || *lexer->current == '(' || *lexer->current == ')' || *lexer->current == '{' || *lexer->current == '}' || *lexer->current == '[' || *lexer->current == ']') {
        char *value = malloc(2);
        value[0] = *lexer->current;
        value[1] = '\0';
        token->type = TOKEN_PUNCTUATOR;
        token->value = value;
        lexer->current++;
        lexer->column++;
        return token;
    }

    // Unknown character
    token->type = TOKEN_EOF;
    token->value = NULL;
    return token;
}

// Free the token
void free_token(Token *token) {
    if (token->value != NULL) {
        free(token->value);
    }
    free(token);
}

// Main function
int main() {
    // Create a lexer
    Lexer *lexer = new_lexer("int main() { int a = 1; float b = 2.5; char c = 'a'; }");

    // Get the next token
    Token *token;
    while ((token = next_token(lexer)) != NULL) {
        // Print the token
        printf("Type: %d, Value: %s\n", token->type, token->value);

        // Free the token
        free_token(token);
    }

    // Free the lexer
    free(lexer);

    return 0;
}