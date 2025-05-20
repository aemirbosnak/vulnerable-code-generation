//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(0));
    int num1, num2, operator, answer, user_answer, score = 0;
    float percentage;
    
    printf("Welcome to the Math Game!\n");
    
    for(int i = 0; i < 10; i++)
    {
        num1 = rand() % 100;
        num2 = rand() % 100;
        operator = rand() % 4;
        
        switch(operator)
        {
            case 0:
                answer = num1 + num2;
                printf("What is %d + %d? ", num1, num2);
                break;
            case 1:
                answer = num1 - num2;
                printf("What is %d - %d? ", num1, num2);
                break;
            case 2:
                answer = num1 * num2;
                printf("What is %d * %d? ", num1, num2);
                break;
            case 3:
                answer = num1 / num2;
                printf("What is %d / %d (rounded to the nearest integer)? ", num1, num2);
                break;
        }
        
        scanf("%d", &user_answer);
        
        if(user_answer == answer)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect!\n");
            printf("The correct answer is %d.\n", answer);
        }
    }
    
    percentage = (float)score / 10 * 100;
    
    printf("Your score is %d out of 10, which is %.2f%%.\n", score, percentage);
    
    if(percentage >= 70)
        printf("Great job!\n");
    else
        printf("You can do better!\n");
    
    return 0;
}