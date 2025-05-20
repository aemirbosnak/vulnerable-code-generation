//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_LINE_LEN 1024

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens++].value = strdup(value);
}

void parse_line(char *line) {
    char *token = strtok(line, ":");
    while (token!= NULL) {
        char *name = strtok(token, "=");
        char *value = strtok(NULL, ":");
        if (name == NULL || value == NULL) {
            printf("Error: Invalid token format.\n");
            exit(1);
        }
        add_token(name, value);
        token = strtok(NULL, ":");
    }
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        parse_line(line);
    }
    fclose(fp);
    print_tokens();
    return 0;
}