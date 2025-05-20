//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *name;
    char *value;
} token_t;

int num_tokens = 0;
token_t tokens[MAX_TOKENS];

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    FILE *fp;
    char line[MAX_TOKEN_LENGTH];
    char *token;
    char *saveptr;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_TOKEN_LENGTH, fp)!= NULL) {
        token = strtok_r(line, ":", &saveptr);
        while (token!= NULL) {
            add_token(token, strtok_r(NULL, ":", &saveptr));
            token = strtok_r(NULL, ":", &saveptr);
        }
    }

    fclose(fp);
    print_tokens();

    return 0;
}