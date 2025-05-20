//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

struct token {
    char *text;
    int length;
};

struct token *tokens;
int num_tokens;

void add_token(char *text, int length) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].text = malloc(length + 1);
    strncpy(tokens[num_tokens].text, text, length);
    tokens[num_tokens].length = length;
    num_tokens++;
}

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    int i, j;

    tokens = malloc(MAX_TOKENS * sizeof(struct token));
    num_tokens = 0;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " \t\n\r\f");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                add_token(token, strlen(token));
            }
            token = strtok(NULL, " \t\n\r\f");
        }
    }

    fclose(fp);

    printf("Number of tokens: %d\n", num_tokens);

    for (i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i].text);
    }

    return 0;
}