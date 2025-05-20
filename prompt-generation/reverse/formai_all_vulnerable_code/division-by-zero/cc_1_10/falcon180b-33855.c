//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c;
    int operator;
    int result;

    printf("Welcome to the Arithmetic Program!\n");

    srand(time(NULL));
    operator = rand() % 4;

    switch(operator) {
        case 0: // Addition
            a = rand() % 100;
            b = rand() % 100;
            printf("Solve: %d + %d = ", a, b);
            scanf("%d", &c);
            result = a + b;
            if(result == c) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
            break;
        case 1: // Subtraction
            a = rand() % 100;
            b = rand() % 100;
            printf("Solve: %d - %d = ", a, b);
            scanf("%d", &c);
            result = a - b;
            if(result == c) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
            break;
        case 2: // Multiplication
            a = rand() % 100;
            b = rand() % 100;
            printf("Solve: %d * %d = ", a, b);
            scanf("%d", &c);
            result = a * b;
            if(result == c) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
            break;
        case 3: // Division
            a = rand() % 100;
            b = rand() % 100;
            printf("Solve: %d / %d = ", a, b);
            scanf("%d", &c);
            result = a / b;
            if(result == c) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
            break;
    }

    return 0;
}