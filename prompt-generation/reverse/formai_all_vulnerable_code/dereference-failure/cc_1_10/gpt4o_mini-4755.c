//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50
#define MAX_LINE_LENGTH 256

typedef struct {
    char **tokens;
    int count;
} TokenList;

void initializeTokenList(TokenList *list) {
    list->tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
    for (int i = 0; i < MAX_TOKENS; i++) {
        list->tokens[i] = (char *)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    }
    list->count = 0;
}

void freeTokenList(TokenList *list) {
    for (int i = 0; i < MAX_TOKENS; i++) {
        free(list->tokens[i]);
    }
    free(list->tokens);
}

void tokenizeLine(char *line, TokenList *list) {
    char *token = strtok(line, " \t\n");
    while (token != NULL && list->count < MAX_TOKENS) {
        strncpy(list->tokens[list->count++], token, MAX_TOKEN_LENGTH);
        token = strtok(NULL, " \t\n");
    }
}

void printTokens(TokenList *list) {
    printf("Tokens:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Token[%d]: %s\n", i, list->tokens[i]);
    }
}

int isIdentifier(char *token) {
    if (!isalpha(token[0]) && token[0] != '_') return 0;
    for (int i = 1; token[i] != '\0'; i++) {
        if (!isalnum(token[i]) && token[i] != '_') return 0;
    }
    return 1;
}

int isKeyword(char *token) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "restrict", "return", "short",
        "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };
    const int keywordCount = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void analyzeTokens(TokenList *list) {
    printf("\nAnalysis of Tokens:\n");
    for (int i = 0; i < list->count; i++) {
        if (isKeyword(list->tokens[i])) {
            printf("'%s' is a keyword.\n", list->tokens[i]);
        } else if (isIdentifier(list->tokens[i])) {
            printf("'%s' is an identifier.\n", list->tokens[i]);
        } else {
            printf("'%s' is neither a keyword nor an identifier.\n", list->tokens[i]);
        }
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    TokenList tokens;
    initializeTokenList(&tokens);

    printf("Enter a line of C code (type 'exit' to leave):\n");

    while (1) {
        // Get a line of C code
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "exit\n") == 0) {
            break;
        }

        // Tokenize the line
        tokenizeLine(line, &tokens);

        // Print tokens
        printTokens(&tokens);

        // Analyze tokens
        analyzeTokens(&tokens);

        // Reset token count for the next line
        tokens.count = 0;
        printf("\n");
    }

    // Clean up
    freeTokenList(&tokens);
    printf("Exiting the C Syntax Parser. Goodbye!\n");
    return 0;
}