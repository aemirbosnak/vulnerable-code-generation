//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STACK_SIZE 100

// Stack structure to manage tags
typedef struct {
    char *items[MAX_STACK_SIZE];
    int top;
} Stack;

// Function prototypes
void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char *tag);
char* pop(Stack *s);
char* peek(Stack *s);
void beautifyHTML(const char *inputFile, const char *outputFile);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautifyHTML(argv[1], argv[2]);
    printf("Beautification completed. Output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}

// Initializes the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Checks if stack is full
int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// Checks if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push a tag onto the stack
void push(Stack *s, char *tag) {
    if (!isFull(s)) {
        s->items[++s->top] = strdup(tag);
    }
}

// Pop a tag from the stack
char* pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return NULL;
}

// Peek at the top tag of the stack
char* peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return NULL;
}

// Function to beautify an HTML file
void beautifyHTML(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    Stack tagStack;
    initStack(&tagStack);

    if (!inFile || !outFile) {
        fprintf(stderr, "Error opening files!\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;
    
    while (fgets(line, sizeof(line), inFile)) {
        char *ptr = line;
        char tempLine[MAX_LINE_LENGTH];

        while (*ptr) {
            if (*ptr == '<') {
                if (ptr[1] == '/') { // Closing tag
                    if (indentLevel > 0) {
                        indentLevel--;
                    }
                    ptr = strchr(ptr, '>');
                    if (ptr) ptr++;
                } else {
                    // Opening tag
                    char *tagStart = ptr + 1;
                    char *tagEnd = strchr(tagStart, '>');
                    if (tagEnd) {
                        int tagLength = tagEnd - tagStart;
                        char tempTag[MAX_LINE_LENGTH];
                        strncpy(tempTag, tagStart, tagLength);
                        tempTag[tagLength] = '\0';

                        if (strstr(tempTag, "br") == NULL && strstr(tempTag, "img") == NULL) {
                            push(&tagStack, tempTag);
                            indentLevel++;
                        }
                        ptr = tagEnd + 1;
                    }
                }
                // Print correct indentation
                for (int i = 0; i < indentLevel; i++) {
                    fputs("  ", outFile);
                }
                fputs(line, outFile);
                break;
            }
            ptr++;
        }
    }

    fclose(inFile);
    fclose(outFile);
}

// Cleanup function for freeing the stack
void freeStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        free(s->items[i]);
    }
}