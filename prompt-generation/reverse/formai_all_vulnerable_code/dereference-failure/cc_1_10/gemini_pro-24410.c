//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
enum TokenType {
    TOKEN_INVALID,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_DELIMITER,
    TOKEN_EOF
};

// Token struct
struct Token {
    enum TokenType type;
    char *value;
};

// Lexer struct
struct Lexer {
    char *input;
    int position;
    int length;
};

// Create a new lexer
struct Lexer *lexer_new(char *input) {
    struct Lexer *lexer = malloc(sizeof(struct Lexer));
    lexer->input = input;
    lexer->position = 0;
    lexer->length = strlen(input);
    return lexer;
}

// Free the lexer
void lexer_free(struct Lexer *lexer) {
    free(lexer);
}

// Get the next token
struct Token *lexer_next_token(struct Lexer *lexer) {
    struct Token *token = malloc(sizeof(struct Token));

    // Skip whitespace
    while (lexer->position < lexer->length && isspace(lexer->input[lexer->position])) {
        lexer->position++;
    }

    // Check for end of input
    if (lexer->position >= lexer->length) {
        token->type = TOKEN_EOF;
        token->value = NULL;
        return token;
    }

    // Check for identifiers
    if (isalpha(lexer->input[lexer->position])) {
        int start = lexer->position;
        while (lexer->position < lexer->length && isalnum(lexer->input[lexer->position])) {
            lexer->position++;
        }
        int length = lexer->position - start;
        token->type = TOKEN_IDENTIFIER;
        token->value = malloc(length + 1);
        strncpy(token->value, lexer->input + start, length);
        token->value[length] = '\0';
        return token;
    }

    // Check for numbers
    if (isdigit(lexer->input[lexer->position])) {
        int start = lexer->position;
        while (lexer->position < lexer->length && isdigit(lexer->input[lexer->position])) {
            lexer->position++;
        }
        int length = lexer->position - start;
        token->type = TOKEN_NUMBER;
        token->value = malloc(length + 1);
        strncpy(token->value, lexer->input + start, length);
        token->value[length] = '\0';
        return token;
    }

    // Check for strings
    if (lexer->input[lexer->position] == '"') {
        lexer->position++;
        int start = lexer->position;
        while (lexer->position < lexer->length && lexer->input[lexer->position] != '"') {
            lexer->position++;
        }
        int length = lexer->position - start;
        token->type = TOKEN_STRING;
        token->value = malloc(length + 1);
        strncpy(token->value, lexer->input + start, length);
        token->value[length] = '\0';
        lexer->position++;
        return token;
    }

    // Check for keywords
    static char *keywords[] = {
        "int",
        "float",
        "double",
        "char",
        "void",
        "if",
        "else",
        "while",
        "do",
        "for",
        "return"
    };
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
        int length = strlen(keywords[i]);
        if (strncmp(lexer->input + lexer->position, keywords[i], length) == 0) {
            token->type = TOKEN_KEYWORD;
            token->value = malloc(length + 1);
            strncpy(token->value, keywords[i], length);
            token->value[length] = '\0';
            lexer->position += length;
            return token;
        }
    }

    // Check for operators
    static char *operators[] = {
        "+",
        "-",
        "*",
        "/",
        "%",
        "=",
        "==",
        "!=",
        ">",
        ">=",
        "<",
        "<=",
        "&&",
        "||",
        "!",
        "++",
        "--"
    };
    for (int i = 0; i < sizeof(operators) / sizeof(char *); i++) {
        int length = strlen(operators[i]);
        if (strncmp(lexer->input + lexer->position, operators[i], length) == 0) {
            token->type = TOKEN_OPERATOR;
            token->value = malloc(length + 1);
            strncpy(token->value, operators[i], length);
            token->value[length] = '\0';
            lexer->position += length;
            return token;
        }
    }

    // Check for delimiters
    static char *delimiters[] = {
        "{",
        "}",
        "(",
        ")",
        "[",
        "]",
        ";",
        ",",
        ".",
        ":"
    };
    for (int i = 0; i < sizeof(delimiters) / sizeof(char *); i++) {
        int length = strlen(delimiters[i]);
        if (strncmp(lexer->input + lexer->position, delimiters[i], length) == 0) {
            token->type = TOKEN_DELIMITER;
            token->value = malloc(length + 1);
            strncpy(token->value, delimiters[i], length);
            token->value[length] = '\0';
            lexer->position += length;
            return token;
        }
    }

    // Invalid token
    token->type = TOKEN_INVALID;
    token->value = NULL;
    return token;
}

// Free the token
void token_free(struct Token *token) {
    free(token->value);
    free(token);
}

// Print the token
void token_print(struct Token *token) {
    switch (token->type) {
        case TOKEN_INVALID:
            printf("Invalid token\n");
            break;
        case TOKEN_IDENTIFIER:
            printf("Identifier: %s\n", token->value);
            break;
        case TOKEN_NUMBER:
            printf("Number: %s\n", token->value);
            break;
        case TOKEN_STRING:
            printf("String: %s\n", token->value);
            break;
        case TOKEN_KEYWORD:
            printf("Keyword: %s\n", token->value);
            break;
        case TOKEN_OPERATOR:
            printf("Operator: %s\n", token->value);
            break;
        case TOKEN_DELIMITER:
            printf("Delimiter: %s\n", token->value);
            break;
        case TOKEN_EOF:
            printf("End of input\n");
            break;
    }
}

int main() {
    // Create a lexer
    struct Lexer *lexer = lexer_new("int main() { int a = 1; }");

    // Get the next token
    struct Token *token;
    while ((token = lexer_next_token(lexer)) != NULL) {
        // Print the token
        token_print(token);

        // Free the token
        token_free(token);
    }

    // Free thelexer
    lexer_free(lexer);

    return 0;
}