//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 1024
#define MAX_LINE_SIZE 4096

typedef struct {
    char *text;
    int size;
} Token;

typedef struct {
    Token *tokens;
    int count;
} TokenList;

void tokenize(char *line, TokenList *tokens) {
    char *start = line;
    char *end = line;
    while (*end!= '\0') {
        if (*end == '<') {
            end++;
            while (*end!= '>' && *end!= '\0') {
                end++;
            }
            if (*end == '>') {
                end++;
                Token *token = malloc(sizeof(Token));
                token->text = start;
                token->size = end - start;
                tokens->tokens = realloc(tokens->tokens, sizeof(Token) * (tokens->count + 1));
                tokens->tokens[tokens->count++] = *token;
                start = end;
            }
        } else {
            end++;
        }
    }
    Token *token = malloc(sizeof(Token));
    token->text = start;
    token->size = end - start;
    tokens->tokens = realloc(tokens->tokens, sizeof(Token) * (tokens->count + 1));
    tokens->tokens[tokens->count++] = *token;
}

void beautify(TokenList *tokens, FILE *output) {
    for (int i = 0; i < tokens->count; i++) {
        Token *token = &tokens->tokens[i];
        if (token->size == 0) {
            fprintf(output, " ");
        } else if (token->size == 1) {
            fprintf(output, "%s", token->text);
        } else {
            fprintf(output, "<%s>", token->text);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: unable to open input file.\n");
        return 1;
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error: unable to open output file.\n");
        return 1;
    }
    TokenList tokens;
    tokens.tokens = NULL;
    tokens.count = 0;
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, input)!= NULL) {
        tokenize(line, &tokens);
    }
    beautify(&tokens, output);
    fclose(input);
    fclose(output);
    return 0;
}