//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 100

// Define function types
typedef double (*math_func)(double);

// Define math functions
double sin_func(double x) { return sin(x); }
double cos_func(double x) { return cos(x); }
double tan_func(double x) { return tan(x); }
double log_func(double x) { return log(x); }

typedef struct {
    double stack[STACK_SIZE];
    int top;
} stack_t;

stack_t* create_stack() {
    stack_t* stack = (stack_t*) malloc(sizeof(stack_t));
    stack->top = -1;
    return stack;
}

void push(stack_t* stack, double value) {
    if (stack->top == STACK_SIZE - 1) {
        printf("Stack overflow error\n");
    } else {
        stack->stack[++stack->top] = value;
    }
}

double pop(stack_t* stack) {
    if (stack->top == -1) {
        printf("Stack underflow error\n");
        return -1;
    } else {
        return stack->stack[stack->top--];
    }
}

double peek(stack_t* stack) {
    if (stack->top == -1) {
        printf("Stack underflow error\n");
        return -1;
    } else {
        return stack->stack[stack->top];
    }
}

void clear_stack(stack_t* stack) {
    while (stack->top != -1) {
        pop(stack);
    }
}

void handle_operator(char operator, stack_t* stack) {
    double a = pop(stack);
    double b;
    if (operator != '!')
        b = pop(stack);
    switch (operator) {
        case '+': push(stack, a + b); break;
        case '-': push(stack, b - a); break;
        case '*': push(stack, a * b); break;
        case '/': push(stack, b / a); break;
        case '^': push(stack, pow(b, a)); break;
        case 's': push(stack, sin_func(a)); break;
        case 'c': push(stack, cos_func(a)); break;
        case 't': push(stack, tan_func(a)); break;
        case 'l': push(stack, log_func(a)); break;
        case '!': push(stack, -a); break;
    }
}

void handle_input(const char* input, stack_t* stack) {
    int i = 0;
    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            double n = 0;
            while (isdigit(input[i])) {
                n = n * 10 + (double) (input[i] - '0');
                i++;
            }
            push(stack, n);
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == 's' || input[i] == 'c' || input[i] == 't' || input[i] == 'l' || input[i] == '!') {
            handle_operator(input[i], stack);
            i++;
        } else {
            i++;
        }
    }
}

int main() {
    printf("Welcome to paranoid scientific calculator!\n");
    printf("This calculator only accepts math operators and shuns any foreign code.\n");
    printf("Enter any operator with double operands followed by an equal sign to evaluate the expression.\n");
    printf("Supported operators: + - * / ^ s c t l (! is unary negation operator)\n");

    char input[100];
    stack_t* stack = create_stack();

    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        handle_input(input, stack);
        printf("Result: %.2f\n", pop(stack));
        clear_stack(stack);
    }
    free(stack);
    return 0;
}