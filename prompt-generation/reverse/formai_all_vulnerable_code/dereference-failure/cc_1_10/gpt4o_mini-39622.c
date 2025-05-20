//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char **lines;
    int count;
} CodeBlock;

void init_code_block(CodeBlock *cb) {
    cb->lines = malloc(MAX_LINES * sizeof(char *));
    for (int i = 0; i < MAX_LINES; i++) {
        cb->lines[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    cb->count = 0;
}

void free_code_block(CodeBlock *cb) {
    for (int i = 0; i < MAX_LINES; i++) {
        free(cb->lines[i]);
    }
    free(cb->lines);
}

void add_line(CodeBlock *cb, const char *line) {
    if (cb->count < MAX_LINES) {
        strncpy(cb->lines[cb->count], line, MAX_LINE_LENGTH - 1);
        cb->lines[cb->count][MAX_LINE_LENGTH - 1] = '\0'; // ensure null-termination
        cb->count++;
    } else {
        printf("Code block is full!\n");
    }
}

void print_code_block(const CodeBlock *cb) {
    for (int i = 0; i < cb->count; i++) {
        printf("%s", cb->lines[i]);
    }
}

int is_comment(const char *line) {
    return (line[0] == '/' && line[1] == '/');
}

int is_empty(const char *line) {
    return (line[0] == '\0' || strcmp(line, "\n") == 0);
}

int is_valid_syntax(const char *line) {
    // Basic sanity checks for a valid line of C code
    return (line[strlen(line) - 1] == ';' || strncmp(line, "return", 6) == 0);
}

void parse_code(const CodeBlock *cb) {
    for (int i = 0; i < cb->count; i++) {
        const char *line = cb->lines[i];
        
        if (is_comment(line)) {
            printf("Comment: %s", line);
        } else if (is_empty(line)) {
            printf("Empty line\n");
        } else if (is_valid_syntax(line)) {
            printf("Valid C code: %s", line);
        } else {
            printf("Syntax error: %s", line);
        }
    }
}

int main() {
    CodeBlock code;
    init_code_block(&code);

    // Example C code lines to parse
    add_line(&code, "// This is a comment\n");
    add_line(&code, "int x = 10;\n");
    add_line(&code, "x += 2;\n");
    add_line(&code, "if (x > 10) {\n");
    add_line(&code, "    return x;\n");
    add_line(&code, "}\n");
    add_line(&code, "\n");
    add_line(&code, "#include <stdio.h>\n");
    add_line(&code, "int main() {\n");
    add_line(&code, "    printf(\"Hello, World!\\n\");\n");
    add_line(&code, "    return 0;\n");
    add_line(&code, "}\n");
    add_line(&code, "Invalid Code Line");

    print_code_block(&code);
    printf("\nParsing Code Block...\n");
    parse_code(&code);

    free_code_block(&code);
    return 0;
}