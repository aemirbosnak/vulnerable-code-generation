//Falcon-180B DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, answer = 0, score = 0, lives = 3;
    char playAgain;

    srand(time(NULL));
    printf("Welcome to the Math Game!\n");
    printf("You have %d lives.\n", lives);

    do {
        num1 = rand() % 100;
        num2 = rand() % 100;
        operation = rand() % 4;

        switch (operation) {
            case 0:
                printf("What is %d + %d?\n", num1, num2);
                if (scanf("%d", &answer)!= 1 || answer!= num1 + num2) {
                    printf("Incorrect! You lose a life.\n");
                    lives--;
                } else {
                    printf("Correct! You earn 10 points.\n");
                    score += 10;
                }
                break;
            case 1:
                printf("What is %d - %d?\n", num1, num2);
                if (scanf("%d", &answer)!= 1 || answer!= num1 - num2) {
                    printf("Incorrect! You lose a life.\n");
                    lives--;
                } else {
                    printf("Correct! You earn 10 points.\n");
                    score += 10;
                }
                break;
            case 2:
                printf("What is %d * %d?\n", num1, num2);
                if (scanf("%d", &answer)!= 1 || answer!= num1 * num2) {
                    printf("Incorrect! You lose a life.\n");
                    lives--;
                } else {
                    printf("Correct! You earn 10 points.\n");
                    score += 10;
                }
                break;
            case 3:
                printf("What is %d / %d?\n", num1, num2);
                if (scanf("%d", &answer)!= 1 || answer!= num1 / num2) {
                    printf("Incorrect! You lose a life.\n");
                    lives--;
                } else {
                    printf("Correct! You earn 10 points.\n");
                    score += 10;
                }
                break;
        }

        if (lives == 0) {
            printf("Game Over! Your score is %d.\n", score);
            exit(0);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}