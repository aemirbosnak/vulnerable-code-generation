//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// A structure to represent a stack of characters
typedef struct Stack {
    int top;
    unsigned capacity;
    char* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to stack
void push(Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop an item from stack
char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// A function to return the top item from stack without popping it
char peek(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

// Function to check if a character is a whitespace
bool isWhitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n';
}

// Function to beautify the HTML
void beautifyHTML(const char* input, char* output) {
    Stack* tags = createStack(100);
    int outputIndex = 0;
    bool insideTag = false;

    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];

        // Check for opening tag
        if (current == '<') {
            insideTag = true;
            if (outputIndex > 0 && output[outputIndex - 1] != '\n') {
                output[outputIndex++] = '\n'; // Add newline before the tag
            }
            push(tags, current);
            output[outputIndex++] = current;
        } 
        // Check for closing tag
        else if (current == '>') {
            insideTag = false;
            output[outputIndex++] = current;
            output[outputIndex] = '\0';
            pop(tags);
            continue;
        } 
        // Simply add content if not inside a tag
        else if (!insideTag) {
            if (!isWhitespace(current) || (outputIndex > 0 && !isWhitespace(output[outputIndex - 1]))) {
                output[outputIndex++] = current;
            }
        } 
        // If we are inside a tag, just add the character
        else {
            output[outputIndex++] = current;
        }
    }
    // Null-terminate the output string
    output[outputIndex] = '\0';

    // Clean up
    free(tags->array);
    free(tags);
}

// Main function to demonstrate the HTML beautifier
int main() {
    const char* inputHTML = "<html><head><title>Sample Page<title></head><body><h1>Hello World!</h1><p>This is a sample paragraph.</p></body></html>";
    char* outputHTML = (char*)malloc(strlen(inputHTML) * 2); // Allocate enough space for beautified HTML

    beautifyHTML(inputHTML, outputHTML);

    printf("Input HTML:\n%s\n\n", inputHTML);
    printf("Beautified HTML:\n%s\n", outputHTML);

    // Clean up 
    free(outputHTML);
    return 0;
}