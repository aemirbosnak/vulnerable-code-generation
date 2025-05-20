//FormAI DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, operator, answer, userAnswer, correctAnswers = 0, totalQuestions = 0;
    char response;

    srand(time(0));

    printf("Welcome to the Math Exercise program!\n");

    do {
        printf("\n\nPlease choose a difficulty level:\n");
        printf("1. Easy (Addition and Subtraction)\n");
        printf("2. Medium (Multiplication and Division)\n");
        printf("3. Hard (Mixed Operations)\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &operator);

        switch(operator) {
            case 1:
                printf("\nLevel: Easy (Addition and Subtraction)\n");
                for(int i=0;i<10;i++) {
                    num1 = rand() % 101; // Range is 0-100
                    num2 = rand() % 101;
                    operator = rand() % 2; // 0 for addition and 1 for subtraction
                    if (operator == 0) {
                        answer = num1 + num2;
                        printf("%d + %d = ", num1, num2);
                    }
                    else {
                        answer = num1 - num2;
                        printf("%d - %d = ", num1, num2);
                    }
                    totalQuestions++;
                    scanf("%d", &userAnswer);
                    if (answer == userAnswer) {
                        printf("Correct!\n");
                        correctAnswers++;
                    }
                    else {
                        printf("Incorrect! The correct answer is %d\n", answer);
                    }
                }
                break;

            case 2:
                printf("\nLevel: Medium (Multiplication and Division)\n");
                for(int i=0;i<10;i++) {
                    num1 = rand() % 13; // Range is 0-12
                    num2 = rand() % 13;
                    operator = rand() % 2; // 0 for multiplication and 1 for division
                    if (operator == 0) {
                        answer = num1 * num2;
                        printf("%d x %d = ", num1, num2);
                    }
                    else {
                        answer = num1 / num2;
                        printf("%d / %d = ", num1, num2);
                    }
                    totalQuestions++;
                    scanf("%d", &userAnswer);
                    if (answer == userAnswer) {
                        printf("Correct!\n");
                        correctAnswers++;
                    }
                    else {
                        printf("Incorrect! The correct answer is %d\n", answer);
                    }
                }
                break;

            case 3:
                printf("\nLevel: Hard (Mixed Operations)\n");
                for(int i=0;i<10;i++) {
                    num1 = rand() % 101; // Range is 0-100
                    num2 = rand() % 101;
                    operator = rand() % 4; // 0 for addition, 1 for subtraction, 2 for multiplication, and 3 for division
                    if (operator == 0) {
                        answer = num1 + num2;
                        printf("%d + %d = ", num1, num2);
                    }
                    else if (operator == 1) {
                        answer = num1 - num2;
                        printf("%d - %d = ", num1, num2);
                    }
                    else if (operator == 2) {
                        num1 = rand() % 13; // Range is 0-12
                        num2 = rand() % 13;
                        answer = num1 * num2;
                        printf("%d x %d = ", num1, num2);
                    }
                    else {
                        num1 = rand() % 13; // Range is 0-12
                        num2 = rand() % 12 + 1; // Range is 1-12
                        num1 = num1 * num2;
                        answer = num1 / num2;
                        printf("%d / %d = ", num1, num2);
                    }
                    totalQuestions++;
                    scanf("%d", &userAnswer);
                    if (answer == userAnswer) {
                        printf("Correct!\n");
                        correctAnswers++;
                    }
                    else {
                        printf("Incorrect! The correct answer is %d\n", answer);
                    }
                }
                break;

            default:
                printf("\nInvalid option! Please choose again.\n");
                break;
        }

        printf("\nYour score: %d/%d (%.2f%%)\n", correctAnswers, totalQuestions, (float)correctAnswers/totalQuestions*100);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &response);
        correctAnswers = 0;
        totalQuestions = 0;

    } while (response == 'y' || response == 'Y');

    printf("\nThank you for using the Math Exercise program!\n");
    return 0;
}