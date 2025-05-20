//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *token;
    int count;
} Token;

void tokenize(char *text, Token *tokens) {
    char *p = strtok(text, " \t\r\n\f\v\"");
    int i = 0;
    while (p!= NULL && i < MAX_TOKENS) {
        if (strlen(p) > 0) {
            tokens[i].token = strdup(p);
            tokens[i].count = 1;
            i++;
        }
        p = strtok(NULL, " \t\r\n\f\v\"");
    }
}

void count_tokens(Token *tokens, int num_tokens, char *text) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        int j;
        for (j = 0; j < strlen(text); j++) {
            if (tolower(text[j]) == tolower(tokens[i].token[0])) {
                tokens[i].count++;
            }
        }
    }
}

int is_spam(Token *tokens, int num_tokens) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        if (tokens[i].count > 3) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int num_tokens = 0;

    Token tokens[MAX_TOKENS];
    while (num_tokens < MAX_TOKENS && num_tokens < 100) {
        char *p = strtok(text, " \t\r\n\f\v\"");
        if (p!= NULL) {
            if (strlen(p) > 0) {
                tokens[num_tokens].token = strdup(p);
                num_tokens++;
            }
        }
    }

    count_tokens(tokens, num_tokens, text);

    int is_spam_result = is_spam(tokens, num_tokens);

    if (is_spam_result) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}