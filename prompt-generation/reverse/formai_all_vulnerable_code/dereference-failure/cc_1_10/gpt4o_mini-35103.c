//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 100

typedef struct Tag {
    char name[MAX_TAG_LENGTH];
    struct Tag *next;
} Tag;

typedef struct {
    Tag *top;
} TagStack;

void initStack(TagStack *stack) {
    stack->top = NULL;
}

int isStackEmpty(TagStack *stack) {
    return stack->top == NULL;
}

void push(TagStack *stack, const char *tagName) {
    Tag *newTag = (Tag *)malloc(sizeof(Tag));
    strncpy(newTag->name, tagName, MAX_TAG_LENGTH);
    newTag->next = stack->top;
    stack->top = newTag;
}

void pop(TagStack *stack) {
    if (!isStackEmpty(stack)) {
        Tag *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

const char* topTag(TagStack *stack) {
    return isStackEmpty(stack) ? NULL : stack->top->name;
}

void freeStack(TagStack *stack) {
    while (!isStackEmpty(stack)) {
        pop(stack);
    }
}

void parseXML(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    TagStack stack;
    initStack(&stack);
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char *openTagStart = strchr(line, '<');
        char *closeTagStart = strchr(line, '>');
        
        if (openTagStart != NULL && closeTagStart != NULL) {
            // Process the opening tag
            if (line[1] != '/') { // Not a closing tag
                char tagName[MAX_TAG_LENGTH] = {0};
                sscanf(openTagStart, "<%s", tagName);
                push(&stack, tagName);
                printf("Opening tag found: %s\n", tagName);
            } else { // Closing tag
                char tagName[MAX_TAG_LENGTH] = {0};
                sscanf(openTagStart + 2, "%s", tagName);
                if (!isStackEmpty(&stack) && strcmp(topTag(&stack), tagName) == 0) {
                    printf("Closing tag found: %s\n", tagName);
                    pop(&stack);
                } else {
                    printf("Mismatched closing tag: %s\n", tagName);
                }
            }
        }
    }

    // If stack is not empty, we have unmatched opening tags
    while (!isStackEmpty(&stack)) {
        printf("Unmatched opening tag: %s\n", topTag(&stack));
        pop(&stack);
    }

    fclose(file);
    freeStack(&stack);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parseXML(argv[1]);

    return EXIT_SUCCESS;
}