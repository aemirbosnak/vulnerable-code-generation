//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numDice, int numSides)
{
    int i;
    int sum = 0;
    for (i = 0; i < numDice; i++)
    {
        int roll = rand() % numSides + 1;
        sum += roll;
    }
    return sum;
}

int main()
{
    int numDice, numSides;
    int rollResult;
    char playAgain;

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides should each die have? ");
    scanf("%d", &numSides);

    srand(time(NULL));
    rollResult = rollDice(numDice, numSides);

    printf("You rolled %d dice with %d sides each:\n", numDice, numSides);
    printf("Result: %d\n", rollResult);

    printf("Would you like to roll again? (y/n) ");
    scanf(" %c", &playAgain);

    while (playAgain == 'y' || playAgain == 'Y')
    {
        srand(time(NULL));
        rollResult = rollDice(numDice, numSides);

        printf("You rolled %d dice with %d sides each:\n", numDice, numSides);
        printf("Result: %d\n", rollResult);

        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &playAgain);
    }

    return 0;
}