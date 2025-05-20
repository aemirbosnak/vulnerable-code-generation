//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_VALUE_LENGTH 256
#define STACK_SIZE 100

typedef struct XmlNode {
    char tagName[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];
    struct XmlNode* next;
} XmlNode;

typedef struct Stack {
    XmlNode* nodes[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isStackFull(Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, XmlNode* node) {
    if (!isStackFull(stack)) {
        stack->nodes[++stack->top] = node;
    } else {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

XmlNode* pop(Stack* stack) {
    if (!isStackEmpty(stack)) {
        return stack->nodes[stack->top--];
    } else {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

void parseXml(FILE* file) {
    char line[512];
    char tagName[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];
    Stack stack;
    initStack(&stack);
    
    while (fgets(line, sizeof(line), file)) {
        char* startTag = strstr(line, "<");
        char* endTag = strstr(line, ">");
        if (startTag && endTag) {
            // Extract tag name
            strncpy(tagName, startTag + 1, endTag - startTag - 1);
            tagName[endTag - startTag - 1] = '\0';
            
            // Check for closing tag
            if (tagName[0] == '/') {
                // Pop from stack
                XmlNode* node = pop(&stack);
                printf("End Tag: %s\n", node->tagName);
                free(node);
            } else {
                // Push new node to stack
                XmlNode* newNode = (XmlNode*)malloc(sizeof(XmlNode));
                strncpy(newNode->tagName, tagName, MAX_TAG_NAME);
                newNode->tagName[MAX_TAG_NAME - 1] = '\0';
                
                // Optional: Extract value if present
                char* valueStart = endTag + 1;
                char* valueEnd = strstr(valueStart, "<");
                if (valueEnd) {
                    strncpy(value, valueStart, valueEnd - valueStart);
                    value[valueEnd - valueStart] = '\0';
                    strcpy(newNode->value, value);
                } else {
                    strcpy(newNode->value, "");
                }
                
                printf("Start Tag: %s, Value: %s\n", newNode->tagName, newNode->value);
                push(&stack, newNode);
            }
        }
    }
    
    // Clean up the stack
    while (!isStackEmpty(&stack)) {
        XmlNode* node = pop(&stack);
        free(node);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <XML file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    parseXml(file);
    fclose(file);
    return EXIT_SUCCESS;
}