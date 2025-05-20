//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_TOKENS 1000

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_KEYWORD,
    TOKEN_SYMBOL,
    TOKEN_STRING,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    char value[MAX_TOKEN_LENGTH];
    TokenType type;
} Token;

const char *keywords[] = {
    "int", "float", "char", "return", "if", "else", "for", "while", 
    "void", "break", "continue", "switch", "case", "default", "typedef",
    "struct", "union", "enum", "goto", "sizeof", "volatile", "const",
    NULL
};

int is_keyword(const char *token) {
    const char **kw = keywords;
    while (*kw) {
        if (strcmp(token, *kw) == 0) {
            return 1;
        }
        kw++;
    }
    return 0;
}

TokenType get_token_type(const char *token) {
    if (is_keyword(token)) {
        return TOKEN_KEYWORD;
    } else if (isdigit(token[0])) {
        return TOKEN_NUMBER;
    } else if (token[0] == '\"') {
        return TOKEN_STRING;
    } else if (isalpha(token[0]) || token[0] == '_') {
        return TOKEN_IDENTIFIER;
    }
    return TOKEN_SYMBOL;
}

void extract_tokens(const char *source, Token *tokens, int *token_count) {
    char *source_copy = strdup(source); 
    char *token = strtok(source_copy, " \n\t();,=+-*/&|!<>[]{}");
    while (token != NULL) {
        strcpy(tokens[*token_count].value, token);
        tokens[*token_count].type = get_token_type(token);
        (*token_count)++;
        token = strtok(NULL, " \n\t();,=+-*/&|!<>[]{}");
    }
    free(source_copy);
}

void print_tokens(const Token *tokens, int token_count) {
    for (int i = 0; i < token_count; i++) {
        printf("Token: %-15s Type: ", tokens[i].value);
        switch (tokens[i].type) {
            case TOKEN_IDENTIFIER: printf("Identifier\n"); break;
            case TOKEN_NUMBER: printf("Number\n"); break;
            case TOKEN_KEYWORD: printf("Keyword\n"); break;
            case TOKEN_SYMBOL: printf("Symbol\n"); break;
            case TOKEN_STRING: printf("String\n"); break;
            default: printf("Unknown\n"); break;
        }
    }
}

void parse_source_code(const char *source) {
    Token tokens[MAX_TOKENS];
    int token_count = 0;

    extract_tokens(source, tokens, &token_count);
    print_tokens(tokens, token_count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source_code_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *source_code = malloc(length + 1);
    fread(source_code, 1, length, file);
    source_code[length] = '\0';
    fclose(file);

    printf("Parsing source code:\n%s\n", source_code);
    parse_source_code(source_code);

    free(source_code);
    return EXIT_SUCCESS;
}