//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 32

typedef struct {
    char *name;
    int length;
} Token;

Token *tokenize(char *input) {
    Token *tokens = NULL;
    int i = 0;
    char *ptr = input;
    char *token = NULL;

    while (*ptr) {
        if (i >= MAX_LINE_LENGTH) {
            printf("Error: Line too long\n");
            exit(1);
        }

        if (isalnum(*ptr)) {
            if (token == NULL) {
                token = calloc(MAX_TOKEN_LENGTH, sizeof(char));
                strncat(token, ptr, 1);
                tokens = realloc(tokens, sizeof(Token));
                tokens[i].name = token;
                tokens[i].length = 1;
            } else {
                strncat(token, ptr, 1);
                tokens[i].length++;
            }
        } else {
            if (token!= NULL) {
                tokens[i].name = token;
                tokens[i].length = strlen(token);
                token = NULL;
            }
        }

        ptr++;
        i++;
    }

    if (token!= NULL) {
        tokens[i].name = token;
        tokens[i].length = strlen(token);
    }

    return tokens;
}

void print_tokens(Token *tokens) {
    int i;

    for (i = 0; tokens[i].name!= NULL; i++) {
        printf("%s: %d\n", tokens[i].name, tokens[i].length);
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    Token *tokens;

    printf("Enter HTML code:\n");
    fgets(input, MAX_LINE_LENGTH, stdin);

    tokens = tokenize(input);
    print_tokens(tokens);

    return 0;
}