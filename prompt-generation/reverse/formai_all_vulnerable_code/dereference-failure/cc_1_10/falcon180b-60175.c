//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} token_t;

int num_tokens = 0;
token_t tokens[MAX_TOKENS];

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        fprintf(stderr, "Error: maximum tokens reached\n");
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
    char line[MAX_LINE_LENGTH];
    char *name, *value;
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file\n");
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        name = strtok(line, ":");
        value = strtok(NULL, ":");
        if (name == NULL || value == NULL) {
            fprintf(stderr, "Error: invalid line format\n");
            exit(1);
        }
        add_token(name, value);
    }
    fclose(fp);
    print_tokens();
    return 0;
}