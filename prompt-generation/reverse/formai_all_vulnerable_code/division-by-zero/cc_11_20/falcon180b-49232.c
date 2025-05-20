//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int num1, num2, operator;
    int choice;

    do {
        printf("Enter the number of problems you want to solve (1-10): ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 10);

    for (int i = 0; i < choice; i++) {
        printf("\nProblem %d:\n", i+1);

        num1 = rand() % 100; // Generate a random number between 0 and 99
        num2 = rand() % 100; // Generate another random number between 0 and 99

        operator = rand() % 4; // Generate a random operator (0 for addition, 1 for subtraction, 2 for multiplication, 3 for division)

        switch (operator) {
            case 0:
                printf("Solve the following problem:\n");
                printf("%d + %d = ", num1, num2);
                break;
            case 1:
                printf("Solve the following problem:\n");
                printf("%d - %d = ", num1, num2);
                break;
            case 2:
                printf("Solve the following problem:\n");
                printf("%d * %d = ", num1, num2);
                break;
            case 3:
                while (num2 == 0) {
                    num2 = rand() % 100; // Generate another random number if the second number is 0 (to avoid division by zero)
                }
                printf("Solve the following problem:\n");
                printf("%d / %d = ", num1, num2);
                break;
        }

        int answer;
        scanf("%d", &answer);

        if (answer == num1 + num2) {
            printf("Correct!\n");
        } else if (answer == num1 - num2) {
            printf("Correct!\n");
        } else if (answer == num1 * num2) {
            printf("Correct!\n");
        } else if (answer == num1 / num2) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", num1 + num2); // Display the correct answer
        }
    }

    return 0;
}