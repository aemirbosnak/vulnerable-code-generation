//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TOKENS 50

typedef struct {
    char **tokens;
    size_t size;
} TokenArray;

TokenArray* createTokenArray() {
    TokenArray *array = (TokenArray *)malloc(sizeof(TokenArray));
    array->tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
    for (size_t i = 0; i < MAX_TOKENS; i++) {
        array->tokens[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    array->size = 0;
    return array;
}

void freeTokenArray(TokenArray *array) {
    for (size_t i = 0; i < MAX_TOKENS; i++) {
        free(array->tokens[i]);
    }
    free(array->tokens);
    free(array);
}

void tokenizeLine(char *line, TokenArray *array) {
    char *token = strtok(line, " \t\n");
    while (token != NULL && array->size < MAX_TOKENS) {
        strcpy(array->tokens[array->size], token);
        array->size++;
        token = strtok(NULL, " \t\n");
    }
}

void parseSyntax(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    size_t lineNumber = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        TokenArray *tokenArray = createTokenArray();
        tokenizeLine(line, tokenArray);

        printf("Line %zu: ", lineNumber);
        for (size_t i = 0; i < tokenArray->size; i++) {
            printf("[%s] ", tokenArray->tokens[i]);
        }
        printf("\n");

        freeTokenArray(tokenArray);
    }

    fclose(file);
}

void usage(const char *progName) {
    fprintf(stderr, "Usage: %s <filename>\n", progName);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    parseSyntax(argv[1]);
    return EXIT_SUCCESS;
}