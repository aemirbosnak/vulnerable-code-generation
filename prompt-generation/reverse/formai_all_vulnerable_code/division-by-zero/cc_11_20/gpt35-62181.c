//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int num1, num2, operator, answer, userInput, score = 0;
    char operators[] = {'+', '-', '*', '/'};
    srand(time(NULL));

    printf("Welcome to the Math Exercise Game!\n");
    printf("You will be given a basic arithmetic problem and you have to solve it.\n");
    printf("You will have 10 seconds to answer each question.\n");
    printf("If you answer correctly, you get 10 points. If you answer incorrectly, you lose 5 points.\n");
    printf("Let's get started!\n\n");

    for (int i = 1; i <= 10; i++)
    {
        num1 = rand() % 100;
        num2 = rand() % 100;
        operator = rand() % 4;

        switch (operator)
        {
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

        time_t start_time = time(NULL);
        scanf("%d", &userInput);
        time_t end_time = time(NULL);

        if (userInput == answer && (end_time - start_time) <= 10)
        {
            score += 10;
            printf("Congratulations! You are correct!\n");
        }
        else
        {
            score -= 5;
            printf("Sorry, but the correct answer is %d.\n", answer);
        }
    }

    printf("\nYour final score is %d.\n", score);

    if (score == 100)
    {
        printf("Wow! You are a math genius!\n");
    }
    else if (score >= 70 && score <= 90)
    {
        printf("Great job! You have a good grasp of arithmetic.\n");
    }
    else if (score >= 40 && score < 70)
    {
        printf("Not bad, but you could use some more practice.\n");
    }
    else
    {
        printf("Looks like you need to work on your math skills.\n");
    }

    return 0;
}