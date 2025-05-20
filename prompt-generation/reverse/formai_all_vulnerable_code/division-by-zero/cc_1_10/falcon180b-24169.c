//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result;
    int choice;
    char playAgain;

    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;

    printf("Welcome to the Arithmetic Game!\n");
    printf("You will be given two numbers and an operation to perform.\n");
    printf("Enter the correct answer to earn points!\n\n");

    do {
        printf("What would you like to do?\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("The numbers are %d and %d.\n", num1, num2);
                result = num1 + num2;
                break;
            case 2:
                printf("The numbers are %d and %d.\n", num1, num2);
                result = num1 - num2;
                break;
            case 3:
                printf("The numbers are %d and %d.\n", num1, num2);
                result = num1 * num2;
                break;
            case 4:
                printf("The numbers are %d and %d.\n", num1, num2);
                result = num1 / num2;
                break;
            default:
                printf("Invalid choice!\n");
                result = -1;
        }

        printf("Enter your answer: ");
        scanf("%d", &result);

        if (result == result) {
            printf("Correct!\n");
            printf("You earned 10 points!\n");
        } else {
            printf("Incorrect.\n");
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}