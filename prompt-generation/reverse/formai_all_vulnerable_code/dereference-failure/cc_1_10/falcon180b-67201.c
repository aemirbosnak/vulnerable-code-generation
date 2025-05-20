//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached.\n");
        exit(1);
    }

    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

void parse_line(char *line) {
    char *token;
    char *value = NULL;
    int i = 0;

    while ((token = strtok(line, " "))!= NULL) {
        if (i >= MAX_TOKEN_LEN) {
            printf("Error: Maximum token length reached.\n");
            exit(1);
        }

        value = strdup(token);
        add_token(value, "");
        i++;
    }
}

void print_tokens() {
    int i;

    for (i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    FILE *fp;
    char line[1024];

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        parse_line(line);
    }

    fclose(fp);
    print_tokens();

    return 0;
}