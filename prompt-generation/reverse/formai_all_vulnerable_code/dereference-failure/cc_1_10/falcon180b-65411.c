//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LENGTH 4

typedef struct {
    char *text;
    int indent;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int max_line_length;
} CodeBlock;

CodeBlock *create_code_block() {
    CodeBlock *block = malloc(sizeof(CodeBlock));
    block->lines = NULL;
    block->num_lines = 0;
    block->max_line_length = MAX_LINE_LENGTH;
    return block;
}

void add_line(CodeBlock *block, const char *text, int indent) {
    Line *line = malloc(sizeof(Line));
    line->text = strdup(text);
    line->indent = indent;
    block->lines = realloc(block->lines, sizeof(Line) * (block->num_lines + 1));
    block->lines[block->num_lines++] = *line;
}

void print_line(FILE *out, const Line *line, int indent) {
    int i;
    for (i = 0; i < indent; i++) {
        fprintf(out, " ");
    }
    fprintf(out, "%s\n", line->text);
}

void print_code_block(FILE *out, const CodeBlock *block) {
    int i;
    for (i = 0; i < block->num_lines; i++) {
        print_line(out, &block->lines[i], 0);
    }
}

void free_code_block(CodeBlock *block) {
    int i;
    for (i = 0; i < block->num_lines; i++) {
        free(block->lines[i].text);
    }
    free(block->lines);
    free(block);
}

CodeBlock *parse_code(const char *input) {
    CodeBlock *block = create_code_block();
    int indent = 0;
    char *line = NULL;
    size_t line_capacity = 0;
    ssize_t read;

    while ((read = getline(&line, &line_capacity, stdin))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        }

        while (isspace(line[0])) {
            line++;
            indent++;
        }

        if (indent > MAX_INDENT_LENGTH) {
            fprintf(stderr, "Error: Maximum indent level exceeded\n");
            free_code_block(block);
            exit(1);
        }

        add_line(block, line, indent);
    }

    return block;
}

int main() {
    CodeBlock *block = parse_code(stdin);
    print_code_block(stdout, block);
    free_code_block(block);
    return 0;
}