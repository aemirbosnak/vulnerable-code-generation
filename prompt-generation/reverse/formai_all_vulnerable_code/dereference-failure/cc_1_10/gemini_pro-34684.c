//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: paranoid
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int depth;
    bool ended;
} element_t;

typedef struct {
    size_t size;
    size_t capacity;
    element_t *elements;
} stack_t;

static void stack_init(stack_t *stack) {
    stack->size = 0;
    stack->capacity = 16;
    stack->elements = malloc(sizeof(element_t) * stack->capacity);
}

static void stack_destroy(stack_t *stack) {
    free(stack->elements);
}

static bool stack_push(stack_t *stack, element_t element) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->elements = realloc(stack->elements, sizeof(element_t) * stack->capacity);
        if (stack->elements == NULL) {
            return false;
        }
    }
    stack->elements[stack->size++] = element;
    return true;
}

static bool stack_pop(stack_t *stack, element_t *element) {
    if (stack->size == 0) {
        return false;
    }
    *element = stack->elements[--stack->size];
    return true;
}

static bool stack_peek(stack_t *stack, element_t *element) {
    if (stack->size == 0) {
        return false;
    }
    *element = stack->elements[stack->size - 1];
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    stack_t stack;
    stack_init(&stack);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *start = buffer;
        while (*start != '\0') {
            if (*start == '<') {
                // Start of an element
                char *end = strchr(start, '>');
                if (end == NULL) {
                    // Malformed XML
                    fprintf(stderr, "Malformed XML: missing closing angle bracket\n");
                    return EXIT_FAILURE;
                }
                *end = '\0';
                element_t element;
                element.name = malloc(strlen(start + 1) + 1);
                strcpy(element.name, start + 1);
                element.depth = stack.size;
                element.ended = false;
                if (!stack_push(&stack, element)) {
                    // Out of memory
                    fprintf(stderr, "Out of memory\n");
                    return EXIT_FAILURE;
                }
                start = end + 1;
            } else if (*start == '/') {
                // End of an element
                char *end = strchr(start, '>');
                if (end == NULL) {
                    // Malformed XML
                    fprintf(stderr, "Malformed XML: missing closing angle bracket\n");
                    return EXIT_FAILURE;
                }
                *end = '\0';
                element_t element;
                if (!stack_peek(&stack, &element)) {
                    // Malformed XML
                    fprintf(stderr, "Malformed XML: missing opening angle bracket\n");
                    return EXIT_FAILURE;
                }
                if (strcmp(start + 2, element.name) != 0) {
                    // Malformed XML
                    fprintf(stderr, "Malformed XML: mismatched closing angle bracket\n");
                    return EXIT_FAILURE;
                }
                element.ended = true;
                if (!stack_pop(&stack, &element)) {
                    // Malformed XML
                    fprintf(stderr, "Malformed XML: unbalanced angle brackets\n");
                    return EXIT_FAILURE;
                }
                start = end + 1;
            } else {
                // Text content
                start++;
            }
        }
    }

    fclose(fp);

    // Check for unbalanced angle brackets
    if (stack.size != 0) {
        fprintf(stderr, "Malformed XML: unbalanced angle brackets\n");
        return EXIT_FAILURE;
    }

    // Print the XML structure
    for (size_t i = 0; i < stack.size; i++) {
        for (int j = 0; j < stack.elements[i].depth; j++) {
            printf("  ");
        }
        if (stack.elements[i].ended) {
            printf("</%s>\n", stack.elements[i].name);
        } else {
            printf("<%s>\n", stack.elements[i].name);
        }
    }

    stack_destroy(&stack);

    return EXIT_SUCCESS;
}