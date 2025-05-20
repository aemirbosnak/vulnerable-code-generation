//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 256
#define MAX_TOKENS 100

typedef struct {
    char *tokens[MAX_TOKENS];
    int token_count;
} TokenList;

TokenList* create_token_list() {
    TokenList *list = malloc(sizeof(TokenList));
    list->token_count = 0;
    return list;
}

void free_token_list(TokenList *list) {
    for (int i = 0; i < list->token_count; i++) {
        free(list->tokens[i]);
    }
    free(list);
}

void tokenize_line(const char *line, TokenList *list) {
    char *line_copy = strdup(line);
    char *token = strtok(line_copy, " \t\n");
    
    while (token != NULL && list->token_count < MAX_TOKENS) {
        list->tokens[list->token_count++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    
    free(line_copy);
}

void print_tokens(TokenList *list) {
    printf("Tokens:\n");
    for (int i = 0; i < list->token_count; i++) {
        printf("%s\n", list->tokens[i]);
    }
}

int is_identifier(const char *token) {
    if (!isalpha(token[0]) && token[0] != '_')
        return 0; // must start with a letter or underscore
    for (int i = 1; token[i] != '\0'; i++) {
        if (!isalnum(token[i]) && token[i] != '_')
            return 0; // must be alphanumeric or underscore
    }
    return 1;
}

int is_keyword(const char *token) {
    const char *keywords[] = {
        "int", "float", "char", "if", "else", "while", "do", "return", "for", 
        "break", "continue", "switch", "case", "default", "const", "volatile", "static",
        NULL
    };

    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1; // it is a keyword
        }
    }
    return 0;
}

void classify_tokens(TokenList *list) {
    printf("\nClassified Tokens:\n");
    for (int i = 0; i < list->token_count; i++) {
        if (is_keyword(list->tokens[i])) {
            printf("%s: Keyword\n", list->tokens[i]);
        } else if (is_identifier(list->tokens[i])) {
            printf("%s: Identifier\n", list->tokens[i]);
        } else {
            printf("%s: Other\n", list->tokens[i]);
        }
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    TokenList *token_list = create_token_list();

    printf("Enter a C syntax line (type 'exit' to quit):\n");
    
    while (1) {
        printf("> ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break; // Handle EOF
        }
        if (strcmp(line, "exit\n") == 0) {
            break; // Exit on "exit" command
        }

        tokenize_line(line, token_list);
        print_tokens(token_list);
        classify_tokens(token_list);
        
        // Reset token list for the next input
        free_token_list(token_list);
        token_list = create_token_list();
    }

    free_token_list(token_list);
    return 0;
}