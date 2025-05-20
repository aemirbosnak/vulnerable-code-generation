//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Token;

void add_token(Token *tokens, int *count, char *name, char *value) {
    if (*count >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }

    Token t = {
       .name = strdup(name),
       .value = strdup(value)
    };

    tokens[*count] = t;
    (*count)++;
}

Token *parse_line(char *line) {
    Token tokens[MAX_TOKENS];
    int count = 0;

    char *name = NULL;
    char *value = NULL;
    char *start = line;

    while (*line!= '\0') {
        if (isspace(*line)) {
            if (name!= NULL) {
                *line = '\0';
                add_token(tokens, &count, name, value);
                name = NULL;
                value = NULL;
            }
        } else {
            if (name == NULL) {
                name = line;
            } else {
                value = line;
            }

            line++;
        }
    }

    if (name!= NULL) {
        add_token(tokens, &count, name, value);
    }

    return tokens;
}

void print_tokens(Token *tokens, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Value: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    Token *tokens = NULL;
    int count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        tokens = realloc(tokens, sizeof(Token) * (count + 1));
        parse_line(line);
    }

    print_tokens(tokens, count);

    free(tokens);
    fclose(file);

    return 0;
}