//FormAI DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, user_answer, score = 0, question_count = 0;
    char operators[4] = {'+', '-', '*', '/'};

    // set random seed to current time
    srand(time(NULL));

    printf("Welcome to the C Math Exercise Program\n");

    while (1) {
        // generate random numbers and operator
        num1 = rand() % 100;
        num2 = rand() % 100;
        operator = rand() % 4;

        // get answer from user
        printf("What is %d %c %d? ", num1, operators[operator], num2);
        scanf("%d", &user_answer);

        // calculate correct answer
        switch (operator) {
            case 0:
                answer = num1 + num2;
                break;
            case 1:
                answer = num1 - num2;
                break;
            case 2:
                answer = num1 * num2;
                break;
            case 3:
                answer = num1 / num2;
                break;
        }

        // check user answer and update score
        if (user_answer == answer) {
            score++;
            printf("Correct! Your score is now %d\n", score);
        } else {
            printf("Incorrect. The correct answer is %d\n", answer);
        }

        // count number of questions asked
        question_count++;

        // ask user if they want to continue or quit
        printf("Do you want to continue? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            printf("Thanks for playing! You answered %d questions and scored %d/%d\n", question_count, score, question_count);
            break;
        }
    }

    return 0;
}