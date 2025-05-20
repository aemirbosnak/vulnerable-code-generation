//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define STACK_SIZE 100

typedef struct {
    char *tags[STACK_SIZE];
    int top;
} TagStack;

// Function prototypes
TagStack* createStack();
int push(TagStack *stack, const char *tag);
const char* pop(TagStack *stack);
int isEmpty(TagStack *stack);
void beautifyHTML(const char *inputFile, const char *outputFile);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return 1;
    }
    beautifyHTML(argv[1], argv[2]);
    return 0;
}

TagStack* createStack() {
    TagStack *stack = (TagStack *)malloc(sizeof(TagStack));
    stack->top = -1;
    return stack;
}

int push(TagStack *stack, const char *tag) {
    if (stack->top < STACK_SIZE - 1) {
        stack->tags[++stack->top] = strdup(tag);
        return 1;
    }
    return 0; // Stack overflow
}

const char* pop(TagStack *stack) {
    if (!isEmpty(stack)) {
        return stack->tags[stack->top--];
    }
    return NULL; // Stack underflow
}

int isEmpty(TagStack *stack) {
    return stack->top == -1;
}

void beautifyHTML(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    if (!in || !out) {
        fprintf(stderr, "Error opening files.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    TagStack *stack = createStack();
    int indentLevel = 0;

    while (fgets(line, sizeof(line), in)) {
        char *pos = line;
        while (*pos) {
            if (*pos == '<') {
                char *end_tag = strchr(pos + 1, '>');
                if (end_tag) {
                    *end_tag = '\0';
                    if (pos[1] != '/') { // It's an opening tag
                        fprintf(out, "%*s%s>\n", indentLevel * 2, "", pos);
                        push(stack, pos + 1);
                        indentLevel++;
                    } else { // It's a closing tag
                        indentLevel--;
                        fprintf(out, "%*s%s>\n", indentLevel * 2, "", pos);
                        pop(stack);
                    }
                    *end_tag = '>';
                    pos = end_tag + 1;
                }
            } else {
                putchar(*pos);
                pos++;
            }
        }
    }

    free(stack);
    fclose(in);
    fclose(out);
}