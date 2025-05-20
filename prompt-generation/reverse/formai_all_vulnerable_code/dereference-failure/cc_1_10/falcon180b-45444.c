//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *name;
    char *value;
} Token;

void print_tokens(Token *tokens, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Value: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    FILE *fp;
    char line[MAX_TOKEN_LENGTH];
    char *token;
    Token tokens[MAX_TOKENS];
    int count = 0;

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_TOKEN_LENGTH, fp)!= NULL) {
        token = strtok(line, ":");

        while (token!= NULL) {
            if (count >= MAX_TOKENS) {
                printf("Error: Maximum number of tokens reached\n");
                fclose(fp);
                return 1;
            }

            tokens[count].name = strdup(token);
            token = strtok(NULL, ":");

            if (token == NULL) {
                printf("Error: Missing value for token '%s'\n", tokens[count].name);
                fclose(fp);
                return 1;
            }

            tokens[count].value = strdup(token);
            count++;

            token = strtok(NULL, ":");
        }
    }

    fclose(fp);
    print_tokens(tokens, count);

    for (int i = 0; i < count; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }

    return 0;
}