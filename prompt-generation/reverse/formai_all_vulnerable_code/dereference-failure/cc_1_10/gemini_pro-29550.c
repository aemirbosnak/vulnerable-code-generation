//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
enum TokenType {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR
};

// Token struct
struct Token {
    enum TokenType type;
    char *value;
};

// Parser struct
struct Parser {
    char *input;
    int current_index;
    struct Token current_token;
};

// Create a new token
struct Token *new_token(enum TokenType type, char *value) {
    struct Token *token = malloc(sizeof(struct Token));
    token->type = type;
    token->value = strdup(value);
    return token;
}

// Free a token
void free_token(struct Token *token) {
    free(token->value);
    free(token);
}

// Initialize a parser
void init_parser(struct Parser *parser, char *input) {
    parser->input = input;
    parser->current_index = 0;
    parser->current_token = *new_token(TOKEN_EOF, "");
}

// Get the next token
struct Token *get_next_token(struct Parser *parser) {
    if (parser->current_index >= strlen(parser->input)) {
        return &parser->current_token;
    }

    // Skip whitespace
    while (isspace(parser->input[parser->current_index])) {
        parser->current_index++;
    }

    // Check for EOF
    if (parser->input[parser->current_index] == '\0') {
        return &parser->current_token;
    }

    // Check for identifiers
    if (isalpha(parser->input[parser->current_index])) {
        int start_index = parser->current_index;
        while (isalnum(parser->input[parser->current_index])) {
            parser->current_index++;
        }
        char *identifier = strndup(parser->input + start_index, parser->current_index - start_index);
        return new_token(TOKEN_IDENTIFIER, identifier);
    }

    // Check for numbers
    if (isdigit(parser->input[parser->current_index])) {
        int start_index = parser->current_index;
        while (isdigit(parser->input[parser->current_index])) {
            parser->current_index++;
        }
        char *number = strndup(parser->input + start_index, parser->current_index - start_index);
        return new_token(TOKEN_NUMBER, number);
    }

    // Check for strings
    if (parser->input[parser->current_index] == '"') {
        int start_index = parser->current_index + 1;
        while (parser->input[parser->current_index] != '"') {
            parser->current_index++;
        }
        char *string = strndup(parser->input + start_index, parser->current_index - start_index);
        parser->current_index++;
        return new_token(TOKEN_STRING, string);
    }

    // Check for keywords
    char *keywords[] = {"if", "else", "while", "for", "return", "break", "continue"};
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
        if (strncmp(parser->input + parser->current_index, keywords[i], strlen(keywords[i])) == 0) {
            char *keyword = strdup(keywords[i]);
            parser->current_index += strlen(keyword);
            return new_token(TOKEN_KEYWORD, keyword);
        }
    }

    // Check for operators
    char *operators[] = {"+", "-", "*", "/", "%", "=", "==", "!=", ">", ">=", "<", "<=", "&&", "||", "!", "~", "^", "<<", ">>"};
    for (int i = 0; i < sizeof(operators) / sizeof(char *); i++) {
        if (strncmp(parser->input + parser->current_index, operators[i], strlen(operators[i])) == 0) {
            char *operator = strdup(operators[i]);
            parser->current_index += strlen(operator);
            return new_token(TOKEN_OPERATOR, operator);
        }
    }

    // Check for punctuators
    char *punctuators[] = {";", ",", "(", ")", "{", "}", "[", "]", ".", "..."};
    for (int i = 0; i < sizeof(punctuators) / sizeof(char *); i++) {
        if (strncmp(parser->input + parser->current_index, punctuators[i], strlen(punctuators[i])) == 0) {
            char *punctuator = strdup(punctuators[i]);
            parser->current_index += strlen(punctuator);
            return new_token(TOKEN_PUNCTUATOR, punctuator);
        }
    }

    // Unknown token
    printf("Error: Unknown token '%c'\n", parser->input[parser->current_index]);
    exit(1);
}

// Parse the input
void parse(struct Parser *parser) {
    while (parser->current_token.type != TOKEN_EOF) {
        // Get the next token
        parser->current_token = *get_next_token(parser);

        // Print the token
        printf("Token: %s (%d)\n", parser->current_token.value, parser->current_token.type);
    }
}

// Free the parser
void free_parser(struct Parser *parser) {
    free_token(&parser->current_token);
}

int main() {
    // Create a parser
    struct Parser parser;

    // Initialize the parser
    init_parser(&parser, "int main() { return 0; }");

    // Parse the input
    parse(&parser);

    // Free the parser
    free_parser(&parser);

    return 0;
}