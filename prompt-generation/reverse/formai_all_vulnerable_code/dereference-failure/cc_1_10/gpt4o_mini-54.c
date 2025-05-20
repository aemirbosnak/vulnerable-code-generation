//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STACK_DEPTH 100

typedef struct {
    char *stack[MAX_STACK_DEPTH];
    int top;
} IndentStack;

void initStack(IndentStack *s) {
    s->top = -1;
}

bool push(IndentStack *s, const char *str) {
    if (s->top >= MAX_STACK_DEPTH - 1) {
        return false;
    }
    s->top++;
    s->stack[s->top] = strdup(str);
    return true;
}

char* pop(IndentStack *s) {
    if (s->top < 0) {
        return NULL;
    }
    char *topStr = s->stack[s->top];
    s->top--;
    return topStr;
}

bool isOpeningTag(const char *line) {
    return strstr(line, "<") && !strstr(line, "</");
}

bool isClosingTag(const char *line) {
    return strstr(line, "</") && strstr(line, ">");
}

void beautifyLine(const char *line, FILE *output, int indentLevel) {
    for (int i = 0; i < indentLevel; i++) {
        fprintf(output, "    "); // 4 spaces for indentation
    }
    fprintf(output, "%s\n", line);
}

void beautifyHTML(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    if (!input) {
        fprintf(stderr, "Error opening input file.\n");
        return;
    }
    
    FILE *output = fopen(outputFile, "w");
    if (!output) {
        fprintf(stderr, "Error opening output file.\n");
        fclose(input);
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    IndentStack stack;
    initStack(&stack);
    int indentLevel = 0;

    while (fgets(line, sizeof(line), input)) {
        char *trimmedLine = line;
        // Trim line of whitespace at the start and end
        while (*trimmedLine == ' ' || *trimmedLine == '\t') trimmedLine++;
        char *end = trimmedLine + strlen(trimmedLine) - 1;
        while (end > trimmedLine && (*end == ' ' || *end == '\t' || *end == '\n')) end--;
        *(end + 1) = '\0';

        if (strlen(trimmedLine) > 0) {
            beautifyLine(trimmedLine, output, indentLevel);
            if (isOpeningTag(trimmedLine)) {
                push(&stack, trimmedLine);
                indentLevel++;
            }
            if (isClosingTag(trimmedLine)) {
                indentLevel--;
                if (!pop(&stack)) {
                    fprintf(stderr, "Warning: Unmatched closing tag in file.\n");
                }
            }
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautifyHTML(argv[1], argv[2]);
    printf("HTML beautification completed. Output written to %s\n", argv[2]);
    return EXIT_SUCCESS;
}