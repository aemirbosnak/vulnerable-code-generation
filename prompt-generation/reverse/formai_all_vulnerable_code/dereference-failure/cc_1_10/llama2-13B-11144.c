//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 32

typedef struct {
    char *name;
    char *type;
    int line;
    int column;
} token_t;

typedef struct {
    token_t tokens[10];
    int num_tokens;
} parse_state_t;

parse_state_t *parse_state = NULL;

void lex(char *src) {
    char *token = strtok(src, " ");
    int i = 0;

    while (token != NULL) {
        if (i >= MAX_NAME_LENGTH) {
            fprintf(stderr, "Token name too long\n");
            exit(1);
        }

        if (strcmp(token, "int") == 0) {
            parse_state->tokens[i].type = "int";
        } else if (strcmp(token, "float") == 0) {
            parse_state->tokens[i].type = "float";
        } else if (strcmp(token, "void") == 0) {
            parse_state->tokens[i].type = "void";
        } else {
            fprintf(stderr, "Invalid token: %s\n", token);
            exit(1);
        }

        parse_state->tokens[i].name = token;
        parse_state->tokens[i].line = i;
        parse_state->tokens[i].column = 0;

        i++;
        token = strtok(NULL, " ");
    }

    parse_state->num_tokens = i;
}

void parse(char *src) {
    char *token = strtok(src, " ");

    while (token != NULL) {
        if (parse_state->num_tokens == 0) {
            fprintf(stderr, "No tokens found\n");
            exit(1);
        }

        if (strcmp(token, "}") == 0) {
            if (parse_state->num_tokens == 0) {
                fprintf(stderr, "Missing opening brace\n");
                exit(1);
            }

            parse_state->num_tokens--;
        } else if (strcmp(token, "{") == 0) {
            parse_state->num_tokens++;
        }

        token = strtok(NULL, " ");
    }
}

int main(void) {
    char src[] = "int main() { float x = 3.14; return 0; }";

    lex(src);
    parse(src);

    if (parse_state->num_tokens != 0) {
        fprintf(stderr, "Unmatched closing brace\n");
        exit(1);
    }

    return 0;
}