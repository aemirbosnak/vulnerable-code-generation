//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

typedef struct {
    char** lines;
    int line_count;
} SourceCode;

void init_source_code(SourceCode* code) {
    code->line_count = 0;
    code->lines = (char**)malloc(MAX_LINES * sizeof(char*));
    for (int i = 0; i < MAX_LINES; i++) {
        code->lines[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
    }
}

void free_source_code(SourceCode* code) {
    for (int i = 0; i < MAX_LINES; i++) {
        free(code->lines[i]);
    }
    free(code->lines);
}

void read_source_code(SourceCode* code) {
    printf("Enter your C syntax lines (press enter twice to finish):\n");
    while (1) {
        if (fgets(code->lines[code->line_count], MAX_LENGTH, stdin) == NULL || code->line_count >= MAX_LINES - 1) {
            break;
        }
        if (strcmp(code->lines[code->line_count], "\n") == 0) {
            break;
        }
        code->line_count++;
    }
}

void display_source_code(const SourceCode* code) {
    printf("\nSource Code:\n");
    for (int i = 0; i < code->line_count; i++) {
        printf("%s", code->lines[i]);
    }
}

int is_valid_identifier(const char* s) {
    if (!isalpha(s[0]) && s[0] != '_') return 0;
    for (int i = 1; s[i] != '\0' && s[i] != '\n'; i++) {
        if (!isalnum(s[i]) && s[i] != '_') return 0;
    }
    return 1;
}

void parse_source_code(const SourceCode* code) {
    printf("\nParsing Results:\n");
    for (int i = 0; i < code->line_count; i++) {
        char* line = strtok(code->lines[i], " \n");
        while (line != NULL) {
            if (is_valid_identifier(line)) {
                printf("Valid Identifier: %s\n", line);
            } else {
                printf("Invalid Identifier: %s\n", line);
            }
            line = strtok(NULL, " \n");
        }
    }
}

int main() {
    SourceCode code;
    init_source_code(&code);
    read_source_code(&code);
    display_source_code(&code);
    parse_source_code(&code);
    free_source_code(&code);
    return 0;
}