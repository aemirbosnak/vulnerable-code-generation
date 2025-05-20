//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct node {
    char *data;
    struct node *next;
};

struct stack {
    struct node *top;
};

void push(struct stack *stack, char *data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

char *pop(struct stack *stack) {
    if (stack->top == NULL) {
        return NULL;
    }

    char *data = stack->top->data;
    struct node *new_top = stack->top->next;
    free(stack->top);
    stack->top = new_top;

    return data;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    struct stack stack;
    stack.top = NULL;

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        char *trimmed_line = strdup(line);
        while (trimmed_line[strlen(trimmed_line) - 1] == '\n' || trimmed_line[strlen(trimmed_line) - 1] == '\r') {
            trimmed_line[strlen(trimmed_line) - 1] = '\0';
        }

        if (strlen(trimmed_line) == 0) {
            continue;
        }

        if (trimmed_line[0] == '<') {
            push(&stack, trimmed_line);
        } else if (trimmed_line[0] == '>') {
            char *popped_line = pop(&stack);
            if (popped_line == NULL) {
                fprintf(stderr, "Error: unbalanced HTML tags\n");
                exit(1);
            }

            printf("%s%s\n", popped_line, trimmed_line);
        } else {
            printf("%s\n", trimmed_line);
        }

        free(trimmed_line);
    }

    fclose(input_file);

    return 0;
}