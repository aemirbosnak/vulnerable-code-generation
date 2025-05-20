//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure to represent a mathematical expression
typedef struct {
    char op[2];  // operator (e.g. +, -, x, /)
    int num1, num2; // numbers in the expression
} expr;

// Function to evaluate an expression
float evaluate(expr e) {
    float result;
    switch (e.op[0]) {
        case '+':
            result = e.num1 + e.num2;
            break;
        case '-':
            result = e.num1 - e.num2;
            break;
        case '*':
            result = e.num1 * e.num2;
            break;
        case '/':
            result = e.num1 / e.num2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }
    return result;
}

// Function to parse an expression from a file
void parse_file(char *filename) {
    expr current;
    current.op[0] = '+';
    current.num1 = 0;
    current.num2 = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            continue;
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            current.op[1] = c;
            current.num2 = 0;
        } else if (c >= '0' && c <= '9') {
            current.num2 = current.num2 * 10 + (c - '0');
        } else {
            printf("Invalid character in expression\n");
            return;
        }
        if (current.op[1] != '\0') {
            evaluate(current);
            current.op[0] = '+';
            current.num1 = 0;
            current.num2 = 0;
        }
    }
    fclose(file);
}

int main() {
    char filename[] = "expression.txt";
    parse_file(filename);
    return 0;
}