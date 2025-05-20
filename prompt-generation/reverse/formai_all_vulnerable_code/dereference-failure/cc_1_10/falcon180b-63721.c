//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Token;

void init_token(Token *token) {
    token->name = NULL;
    token->value = NULL;
}

void free_token(Token *token) {
    if (token->name) {
        free(token->name);
        token->name = NULL;
    }
    if (token->value) {
        free(token->value);
        token->value = NULL;
    }
}

void print_token(Token *token) {
    if (token->name) {
        printf("%s: ", token->name);
    } else {
        printf("<unknown>: ");
    }
    if (token->value) {
        printf("%s\n", token->value);
    } else {
        printf("<empty>\n");
    }
}

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    char *saveptr;
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok_r(line, "\n", &saveptr);
        while (token!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: Too many tokens.\n");
                return 1;
            }
            init_token(&tokens[num_tokens]);
            if (isalnum(token[0])) {
                tokens[num_tokens].name = strdup(token);
            } else {
                tokens[num_tokens].value = strdup(token);
            }
            num_tokens++;
            token = strtok_r(NULL, "\n", &saveptr);
        }
    }

    fclose(fp);

    for (int i = 0; i < num_tokens; i++) {
        print_token(&tokens[i]);
    }

    for (int i = 0; i < num_tokens; i++) {
        free_token(&tokens[i]);
    }

    return 0;
}