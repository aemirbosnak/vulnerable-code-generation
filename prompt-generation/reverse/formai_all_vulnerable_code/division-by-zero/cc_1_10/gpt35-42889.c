//FormAI DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Modular function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Modular function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Modular function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Modular function to divide two numbers
int divide(int a, int b) {
    return a / b;
}

// Main function
int main() {
    int a, b;
    char operator;
    
    // Prompt user for input
    printf("Enter an arithmetic expression: ");
    scanf("%d %c %d", &a, &operator, &b);
    
    // Calculate result based on user input
    switch(operator) {
        case '+':
            printf("%d + %d = %d", a, b, add(a, b));
            break;
        case '-':
            printf("%d - %d = %d", a, b, subtract(a, b));
            break;
        case '*':
            printf("%d * %d = %d", a, b, multiply(a, b));
            break;
        case '/':
            printf("%d / %d = %d", a, b, divide(a, b));
            break;
        default:
            printf("Invalid operator");
            break;
    }
    
    return 0;
}