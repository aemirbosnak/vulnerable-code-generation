//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_LINE_LENGTH 1000

typedef struct Stack {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    } else {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    } else {
        return s->data[(s->top)--];
    }
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    Stack stack;
    stack.top = -1;
    int indent_level = 0;
    int i, j;

    // Check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open file for reading
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int len = strlen(line);
        if (len == 1 && line[0] == '\n') {
            // Ignore blank lines
            continue;
        }

        // Count opening and closing tags on this line
        int open_tags = 0, closing_tags = 0;
        for (i = 0; i < len; i++) {
            if (line[i] == '<') {
                if (line[i+1] != '/') {
                    // Opening tag
                    open_tags++;
                    if (line[i+1] == '!' || line[i+1] == '?') {
                        // Ignore comments and processing instructions
                        open_tags--;
                    } else {
                        // Push tag onto stack
                        push(&stack, line[i+1]);
                    }
                } else {
                    // Closing tag
                    closing_tags++;
                    i += 2; // Skip ahead to tag name
                    while (line[i] != '>') {
                        i++;
                    }
                    char opening_tag = pop(&stack);
                    if (opening_tag != line[i-1]) {
                        // The closing tag does not match the last opening tag
                        fprintf(stderr, "Error: closing tag </%c> does not match opening tag <%c>\n", line[i-1], opening_tag);
                        fclose(fp);
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }

        // Print opening tags on a line by themselves
        for (j = 0; j < open_tags; j++) {
            for (i = 0; i < indent_level; i++) {
                printf("  ");
            }
            printf("<%c>\n", pop(&stack));
            indent_level++;
        }

        // Print non-tag text with the current indentation level
        for (i = 0; i < len; i++) {
            if (line[i] == '<' || line[i] == '>') {
                // Ignore angle brackets
                continue;
            } else if (line[i] == '/') {
                // Ignore slashes in closing tags
                continue;
            } else {
                // Print the character
                for (j = 0; j < indent_level; j++) {
                    printf("  ");
                }
                putchar(line[i]);
                if (line[i+1] == '<') {
                    // Add a newline after a non-tag character if the next character is a tag
                    putchar('\n');
                }
            }
        }

        // Print closing tags on a line by themselves
        for (j = 0; j < closing_tags; j++) {
            indent_level--;
            for (i = 0; i < indent_level; i++) {
                printf("  ");
            }
            printf("</%c>\n", pop(&stack));
        }
    }

    // Close file and exit program
    fclose(fp);
    exit(EXIT_SUCCESS);
}