//Falcon-180B DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 1024

char *line = NULL;
size_t line_capacity = 0;
size_t line_length = 0;

char **tokens = NULL;
size_t num_tokens = 0;
size_t tokens_capacity = 0;

void add_token(const char *token) {
    if (num_tokens >= tokens_capacity) {
        tokens_capacity += 64;
        tokens = realloc(tokens, tokens_capacity * sizeof(char*));
    }
    tokens[num_tokens++] = strdup(token);
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file.\n");
        exit(1);
    }

    line = malloc(MAX_LINE_LENGTH);
    line_capacity = MAX_LINE_LENGTH;

    while (fgets(line, line_capacity, fp)!= NULL) {
        line_length = strlen(line);
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }

        char *delimiter = " ";
        char *token = strtok(line, delimiter);
        while (token!= NULL) {
            add_token(token);
            token = strtok(NULL, delimiter);
        }
    }

    fclose(fp);

    for (size_t i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
    }

    for (size_t i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(line);

    return 0;
}