//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: innovative
// The Syntax Parser

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define MAX_LENGTH 1024
#define TOKEN_COUNT 16

typedef struct {
    char *name;
    char *value;
} token_t;

typedef struct {
    token_t tokens[TOKEN_COUNT];
    int count;
} parse_state_t;

parse_state_t *parse_state = NULL;

void parse_init(void) {
    parse_state = calloc(1, sizeof(parse_state_t));
    parse_state->count = 0;
}

void parse_add_token(char *token) {
    if (parse_state->count >= TOKEN_COUNT) {
        printf("Error: too many tokens\n");
        exit(1);
    }
    parse_state->tokens[parse_state->count].name = token;
    parse_state->tokens[parse_state->count].value = NULL;
    parse_state->count++;
}

void parse_add_number(char *token) {
    double value;
    if (sscanf(token, "%lf", &value) == 1) {
        parse_add_token(token);
        parse_state->tokens[parse_state->count - 1].value = (void *)&value;
    } else {
        printf("Error: invalid number format\n");
    }
}

void parse_add_identifier(char *token) {
    if (strlen(token) == 0) {
        printf("Error: invalid identifier\n");
    } else {
        parse_add_token(token);
    }
}

void parse_parse(char *src) {
    char *token = strtok(src, " ");
    while (token != NULL && parse_state->count < TOKEN_COUNT) {
        if (strcmp(token, "int") == 0) {
            parse_add_number(token);
        } else if (strcmp(token, "double") == 0) {
            parse_add_number(token);
        } else if (strcmp(token, "void") == 0) {
            parse_add_token(token);
        } else if (strcmp(token, "if") == 0) {
            parse_add_token(token);
            parse_state->tokens[parse_state->count - 1].value = (void *)1;
        } else if (strcmp(token, "else") == 0) {
            parse_add_token(token);
            parse_state->tokens[parse_state->count - 1].value = (void *)2;
        } else {
            parse_add_identifier(token);
        }
        token = strtok(NULL, " ");
    }
}

int main(void) {
    parse_init();
    char src[] = "int x = 5; double y = 3.14; void z(); if (x > 10) { y = 2 * y; } else { z(); }";
    parse_parse(src);
    printf("tokens: ");
    for (int i = 0; i < parse_state->count; i++) {
        printf("%s = %p\n", parse_state->tokens[i].name, parse_state->tokens[i].value);
    }
    return 0;
}