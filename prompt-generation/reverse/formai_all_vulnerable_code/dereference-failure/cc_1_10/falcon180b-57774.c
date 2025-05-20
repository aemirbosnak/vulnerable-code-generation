//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int token_len;
} Token;

int num_tokens = 0;
Token tokens[MAX_TOKENS];

void add_token(char *str, int len) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].token = malloc(len + 1);
    strncpy(tokens[num_tokens].token, str, len);
    tokens[num_tokens].token[len] = '\0';
    tokens[num_tokens].token_len = len;
    num_tokens++;
}

void remove_whitespace(char *str) {
    char *p = str;
    while (*p) {
        if (!isspace(*p)) {
            *p = tolower(*p);
        }
        p++;
    }
}

int get_token_index(char *str) {
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(str, tokens[i].token) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, stdin)!= NULL) {
        remove_whitespace(line);
        char *p = strtok(line, " ");
        while (p!= NULL) {
            add_token(p, strlen(p));
            p = strtok(NULL, " ");
        }
    }
    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i].token);
    }
    return 0;
}