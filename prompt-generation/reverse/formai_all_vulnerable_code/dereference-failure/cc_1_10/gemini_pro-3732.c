//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 100

// Token types
enum TokenType {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_SYMBOL,
};

// Token structure
struct Token {
    enum TokenType type;
    char *value;
};

// Lexer structure
struct Lexer {
    char *input;
    int input_length;
    int current_position;
    struct Token tokens[MAX_TOKENS];
    int num_tokens;
};

// Create a new lexer
struct Lexer *new_lexer(char *input) {
    struct Lexer *lexer = malloc(sizeof(struct Lexer));
    lexer->input = input;
    lexer->input_length = strlen(input);
    lexer->current_position = 0;
    lexer->num_tokens = 0;
    return lexer;
}

// Get the next token
struct Token *get_next_token(struct Lexer *lexer) {
    // Skip whitespace
    while (lexer->current_position < lexer->input_length && isspace(lexer->input[lexer->current_position])) {
        lexer->current_position++;
    }

    // Check for end of input
    if (lexer->current_position >= lexer->input_length) {
        return &lexer->tokens[lexer->num_tokens++];
    }

    // Get the next character
    char c = lexer->input[lexer->current_position];

    // Identifier
    if (isalpha(c) || c == '_') {
        int start_position = lexer->current_position;
        while (lexer->current_position < lexer->input_length && (isalnum(lexer->input[lexer->current_position]) || lexer->input[lexer->current_position] == '_')) {
            lexer->current_position++;
        }
        int length = lexer->current_position - start_position;
        char *value = malloc(length + 1);
        strncpy(value, lexer->input + start_position, length);
        value[length] = '\0';
        struct Token *token = &lexer->tokens[lexer->num_tokens++];
        token->type = TOKEN_IDENTIFIER;
        token->value = value;
        return token;
    }

    // Number
    if (isdigit(c)) {
        int start_position = lexer->current_position;
        while (lexer->current_position < lexer->input_length && isdigit(lexer->input[lexer->current_position])) {
            lexer->current_position++;
        }
        int length = lexer->current_position - start_position;
        char *value = malloc(length + 1);
        strncpy(value, lexer->input + start_position, length);
        value[length] = '\0';
        struct Token *token = &lexer->tokens[lexer->num_tokens++];
        token->type = TOKEN_NUMBER;
        token->value = value;
        return token;
    }

    // String
    if (c == '"') {
        int start_position = lexer->current_position;
        lexer->current_position++;
        while (lexer->current_position < lexer->input_length && lexer->input[lexer->current_position] != '"') {
            lexer->current_position++;
        }
        if (lexer->current_position >= lexer->input_length) {
            printf("Error: Unterminated string\n");
            exit(1);
        }
        int length = lexer->current_position - start_position;
        char *value = malloc(length + 1);
        strncpy(value, lexer->input + start_position, length);
        value[length] = '\0';
        struct Token *token = &lexer->tokens[lexer->num_tokens++];
        token->type = TOKEN_STRING;
        token->value = value;
        lexer->current_position++;
        return token;
    }

    // Symbol
    struct Token *token = &lexer->tokens[lexer->num_tokens++];
    token->type = TOKEN_SYMBOL;
    token->value = malloc(2);
    token->value[0] = c;
    token->value[1] = '\0';
    lexer->current_position++;
    return token;
}

// Print the tokens
void print_tokens(struct Lexer *lexer) {
    for (int i = 0; i < lexer->num_tokens; i++) {
        struct Token *token = &lexer->tokens[i];
        printf("Token: %s, Value: %s\n", token->type == TOKEN_EOF ? "EOF" : token->type == TOKEN_IDENTIFIER ? "Identifier" : token->type == TOKEN_NUMBER ? "Number" : token->type == TOKEN_STRING ? "String" : "Symbol", token->value);
    }
}

// Free the lexer
void free_lexer(struct Lexer *lexer) {
    for (int i = 0; i < lexer->num_tokens; i++) {
        free(lexer->tokens[i].value);
    }
    free(lexer);
}

// Main function
int main() {
    char *input = "int main(int argc, char **argv) { return 0; }";
    struct Lexer *lexer = new_lexer(input);
    struct Token *token;
    do {
        token = get_next_token(lexer);
        print_tokens(lexer);
    } while (token->type != TOKEN_EOF);
    free_lexer(lexer);
    return 0;
}