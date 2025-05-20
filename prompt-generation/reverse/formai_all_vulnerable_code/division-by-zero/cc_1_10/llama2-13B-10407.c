//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

void math_exercise(int num1, int num2, int op, int num3) {
    int result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            result = -1;
            break;
    }

    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, num3;
    char op;

    printf("Welcome to the retro math exercise program! \n");

    printf("Please enter the first number: ");
    scanf("%d", &num1);

    printf("Please enter the second number: ");
    scanf("%d", &num2);

    printf("Please enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Please enter the third number: ");
    scanf("%d", &num3);

    math_exercise(num1, num2, op, num3);

    return 0;
}