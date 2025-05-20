//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_VALUE -1000000000
#define MAX_VALUE 1000000000

int main() {
    int num1, num2, sum, diff, multi, div, mod;
    char op;

    printf("Welcome to Arithmetic Land!\n");

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);

        printf("Enter an operation (+, -, *, /, %): ");
        scanf(" %c", &op);

        if (op == '+') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            sum = num1 + num2;
            printf("The sum is %d\n", sum);
        } else if (op == '-') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            diff = num1 - num2;
            printf("The difference is %d\n", diff);
        } else if (op == '*') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            multi = num1 * num2;
            printf("The product is %d\n", multi);
        } else if (op == '/') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            div = num1 / num2;
            printf("The quotient is %d\n", div);
        } else if (op == '%') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            mod = num1 % num2;
            printf("The remainder is %d\n", mod);
        } else {
            printf("Invalid operation. Please try again.\n");
        }
    } while (1);

    return 0;
}