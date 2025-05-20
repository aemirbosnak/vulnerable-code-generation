//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: calm
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
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].token = malloc(len + 1);
    memcpy(tokens[num_tokens].token, str, len);
    tokens[num_tokens].token_len = len;
    num_tokens++;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1024];
    char *p;
    int len;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        p = line;
        len = strlen(line);
        while ((p < line + len - 2) && isspace(*p)) {
            p++;
        }
        if (p >= line + len - 2) {
            continue;
        }
        add_token(p, len - (p - line));
    }

    fclose(fp);

    printf("Number of tokens: %d\n", num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        printf("Token %d: %s\n", i, tokens[i].token);
    }

    return 0;
}