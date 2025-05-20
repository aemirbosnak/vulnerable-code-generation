//Falcon-180B DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    char *token;
    int length;
    int count;
} Token;

void tokenize(Text *text, Token *tokens) {
    int i = 0;
    int j = 0;
    char *word = malloc(MAX_TOKEN_LENGTH);
    char *delimiter = " \t\n\r\f\v";

    while (i < text->length) {
        if (isspace(text->text[i])) {
            if (j > 0) {
                tokens[j].token = strdup(word);
                tokens[j].length = strlen(tokens[j].token);
                tokens[j].count = 1;
                j++;
                memset(word, 0, MAX_TOKEN_LENGTH);
            }
        } else {
            strncat(word, &text->text[i], 1);
            i++;
        }
    }

    if (j > 0) {
        tokens[j].token = strdup(word);
        tokens[j].length = strlen(tokens[j].token);
        tokens[j].count = 1;
        j++;
    }

    free(word);
}

void count_tokens(Token *tokens, int num_tokens) {
    int i;

    for (i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].token, tokens[i].count);
    }
}

int main() {
    Text text;
    Token tokens[MAX_TOKENS];

    printf("Enter text: ");
    fgets(text.text, MAX_TOKEN_LENGTH, stdin);
    text.length = strlen(text.text);

    tokenize(&text, tokens);
    count_tokens(tokens, text.length);

    return 0;
}