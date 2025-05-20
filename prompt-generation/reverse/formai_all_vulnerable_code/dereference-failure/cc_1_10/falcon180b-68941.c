//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *token;
    int token_len;
} Token;

void tokenize(char *str, Token *tokens) {
    int i = 0, j = 0, k = 0;
    char *p = str;

    while (*p) {
        if (isspace(*p)) {
            if (j > 0) {
                tokens[i].token = malloc(j + 1);
                strncpy(tokens[i].token, p - j, j);
                tokens[i].token_len = j;
                i++;
                j = 0;
            }
        } else if (i == MAX_TOKENS - 1) {
            break;
        } else {
            if (j == MAX_TOKEN_LEN - 1) {
                break;
            }
            p++;
            j++;
        }
    }

    if (j > 0) {
        tokens[i].token = malloc(j + 1);
        strncpy(tokens[i].token, p - j, j);
        tokens[i].token_len = j;
        i++;
    }
}

void print_tokens(Token *tokens, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", tokens[i].token, tokens[i].token_len);
    }
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    Token tokens[MAX_TOKENS];
    int n = 0;

    tokenize(str, tokens);
    print_tokens(tokens, n);

    for (int i = 0; i < n; i++) {
        free(tokens[i].token);
    }

    return 0;
}