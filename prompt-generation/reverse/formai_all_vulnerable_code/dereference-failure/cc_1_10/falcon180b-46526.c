//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char *token;
    int len;
} Token;

int num_tokens = 0;
Token tokens[MAX_TOKENS];

void add_token(char *str, int len) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].token = malloc(len + 1);
    strncpy(tokens[num_tokens].token, str, len);
    tokens[num_tokens].len = len;
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (%d)\n", tokens[i].token, tokens[i].len);
    }
}

int main() {
    char line[MAX_LINE_LEN];
    char *token;
    int len;
    int i = 0;

    printf("Enter your resume:\n");
    fgets(line, MAX_LINE_LEN, stdin);

    token = strtok(line, " \t\n");
    while (token!= NULL) {
        len = strlen(token);
        if (len > 0) {
            add_token(token, len);
        }
        token = strtok(NULL, " \t\n");
    }

    print_tokens();

    return 0;
}