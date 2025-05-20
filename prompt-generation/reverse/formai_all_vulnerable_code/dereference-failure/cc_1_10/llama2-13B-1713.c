//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PROGRAM_SIZE 4096

typedef struct {
    char *name;
    size_t size;
} symbol_t;

typedef struct {
    char *name;
    size_t size;
    symbol_t *symbols;
} program_t;

void parse_program(program_t *program) {
    char line[MAX_LINE_LENGTH];
    size_t line_num = 0;

    // Parse the program line by line
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        line_num++;

        // Skip comments and empty lines
        if (line[0] == '/' && line[1] == '/') {
            continue;
        } else if (strcmp(line, "") == 0) {
            continue;
        }

        // Tokenize the line
        char *token = strtok(line, " ");
        while (token != NULL && token[0] != '\0') {
            // Add the token to the program
            symbol_t *symbol = malloc(sizeof(symbol_t));
            symbol->name = token;
            symbol->size = strcspn(token, " ");
            program->symbols = realloc(program->symbols, (program->size + 1) * sizeof(symbol_t));
            program->symbols[program->size] = *symbol;
            program->size++;

            // Advance to the next token
            token = strtok(NULL, " ");
        }
    }
}

void print_statistics(program_t *program) {
    printf("Program Statistics:\n");
    printf("  Number of lines: %zu\n", program->size);
    printf("  Number of symbols: %zu\n", program->symbols->size);
    printf("  Largest symbol: %s (%zu bytes)\n", program->symbols->name, program->symbols->size);
    printf("  Average symbol size: %zu bytes\n", (program->symbols->size + 1) / program->symbols->size);
}

int main() {
    program_t program;
    parse_program(&program);
    print_statistics(&program);
    return 0;
}