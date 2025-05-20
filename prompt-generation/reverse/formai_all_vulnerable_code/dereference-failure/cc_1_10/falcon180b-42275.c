//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 20

typedef struct {
    char *name;
    char *value;
} token_t;

typedef struct {
    int num_tokens;
    token_t tokens[MAX_TOKENS];
} line_t;

line_t* parse_line(char* input) {
    line_t* line = malloc(sizeof(line_t));
    line->num_tokens = 0;

    char* token_start = input;
    char* token_end = strchr(input, ':');

    if (token_end == NULL) {
        printf("Error: Invalid input format.\n");
        free(line);
        return NULL;
    }

    *token_end = '\0';
    token_t* token = malloc(sizeof(token_t));
    token->name = strdup(token_start);
    token->value = strdup(token_end + 1);
    line->tokens[line->num_tokens++] = *token;
    free(token);

    return line;
}

void print_line(line_t* line) {
    for (int i = 0; i < line->num_tokens; i++) {
        printf("%s: %s\n", line->tokens[i].name, line->tokens[i].value);
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    line_t* line = NULL;

    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        line = parse_line(input);
        if (line!= NULL) {
            print_line(line);
            free(line);
        }
    }

    return 0;
}