//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 100 // magic number for randomness

int main() {
    int num1, num2, sum, diff, multi, div;
    char op;

    srand(time(NULL)); // seed randomness

    printf("Welcome to the C Math Exercise Program!\n");

    // exercise 1: evaluate a simple expression
    printf("Enter a simple expression: ");
    scanf("%d%c", &num1, &op);
    if (op == '+') {
        printf("5 + %d = %d\n", num1, num1 + 5);
    } else if (op == '-') {
        printf("5 - %d = %d\n", num1, num1 - 5);
    } else if (op == '*') {
        printf("5 * %d = %d\n", num1, num1 * 5);
    } else if (op == '/') {
        printf("5 / %d = %d\n", num1, num1 / 5);
    }

    // exercise 2: evaluate a more complex expression
    printf("Enter a more complex expression: ");
    scanf("%d%c%d", &num1, &op, &num2);
    if (op == '+') {
        sum = num1 + num2;
        printf("(%d + %d) = %d\n", num1, num2, sum);
    } else if (op == '-') {
        diff = num1 - num2;
        printf("(%d - %d) = %d\n", num1, num2, diff);
    } else if (op == '*') {
        multi = num1 * num2;
        printf("(%d * %d) = %d\n", num1, num2, multi);
    } else if (op == '/') {
        div = num1 / num2;
        printf("(%d / %d) = %d\n", num1, num2, div);
    }

    // exercise 3: calculate the factorial of a number
    printf("Enter a number: ");
    scanf("%d", &num1);
    if (num1 == 0) {
        printf("0! = 1\n");
    } else {
        printf("%d! = %d\n", num1, factorial(num1));
    }

    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}