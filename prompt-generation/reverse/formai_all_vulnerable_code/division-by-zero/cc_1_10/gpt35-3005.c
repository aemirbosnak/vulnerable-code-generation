//FormAI DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {

    srand(time(NULL));
    int num1, num2, operation, answer, user_answer;
    int score = 0, incorrect = 0;
    bool running = true;

    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given a random math operation to solve.\n");
    printf("Type in your answer and press enter. Good luck!\n");

    while (running) {
        num1 = rand() % 100;
        num2 = rand() % 100;

        operation = rand() % 4;

        switch (operation) {
            case 0:
                printf("%d + %d = ", num1, num2);
                answer = num1 + num2;
                break;
            case 1:
                printf("%d - %d = ", num1, num2);
                answer = num1 - num2;
                break;
            case 2:
                printf("%d * %d = ", num1, num2);
                answer = num1 * num2;
                break;
            case 3:
                printf("%d / %d = ", num1, num2);
                answer = num1 / num2;
                break;
        }

        scanf("%d", &user_answer);

        if (user_answer == answer) {
            score++;
            printf("Correct!\n");
        } else {
            incorrect++;
            printf("Incorrect, the answer is %d\n", answer);
        }

        printf("Your current score is %d and incorrect answers are %d.\n", score, incorrect);

        printf("Would you like to continue? (1 = Yes, 2 = No)\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 2) {
            running = false;
        }
    }

    printf("Thanks for using the Math Exercise Program! Your final score is %d, with %d incorrect answers.\n", score, incorrect);

    return 0;
}