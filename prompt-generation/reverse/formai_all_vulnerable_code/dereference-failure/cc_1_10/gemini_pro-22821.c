//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS_PER_LINE 10

typedef struct {
    char *str;
    int len;
} Token;

typedef struct {
    Token tokens[MAX_TOKENS_PER_LINE];
    int num_tokens;
} Line;

typedef struct {
    Line lines[MAX_LINE_LENGTH];
    int num_lines;
} Program;

// Reads a line of input from the user.
char *read_line() {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, stdin);
    return line;
}

// Tokenizes a line of input.
Line tokenize_line(char *line) {
    Line line_tokens;
    line_tokens.num_tokens = 0;

    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        line_tokens.tokens[line_tokens.num_tokens].str = token;
        line_tokens.tokens[line_tokens.num_tokens].len = strlen(token);
        line_tokens.num_tokens++;
        token = strtok(NULL, " \t\n");
    }

    return line_tokens;
}

// Parses a program.
Program parse_program(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    Program program;
    program.num_lines = 0;

    char *line = read_line();
    while (line != NULL) {
        program.lines[program.num_lines] = tokenize_line(line);
        program.num_lines++;
        free(line);
        line = read_line();
    }

    fclose(fp);

    return program;
}

// Prints a program.
void print_program(Program program) {
    for (int i = 0; i < program.num_lines; i++) {
        Line line = program.lines[i];
        for (int j = 0; j < line.num_tokens; j++) {
            Token token = line.tokens[j];
            printf("%s ", token.str);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Program program = parse_program(argv[1]);
    print_program(program);

    return 0;
}