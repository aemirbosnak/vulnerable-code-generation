//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TOKENS 128

// Token types
typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char *value;
} Token;

// Lexer structure
typedef struct {
    char *input;
    int input_length;
    int current_position;
    Token current_token;
} Lexer;

// Create a new lexer
Lexer *new_lexer(char *input) {
    Lexer *lexer = malloc(sizeof(Lexer));
    lexer->input = input;
    lexer->input_length = strlen(input);
    lexer->current_position = 0;
    lexer->current_token.type = TOKEN_EOF;
    lexer->current_token.value = NULL;
    return lexer;
}

// Destroy a lexer
void destroy_lexer(Lexer *lexer) {
    free(lexer->current_token.value);
    free(lexer);
}

// Get the next token from the lexer
Token get_next_token(Lexer *lexer) {
    // If we have reached the end of the input, return the EOF token
    if (lexer->current_position >= lexer->input_length) {
        return lexer->current_token;
    }

    // Skip whitespace
    while (lexer->current_position < lexer->input_length && isspace(lexer->input[lexer->current_position])) {
        lexer->current_position++;
    }

    // Check if we have reached the end of the input
    if (lexer->current_position >= lexer->input_length) {
        return lexer->current_token;
    }

    // Get the first character of the token
    char first_char = lexer->input[lexer->current_position];

    // Identifier
    if (isalpha(first_char) || first_char == '_') {
        int start_position = lexer->current_position;
        while (lexer->current_position < lexer->input_length && (isalnum(lexer->input[lexer->current_position]) || lexer->input[lexer->current_position] == '_')) {
            lexer->current_position++;
        }
        int length = lexer->current_position - start_position;
        char *value = malloc(length + 1);
        strncpy(value, lexer->input + start_position, length);
        value[length] = '\0';
        lexer->current_token.type = TOKEN_IDENTIFIER;
        lexer->current_token.value = value;
        return lexer->current_token;
    }

    // Number
    if (isdigit(first_char)) {
        int start_position = lexer->current_position;
        while (lexer->current_position < lexer->input_length && isdigit(lexer->input[lexer->current_position])) {
            lexer->current_position++;
        }
        int length = lexer->current_position - start_position;
        char *value = malloc(length + 1);
        strncpy(value, lexer->input + start_position, length);
        value[length] = '\0';
        lexer->current_token.type = TOKEN_NUMBER;
        lexer->current_token.value = value;
        return lexer->current_token;
    }

    // String
    if (first_char == '"' || first_char == '\'') {
        char delimiter = first_char;
        int start_position = lexer->current_position + 1;
        while (lexer->current_position < lexer->input_length && lexer->input[lexer->current_position] != delimiter) {
            lexer->current_position++;
        }
        int length = lexer->current_position - start_position;
        char *value = malloc(length + 1);
        strncpy(value, lexer->input + start_position, length);
        value[length] = '\0';
        lexer->current_token.type = TOKEN_STRING;
        lexer->current_token.value = value;
        return lexer->current_token;
    }

    // Keyword
    char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int num_keywords = sizeof(keywords) / sizeof(char *);
    for (int i = 0; i < num_keywords; i++) {
        if (strncmp(lexer->input + lexer->current_position, keywords[i], strlen(keywords[i])) == 0) {
            int length = strlen(keywords[i]);
            char *value = malloc(length + 1);
            strncpy(value, keywords[i], length);
            value[length] = '\0';
            lexer->current_token.type = TOKEN_KEYWORD;
            lexer->current_token.value = value;
            lexer->current_position += length;
            return lexer->current_token;
        }
    }

    // Operator
    char *operators[] = {"=", "+", "-", "*", "/", "%", "&", "|", "^", "~", "!", "==", "!=", "<", "<=", ">", ">=", "<<", ">>", "&&", "||", "->", "++", "--", "::", "[]"};
    int num_operators = sizeof(operators) / sizeof(char *);
    for (int i = 0; i < num_operators; i++) {
        if (strncmp(lexer->input + lexer->current_position, operators[i], strlen(operators[i])) == 0) {
            int length = strlen(operators[i]);
            char *value = malloc(length + 1);
            strncpy(value, operators[i], length);
            value[length] = '\0';
            lexer->current_token.type = TOKEN_OPERATOR;
            lexer->current_token.value = value;
            lexer->current_position += length;
            return lexer->current_token;
        }
    }

    // Punctuator
    char *punctuators[] = {";", ",", ":", "(", ")", "{", "}", "[", "]", ".", "..."};
    int num_punctuators = sizeof(punctuators) / sizeof(char *);
    for (int i = 0; i < num_punctuators; i++) {
        if (strncmp(lexer->input + lexer->current_position, punctuators[i], strlen(punctuators[i])) == 0) {
            int length = strlen(punctuators[i]);
            char *value = malloc(length + 1);
            strncpy(value, punctuators[i], length);
            value[length] = '\0';
            lexer->current_token.type = TOKEN_PUNCTUATOR;
            lexer->current_token.value = value;
            lexer->current_position += length;
            return lexer->current_token;
        }
    }

    // Unknown token
    lexer->current_token.type = TOKEN_EOF;
    lexer->current_token.value = NULL;
    return lexer->current_token;
}

// Print the tokens from the lexer
void print_tokens(Lexer *lexer) {
    while (lexer->current_token.type != TOKEN_EOF) {
        printf("%s ", lexer->current_token.value);
        lexer->current_token = get_next_token(lexer);
    }
    printf("\n");
}

// Main function
int main() {
    char *input = "int main() { int a = 10; if (a > 5) { return 0; } else { return 1; } }";
    Lexer *lexer = new_lexer(input);
    print_tokens(lexer);
    destroy_lexer(lexer);
    return 0;
}