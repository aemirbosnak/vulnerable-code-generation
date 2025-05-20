//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_PROGRAM_LENGTH 1000

typedef struct {
    char *token;
    int token_length;
    int line_number;
} token_t;

typedef struct {
    token_t *tokens;
    int num_tokens;
    int current_line_number;
} program_t;

static void parse_token(program_t *program, char *buffer) {
    char *token_start = buffer;
    char *token_end = strchr(buffer, ' ');
    int token_length = token_end - buffer;

    if (token_length > MAX_TOKEN_LENGTH) {
        printf("Token too long (%d > %d)\n", token_length, MAX_TOKEN_LENGTH);
        exit(1);
    }

    program->tokens = realloc(program->tokens, (program->num_tokens + 1) * sizeof(token_t));
    program->tokens[program->num_tokens].token = buffer;
    program->tokens[program->num_tokens].token_length = token_length;
    program->tokens[program->num_tokens].line_number = program->current_line_number;
    program->num_tokens++;

    program->current_line_number += token_length + 1; // Increment line number by token length + 1 to account for the newline character
}

static void parse_program(program_t *program, char *buffer) {
    char *token_start = buffer;
    char *token_end = strchr(buffer, '\n');
    int token_length = token_end - buffer;

    if (token_length > MAX_TOKEN_LENGTH) {
        printf("Token too long (%d > %d)\n", token_length, MAX_TOKEN_LENGTH);
        exit(1);
    }

    program->tokens = realloc(program->tokens, (program->num_tokens + 1) * sizeof(token_t));
    program->tokens[program->num_tokens].token = buffer;
    program->tokens[program->num_tokens].token_length = token_length;
    program->tokens[program->num_tokens].line_number = program->current_line_number;
    program->num_tokens++;

    program->current_line_number += token_length + 1; // Increment line number by token length + 1 to account for the newline character

    if (token_end[0] == '\0') {
        // Handle empty line
        program->current_line_number++;
    }
}

int main() {
    program_t program;
    char buffer[MAX_PROGRAM_LENGTH];

    while (fgets(buffer, MAX_PROGRAM_LENGTH, stdin)) {
        parse_program(&program, buffer);
    }

    // Print the parsed program
    for (int i = 0; i < program.num_tokens; i++) {
        printf("%d: %s\n", program.tokens[i].line_number, program.tokens[i].token);
    }

    return 0;
}