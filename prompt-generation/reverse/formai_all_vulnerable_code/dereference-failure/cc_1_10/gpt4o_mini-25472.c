//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 50
#define MAX_VALUE_LENGTH 255
#define MAX_STACK_SIZE 100

typedef struct {
    char tags[MAX_STACK_SIZE][MAX_TAG_NAME];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to push a tag onto the stack
void push(Stack* s, const char* tag) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->top++;
        strcpy(s->tags[s->top], tag);
    } else {
        printf("Stack overflow!\n");
    }
}

// Function to pop a tag from the stack
void pop(Stack* s) {
    if (s->top > -1) {
        s->top--;
    } else {
        printf("Stack underflow!\n");
    }
}

// Function to retrieve the top tag from the stack
const char* top(const Stack* s) {
    if (s->top > -1) {
        return s->tags[s->top];
    }
    return NULL;
}

// Function to trim whitespace from a string
char* trimWhitespace(char* str) {
    char* end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;

    return str;
}

// Function to parse XML file
void parseXML(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Stack stack;
    initStack(&stack);
    char line[MAX_VALUE_LENGTH];
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char* start = strchr(line, '<');
        char* end = strchr(line, '>');
        if (start && end && end > start) {
            // Extract the tag name
            int tagLength = end - start - 1;
            if (line[start - line + 1] != '/') { // Opening tag
                sscanf(start + 1, "%s", tag);
                push(&stack, tag);
                printf("Start tag: %s\n", tag);
            } else { // Closing tag
                sscanf(start + 2, "%s", tag);
                if (strcmp(tag, top(&stack)) == 0) {
                    printf("End tag: %s\n", tag);
                    pop(&stack);
                } else {
                    printf("Error: Mismatched tag! Expected %s but found %s\n", top(&stack), tag);
                }
            }
        }
        
        // Extract value between tags, if any
        char* valueStart = end + 1;
        char* valueEnd = strchr(valueStart, '<');
        if (valueEnd && valueEnd > valueStart) {
            strncpy(value, valueStart, valueEnd - valueStart);
            value[valueEnd - valueStart] = '\0';
            trimWhitespace(value);
            if (strlen(value) > 0) {
                printf("Value found: %s\n", value);
            }
        }
    }

    if (stack.top != -1) {
        printf("Error: Unmatched start tag %s\n", top(&stack));
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename.xml>\n", argv[0]);
        return 1;
    }

    parseXML(argv[1]);
    return 0;
}