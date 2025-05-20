//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
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

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *str, int len) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens exceeded.\n");
        exit(1);
    }

    tokens[num_tokens].token = malloc(len + 1);
    strncpy(tokens[num_tokens].token, str, len);
    tokens[num_tokens].token_len = len;
    num_tokens++;
}

void process_line(char *line) {
    char *token = strtok(line, " ");

    while (token!= NULL) {
        int len = strlen(token);
        if (len > 0 && isalnum(token[0])) {
            add_token(token, len);
        }
        token = strtok(NULL, " ");
    }
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (%d)\n", tokens[i].token, tokens[i].token_len);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        process_line(line);
    }

    fclose(fp);
    print_tokens();

    return 0;
}