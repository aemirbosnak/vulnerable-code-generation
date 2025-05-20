//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000
#define MIN_NUM 1

int main() {
    srand(time(NULL));
    int num1, num2, sum, diff, mult, div, mod;
    char op;

    printf("Welcome to the Arithmetic Game!\n");

    do {
        printf("Please enter a number: ");
        scanf("%d", &num1);

        if (num1 < MIN_NUM || num1 > MAX_NUM) {
            printf("Invalid input! Please try again.\n");
            continue;
        }

        printf("Now, please enter an operation (+, -, *, /, %): ");
        scanf(" %c", &op);

        if (op == '+') {
            num2 = rand() % MAX_NUM;
            sum = num1 + num2;
            printf("The sum of %d and %d is %d\n", num1, num2, sum);
        } else if (op == '-') {
            num2 = rand() % MAX_NUM;
            diff = num1 - num2;
            printf("The difference of %d and %d is %d\n", num1, num2, diff);
        } else if (op == '*') {
            num2 = rand() % MAX_NUM;
            mult = num1 * num2;
            printf("The product of %d and %d is %d\n", num1, num2, mult);
        } else if (op == '/') {
            num2 = rand() % MAX_NUM;
            if (num2 == 0) {
                printf("Division by zero! Please try again.\n");
                continue;
            }
            div = num1 / num2;
            printf("The quotient of %d and %d is %d\n", num1, num2, div);
        } else if (op == '%') {
            num2 = rand() % MAX_NUM;
            mod = num1 % num2;
            printf("The remainder of %d and %d is %d\n", num1, num2, mod);
        } else {
            printf("Invalid operation! Please try again.\n");
            continue;
        }
    } while (1);

    return 0;
}