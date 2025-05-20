//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Token;

Token *tokenize(char *line) {
    int i = 0;
    char *token;
    Token *tokens = calloc(MAX_TOKENS, sizeof(Token));

    while ((token = strtok(line, " "))!= NULL) {
        if (i >= MAX_TOKENS) {
            printf("Error: Too many tokens.\n");
            exit(1);
        }

        tokens[i].name = strdup(token);
        tokens[i].value = NULL;
        i++;
    }

    return tokens;
}

void print_tokens(Token *tokens) {
    int i;

    for (i = 0; tokens[i].name!= NULL; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Token *tokens;

    file = fopen("resume.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        tokens = tokenize(line);
        print_tokens(tokens);
        free(tokens);
    }

    fclose(file);

    return 0;
}