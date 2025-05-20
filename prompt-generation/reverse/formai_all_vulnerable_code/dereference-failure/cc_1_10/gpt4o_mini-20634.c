//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STACK_DEPTH 100

typedef struct {
    char *tags[MAX_STACK_DEPTH];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_STACK_DEPTH - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, const char *tag) {
    if (!isFull(stack)) {
        stack->tags[++stack->top] = strdup(tag);
    }
}

char *pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->tags[stack->top--];
    }
    return NULL;
}

char *peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->tags[stack->top];
    }
    return NULL;
}

void trimWhitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    
    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;
}

void beautifyHTML(const char *input) {
    Stack stack;
    initStack(&stack);
    
    char line[MAX_LINE_LENGTH];
    const char *ptr = input;
    int indentLevel = 0;

    while (*ptr) {
        int lineWidth = 0;
        
        // Start collecting a line
        char tag[MAX_LINE_LENGTH] = {0};
        int isTag = 0;

        while (*ptr && lineWidth < MAX_LINE_LENGTH - 1) {
            if (*ptr == '<') {
                if (isTag) {
                    // Finish current tag
                    break;
                }
                isTag = 1; // we have found the start of a tag
            } 
            if (isTag) {
                // Add char to the tag
                tag[lineWidth++] = *ptr;
            } else {
                // Regular text outside tag
                line[lineWidth++] = *ptr;
            }
            ptr++;
        }

        // If we finished a tag and it was a closing tag or self-closing
        tag[lineWidth] = '\0';
        if (isTag) {
            trimWhitespace(tag);

            if (tag[0] == '<' && tag[1] == '/') {
                // Closing tag
                indentLevel--;
                if (indentLevel < 0) indentLevel = 0;
                for (int i = 0; i < indentLevel; i++) printf("    ");
                printf("%s\n", tag);
                continue;
            }

            // Push tag to stack
            if (tag[0] == '<' && tag[strlen(tag)-2] != '/') {
                // Not a self-closing tag
                push(&stack, tag);
                for (int i = 0; i < indentLevel; i++) printf("    ");
                printf("%s\n", tag);
                indentLevel++;
            } else {
                // Self-closing tag
                for (int i = 0; i < indentLevel; i++) printf("    ");
                printf("%s\n", tag);
            }
        }

        if (lineWidth > 0) {
            line[lineWidth] = '\0';
            for (int i = 0; i < indentLevel; i++) printf("    ");
            printf("%s\n", line);
        }

        memset(line, 0, sizeof(line));
    }

    // Clean up remaining tags in the stack
    while (!isEmpty(&stack)) {
        char *tag = pop(&stack);
        if (tag) free(tag);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <html_string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *inputHTML = argv[1];
    
    printf("Beautified HTML:\n");
    beautifyHTML(inputHTML);
    
    return EXIT_SUCCESS;
}