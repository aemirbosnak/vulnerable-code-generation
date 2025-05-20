//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN 100
#define MIN_OPERAND 1e-20

typedef struct Calculator {
    double stack[10];
    int top;
}Calculator;

Calculator calculator;

void push(double value) {
    if (calculator.top >= 9) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    calculator.stack[calculator.top++] = value;
}

double pop() {
    if (calculator.top <= 0) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return calculator.stack[--calculator.top];
}

void display_stack() {
    int i;
    printf("Stack: ");
    for (i = calculator.top; i >= 0; i--) {
        printf("%.12lf ", calculator.stack[i]);
    }
    printf("\n");
}

void process_operand(char op) {
    double b, a;

    a = pop();
    b = pop();

    switch (op) {
        case '+':
            push(a + b);
            break;
        case '-':
            push(a - b);
            break;
        case '*':
            push(a * b);
            break;
        case '/':
            if (b == 0) {
                printf("Error: Division by Zero\n");
                exit(EXIT_FAILURE);
            }
            push(a / b);
            break;
        case '^':
            push(pow(a, b));
            break;
        default:
            printf("Error: Unsupported Operator\n");
            exit(EXIT_FAILURE);
    }
}

int is_operator(char c) {
    return (strchr("+-*/^", c) != NULL);
}

void calculate(char *input) {
    int i;
    double num;

    calculator.top = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            num = strtod(&input[i], NULL);
            push(num);
        } else if (is_operator(input[i])) {
            process_operand(input[i]);
        } else if (input[i] == 's') {
            display_stack();
        } else {
            printf("Error: Unsupported Character\n");
            exit(EXIT_FAILURE);
        }
    }

    if (calculator.top != 1) {
        printf("Error: Stack Unbalanced\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        return EXIT_FAILURE;
    }

    calculator.top = 0;

    if (isdigit(argv[1][0])) {
        calculate(argv[1]);
    } else {
        printf("Error: Invalid Input\n");
        calculate("0");
    }

    printf("Result: %.12lf\n", pop());

    return EXIT_SUCCESS;
}