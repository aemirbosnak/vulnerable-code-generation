//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int a, b, choice, answer, user_answer, right = 0, wrong = 0;
    double timer = 0.0, score;

    printf("Welcome to the Math Exercise Program\n");
    printf("Let's get started!\n\n");

    srand(time(NULL));

    for(int i = 1; i <= 10; i++)
    {
        a = rand() % 10;
        b = rand() % 10;

        choice = rand() % 4;

        switch(choice)
        {
            case 0:
                answer = a + b;
                printf("%d. What is %d + %d? ", i, a, b);
                break;
            case 1:
                answer = a - b;
                printf("%d. What is %d - %d? ", i, a, b);
                break;
            case 2:
                answer = a * b;
                printf("%d. What is %d * %d? ", i, a, b);
                break;
            case 3:
                answer = a / b;
                printf("%d. What is %d / %d? ", i, a, b);
                break;
        }

        time_t start_time = time(NULL);
        scanf("%d", &user_answer);
        time_t end_time = time(NULL);

        timer += difftime(end_time, start_time);

        if(user_answer == answer)
        {
            right++;
            printf("That's correct! Your current score is %d/%d\n\n", right, i);
        }
        else
        {
            wrong++;
            printf("Sorry, the correct answer is %d. Your current score is %d/%d\n\n", answer, right, i);
        }
    }

    score = right / 10.0;

    printf("Congratulations on finishing the Math Exercise Program!\n");
    printf("You got %d questions right and %d questions wrong in %.1lf seconds.\n", right, wrong, timer);
    printf("Your score is %.2lf/10.00\n", score);

    if(score < 5.0)
    {
        printf("Better luck next time!\n");
    }
    else if(score < 8.0)
    {
        printf("Great job! Keep practicing to improve your score!\n");
    }
    else
    {
        printf("Excellent work! You are a Math whiz!\n");
    }

    return 0;
}