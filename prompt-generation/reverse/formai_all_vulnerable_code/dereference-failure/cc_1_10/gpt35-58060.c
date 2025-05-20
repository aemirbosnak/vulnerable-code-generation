//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scientific
//The purpose of this program is to perform a syntax parsing on a C code snippet to check for any errors

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to represent stack
typedef struct Stack {
    int top;
    unsigned capacity;
    char* array;
} Stack;

//function to create a new stack
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

//function to check if stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

//function to check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

//function to push an element onto stack
void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

//function to pop an element from stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

//function to check if opening and closing brackets match
int bracketsMatch(char opener, char closer) {
    if (opener == '(' && closer == ')')
        return 1;
    else if (opener == '{' && closer == '}')
        return 1;
    else if (opener == '[' && closer == ']')
        return 1;
    else
        return 0;
}

//function to check if syntax is correct
int isSyntaxCorrect(char* code) {
    Stack* stack = createStack(strlen(code));
    for (int i = 0; code[i] != '\0'; i++) {
        //check for opening brackets and push onto stack
        if (code[i] == '(' || code[i] == '{' || code[i] == '[') {
            push(stack, code[i]);
        }
        //check for closing brackets and pop from stack
        if (code[i] == ')' || code[i] == '}' || code[i] == ']') {
            if (isEmpty(stack)) {
                return 0;
            }
            else if (!bracketsMatch(pop(stack), code[i])) {
                return 0;
            }
        }
    }
    return isEmpty(stack);
}

int main() {
    char code[1000];
    printf("Enter C code snippet: ");
    fgets(code, 1000, stdin);
    //remove newline character from code
    code[strlen(code) - 1] = '\0';
    if (isSyntaxCorrect(code)) {
        printf("Syntax is correct\n");
    }
    else {
        printf("Syntax is incorrect\n");
    }
    return 0;
}