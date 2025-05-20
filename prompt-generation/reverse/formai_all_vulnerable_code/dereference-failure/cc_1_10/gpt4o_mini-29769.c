//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TOKEN_LENGTH 128

typedef struct {
    char *type;
    char *value;
} Token;

typedef struct {
    Token *tokens;
    int token_count;
} TokenList;

// Function prototypes
TokenList* tokenize(const char *input);
void free_token_list(TokenList *list);
void print_tokens(TokenList *list);
void parse_function(TokenList *list);
void parse_variable(TokenList *list);
int is_identifier(const char *str);
int is_type(const char *str);

int main() {
    char line[MAX_LINE_LENGTH];
    printf("Enter a C code snippet:\n");
    
    if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Tokenize the C code
    TokenList *tokens = tokenize(line);
    if (tokens == NULL) {
        fprintf(stderr, "Error during tokenization.\n");
        return 1;
    }

    // Print the tokens
    print_tokens(tokens);
    
    // Parse the tokens
    parse_function(tokens);
    parse_variable(tokens);
    
    // Free allocated token list
    free_token_list(tokens);
    return 0;
}

// Tokenize the input string into tokens
TokenList* tokenize(const char *input) {
    TokenList *list = malloc(sizeof(TokenList));
    list->tokens = malloc(MAX_LINE_LENGTH * sizeof(Token));
    list->token_count = 0;

    // Split input by spaces
    char *input_copy = strdup(input);
    char *token = strtok(input_copy, " \n\t");
    
    while (token != NULL) {
        if (list->token_count < MAX_LINE_LENGTH) {
            list->tokens[list->token_count].type = (is_type(token) ? "type" : "identifier");
            list->tokens[list->token_count].value = strdup(token);
            list->token_count++;
        }
        token = strtok(NULL, " \n\t");
    }
    
    free(input_copy);
    return list;
}

// Free the allocated memory for the token list
void free_token_list(TokenList *list) {
    for (int i = 0; i < list->token_count; i++) {
        free(list->tokens[i].value);
    }
    free(list->tokens);
    free(list);
}

// Print the tokens for debugging
void print_tokens(TokenList *list) {
    printf("Tokens:\n");
    for (int i = 0; i < list->token_count; i++) {
        printf("Type: %s, Value: %s\n", list->tokens[i].type, list->tokens[i].value);
    }
}

// Sample parser for functions
void parse_function(TokenList *list) {
    for (int i = 0; i < list->token_count; i++) {
        if (strcmp(list->tokens[i].type, "type") == 0 && 
            i + 1 < list->token_count && 
            strcmp(list->tokens[i + 1].type, "identifier") == 0) {
            if (i + 2 < list->token_count && strcmp(list->tokens[i + 2].value, "(") == 0) {
                printf("Function detected: %s %s()\n", list->tokens[i].value, list->tokens[i + 1].value);
            }
        }
    }
}

// Sample parser for variable declarations
void parse_variable(TokenList *list) {
    for (int i = 0; i < list->token_count; i++) {
        if (strcmp(list->tokens[i].type, "type") == 0 && i + 1 < list->token_count && 
            strcmp(list->tokens[i + 1].type, "identifier") == 0) {
            printf("Variable declaration detected: %s %s;\n", list->tokens[i].value, list->tokens[i + 1].value);
        }
    }
}

// Check if a string is a valid identifier
int is_identifier(const char *str) {
    if (!isalpha(str[0]) && str[0] != '_') return 0;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') return 0;
    }
    return 1;
}

// Check if a string is a valid C type
int is_type(const char *str) {
    return (strcmp(str, "int") == 0 || strcmp(str, "float") == 0 ||
            strcmp(str, "double") == 0 || strcmp(str, "char") == 0);
}