//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
    int line_number;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, char *value, int line_number) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: maximum number of tokens reached\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    tokens[num_tokens].line_number = line_number;
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }
    char line[MAX_LINE_SIZE];
    int line_number = 1;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ":");
        while (token!= NULL) {
            char *name = strtok(token, " ");
            char *value = strtok(NULL, " ");
            if (name == NULL || value == NULL) {
                printf("Error: invalid token format on line %d\n", line_number);
                exit(1);
            }
            add_token(name, value, line_number);
            token = strtok(NULL, ":");
        }
        line_number++;
    }
    fclose(fp);
    print_tokens();
    return 0;
}