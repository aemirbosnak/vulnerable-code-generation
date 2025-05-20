//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, userAnswer;
    char operator;

    srand(time(0));

    printf("Welcome to the Math Exercise!\n");
    printf("Please enter the number of questions you want to solve: ");
    scanf("%d", &answer);

    for (int i = 0; i < answer; i++) {
        num1 = rand() % 100;
        num2 = rand() % 100;
        operator = rand() % 4;

        switch (operator) {
            case 0:
                printf("%d + %d: ", num1, num2);
                answer = num1 + num2;
                break;
            case 1:
                printf("%d - %d: ", num1, num2);
                answer = num1 - num2;
                break;
            case 2:
                printf("%d * %d: ", num1, num2);
                answer = num1 * num2;
                break;
            case 3:
                printf("%d / %d: ", num1, num2);
                answer = num1 / num2;
                break;
        }

        scanf("%d", &userAnswer);

        if (userAnswer == answer) {
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
    }

    printf("Thank you for playing Math Exercise!\n");

    return 0;
}