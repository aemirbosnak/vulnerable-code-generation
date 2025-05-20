//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *name;
    char *value;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens;

void init_tokens() {
    num_tokens = 0;
}

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

void free_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }
}

void parse_line(char *line) {
    char *token = strtok(line, ":");
    while (token!= NULL) {
        char *name = strtok(token, "=");
        char *value = strtok(NULL, "=");
        if (name == NULL || value == NULL) {
            printf("Error: Invalid token format\n");
            exit(1);
        }
        add_token(name, value);
        token = strtok(NULL, ":");
    }
}

int main() {
    init_tokens();
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }
    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        parse_line(line);
    }
    fclose(fp);
    printf("Number of tokens: %d\n", num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        printf("%s=%s\n", tokens[i].name, tokens[i].value);
    }
    free_tokens();
    return 0;
}