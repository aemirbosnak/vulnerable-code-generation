//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, answer, userAnswer;
    char operation;
    int correctAnswers = 0, incorrectAnswers = 0;
    int totalQuestions;

    srand(time(0)); // generates random numbers based on time

    printf("Welcome to the Math Exercise Program!\n");
    printf("Please enter the number of questions you want to answer: ");
    scanf("%d", &totalQuestions); // asks user for number of questions to answer

    for(int i=1; i<=totalQuestions; i++)
    {
        num1 = rand() % 100; // generates random number between 0 and 99
        num2 = rand() % 100;

        switch(rand() % 4) // generates a random operation
        {
            case 0:
                operation = '+';
                answer = num1 + num2;
                break;
            case 1:
                operation = '-';
                answer = num1 - num2;
                break;
            case 2:
                operation = '*';
                answer = num1 * num2;
                break;
            case 3:
                operation = '/';
                answer = num1 / num2;
                break;
        }

        printf("\nQuestion %d: %d %c %d = ", i, num1, operation, num2);
        scanf("%d", &userAnswer); // asks user for answer

        if(userAnswer == answer)
        {
            printf("Correct!\n");
            correctAnswers++;
        }
        else
        {
            printf("Incorrect! The correct answer is %d\n", answer);
            incorrectAnswers++;
        }
    }

    printf("\n\nTotal Score:\n");
    printf("Correct Answers: %d\n", correctAnswers);
    printf("Incorrect Answers: %d\n", incorrectAnswers);

    return 0;
}