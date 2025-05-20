//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 64
#define MAX_TOKENS 100

typedef struct {
    char **tokens;
    int count;
} TokenList;

void tokenize_line(char *line, TokenList *tokenList) {
    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        if (tokenList->count < MAX_TOKENS) {
            tokenList->tokens[tokenList->count] = strdup(token);
            tokenList->count++;
        }
        token = strtok(NULL, " \t\n");
    }
}

int is_identifier(const char *token) {
    if (!isalpha(token[0]) && token[0] != '_') return 0;
    for (int i = 1; token[i] != '\0'; i++) {
        if (!isalnum(token[i]) && token[i] != '_') return 0;
    }
    return 1;
}

int is_keyword(const char *token) {
    const char *keywords[] = {"int", "float", "double", "char", "void", "if", "else", "while", "for", "return"};
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void print_tokens(TokenList *tokenList) {
    printf("Tokens found:\n");
    for (int i = 0; i < tokenList->count; i++) {
        printf("%s\n", tokenList->tokens[i]);
    }
}

void free_token_list(TokenList *tokenList) {
    for (int i = 0; i < tokenList->count; i++) {
        free(tokenList->tokens[i]);
    }
    free(tokenList->tokens);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    TokenList tokenList;
    tokenList.tokens = malloc(MAX_TOKENS * sizeof(char *));
    tokenList.count = 0;

    printf("Enter the filename to parse: ");
    char filename[MAX_LINE_LENGTH];
    fgets(filename, MAX_LINE_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove trailing newline

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        tokenize_line(line, &tokenList);
    }
    
    fclose(file);

    print_tokens(&tokenList);

    for (int i = 0; i < tokenList.count; i++) {
        if (is_keyword(tokenList.tokens[i])) {
            printf("'%s' is a keyword.\n", tokenList.tokens[i]);
        } else if (is_identifier(tokenList.tokens[i])) {
            printf("'%s' is an identifier.\n", tokenList.tokens[i]);
        }
    }

    free_token_list(&tokenList);

    return EXIT_SUCCESS;
}