//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int getRandomNumber(void) {
    return (rand() % 10) + 1;
}

// Function to generate a random math problem
void generateMathProblem(char op, int a, int b) {
    switch (op) {
        case '+':
            printf("What is %d + %d? ", a, b);
            break;
        case '-':
            printf("What is %d - %d? ", a, b);
            break;
        case '*':
            printf("What is %d x %d? ", a, b);
            break;
        case '/':
            printf("What is %d / %d? ", a, b);
            break;
        default:
            printf("Invalid operation. Please try again.\n");
            return;
    }
}

int main(void) {
    // Get the user's input for the math operation
    char op;
    printf("Enter the math operation (+, -, *, /): ");
    scanf("%c", &op);

    // Get the user's input for the numbers to operate on
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    // Generate the math problem and display it to the user
    generateMathProblem(op, a, b);

    // Get the user's answer
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);

    // Check if the user's answer is correct
    if (op == '+' && answer == a + b) {
        printf("Correct! The answer is %d.\n", answer);
    } else if (op == '-' && answer == a - b) {
        printf("Correct! The answer is %d.\n", answer);
    } else if (op == '*' && answer == a * b) {
        printf("Correct! The answer is %d.\n", answer);
    } else if (op == '/' && answer == a / b) {
        printf("Correct! The answer is %d.\n", answer);
    } else {
        printf("Incorrect. The answer is %d.\n", answer);
    }

    return 0;
}