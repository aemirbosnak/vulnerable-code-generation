//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, user_ans;
    char operator;
    srand(time(0));

    printf("Welcome to the Math Game!\n");

    while (1)
    {
        // Generate two random numbers and an operator
        num1 = rand() % 100;
        num2 = rand() % 100;
        switch (rand() % 4)
        {
        case 0:
            operator = '+';
            result = num1 + num2;
            break;
        case 1:
            operator = '-';
            result = num1 - num2;
            break;
        case 2:
            operator = '*';
            result = num1 * num2;
            break;
        case 3:
            operator = '/';
            result = num1 / num2;
            break;
        }

        // Display the equation and ask for user's answer
        printf("\nWhat is %d %c %d?\n", num1, operator, num2);
        scanf("%d", &user_ans);

        // Verify the answer and give feedback
        if (user_ans == result)
            printf("Congratulations! Your answer is correct!\n");
        else
            printf("Sorry, your answer is incorrect. The correct answer is %d.\n", result);

        // Ask if the user wants to play again
        printf("Play again? (Y/N)\n");
        char play_again;
        scanf(" %c", &play_again);
        if (play_again != 'Y' && play_again != 'y')
            break;
    }

    printf("Thanks for playing!\n");
    return 0;
}