//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STACK_SIZE 100

typedef struct {
    char *data[MAX_STACK_SIZE];
    int top;
} Stack;

// Stack functions
void initStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *elem) {
    if (!isStackFull(s)) {
        s->data[++s->top] = elem;
    }
}

char *pop(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top--];
    }
    return NULL;
}

char *peek(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top];
    }
    return NULL;
}

// Function to add indent
void addIndentation(int level, char *output, int max_length) {
    for (int i = 0; i < level; i++) {
        strncat(output, "    ", max_length - strlen(output) - 1);
    }
}

// Function to beautify HTML
void beautifyHTML(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    char line[MAX_LINE_LENGTH];
    Stack stack;
    int indentLevel = 0;
    initStack(&stack);

    if (!in || !out) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), in)) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            // Check for opening tag
            if (token[0] == '<' && token[1] != '/') {
                addIndentation(indentLevel, line, sizeof(line));
                fprintf(out, "%s\n", line);
                push(&stack, token);
                indentLevel++;
            }
            // Check for closing tag
            else if (token[0] == '<' && token[1] == '/') {
                indentLevel--;
                addIndentation(indentLevel, line, sizeof(line));
                fprintf(out, "%s\n", line);
            }
            // Output regular text
            else {
                addIndentation(indentLevel, line, sizeof(line));
                fprintf(out, "%s %s\n", line, token);
            }
            token = strtok(NULL, " \n");
        }
    }

    fclose(in);
    fclose(out);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautifyHTML(argv[1], argv[2]);
    printf("HTML beautification completed. Output written to %s\n", argv[2]);

    return EXIT_SUCCESS;
}