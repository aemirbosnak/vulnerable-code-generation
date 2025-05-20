//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_TOKEN_LENGTH 64
#define MAX_TOKENS 100

typedef struct {
    char **tokens;
    int token_count;
} TokenList;

TokenList* create_token_list() {
    TokenList *list = (TokenList *)malloc(sizeof(TokenList));
    list->tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
    for (int i = 0; i < MAX_TOKENS; i++) {
        list->tokens[i] = (char *)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    }
    list->token_count = 0;
    return list;
}

void free_token_list(TokenList *list) {
    for (int i = 0; i < MAX_TOKENS; i++) {
        free(list->tokens[i]);
    }
    free(list->tokens);
    free(list);
}

void add_token(TokenList *list, const char *token) {
    if (list->token_count < MAX_TOKENS) {
        strncpy(list->tokens[list->token_count++], token, MAX_TOKEN_LENGTH);
    }
}

void tokenize_line(const char *line, TokenList *list) {
    const char *delimiters = " ;(){}[],";
    char *temp = strdup(line);
    char *token = strtok(temp, delimiters);
    while (token != NULL) {
        add_token(list, token);
        token = strtok(NULL, delimiters);
    }
    free(temp);
}

void print_tokens(TokenList *list) {
    for (int i = 0; i < list->token_count; i++) {
        printf("Token[%d]: %s\n", i, list->tokens[i]);
    }
}

int is_keyword(const char *token) {
    const char *keywords[] = {
        "int", "float", "double", "char", 
        "void", "if", "else", "for", 
        "while", "return", "include", 
        "define", "struct", "union", NULL
    };
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void analyze_tokens(TokenList *list) {
    for (int i = 0; i < list->token_count; i++) {
        if (is_keyword(list->tokens[i])) {
            printf("Keyword found: %s\n", list->tokens[i]);
        } else if (isdigit(list->tokens[i][0])) {
            printf("Number found: %s\n", list->tokens[i]);
        } else {
            printf("Identifier found: %s\n", list->tokens[i]);
        }
    }
}

int main() {
    FILE *file = fopen("example.c", "r");
    if (!file) {
        fprintf(stderr, "Could not open file example.c\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    TokenList *token_list = create_token_list();

    while (fgets(line, sizeof(line), file)) {
        tokenize_line(line, token_list);
    }

    fclose(file);

    printf("Tokens from file:\n");
    print_tokens(token_list);
    analyze_tokens(token_list);

    free_token_list(token_list);
    return 0;
}