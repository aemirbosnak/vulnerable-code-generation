//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a stack data structure
typedef struct Stack {
    char* data;
    int top;
    int capacity;
} Stack;

// Initialize a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char*)malloc(sizeof(char) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, char element) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = element;
}

// Pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Check if a string is a palindrome using a stack
bool isPalindrome(char* str) {
    int len = strlen(str);
    
    // Create a stack
    Stack* stack = createStack(len);
    
    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    
    // Pop all characters from the stack and compare them with the original string
    for (int i = 0; i < len; i++) {
        char c = pop(stack);
        if (c != str[i]) {
            return false;
        }
    }
    
    // If all characters match, the string is a palindrome
    return true;
}

int main() {
    char str[] = "racecar";
    
    if (isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    
    return 0;
}