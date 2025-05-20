//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define STACK_SIZE 100

typedef struct {
    char *elements[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == (STACK_SIZE - 1);
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *element) {
    if (!isFull(s)) {
        s->elements[++(s->top)] = element;
    }
}

char *pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->elements[(s->top)--];
    }
    return NULL;
}

char *peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->elements[s->top];
    }
    return NULL;
}

void beautifyHtml(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");
    char line[MAX_LINE_LENGTH];
    Stack stack;
    initStack(&stack);
    int indent = 0;

    if (!input || !output) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), input)) {
        char *token = strtok(line, "<>");
        while (token) {
            if (strchr(token, '/')) {
                // Closing tag detected
                indent--;
                fprintf(output, "%*s</%s>\n", indent * 4, "", token);
                pop(&stack);
                break;
            } else if (strlen(token) > 0) {
                // Opening tag detected
                fprintf(output, "%*s<%s>\n", indent * 4, "", token);
                push(&stack, token);
                indent++;
            }
            token = strtok(NULL, "<>");
        }
    }

    fclose(input);
    fclose(output);
}

void showUsage(char *programName) {
    fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        showUsage(argv[0]);
        return EXIT_FAILURE;
    }

    beautifyHtml(argv[1], argv[2]);
    printf("The HTML has been beautified and saved to %s.\n", argv[2]);

    return EXIT_SUCCESS;
}