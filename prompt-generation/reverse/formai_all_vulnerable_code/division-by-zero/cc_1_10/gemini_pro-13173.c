//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare variables
    int dice1, dice2, total;

    // Get the user's input
    printf("Welcome to the Dice Roller Extravaganza!\n");
    printf("How many sides do the dice have? ");
    int sides;
    scanf("%d", &sides);

    // Roll the dice
    dice1 = rand() % sides + 1;
    dice2 = rand() % sides + 1;

    // Calculate the total
    total = dice1 + dice2;

    // Display the results
    printf("You rolled a %d and a %d, for a total of %d!\n", dice1, dice2, total);

    // Check for a winning roll
    if (total == 7 || total == 11) {
        printf("Congratulations! You win!\n");
    } else if (total == 2 || total == 3 || total == 12) {
        printf("Sorry, you lose!\n");
    } else {
        printf("The point is %d. Roll again!\n", total);
    }

    // Ask the user if they want to roll again
    char again;
    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &again);

    // Roll again if the user wants to
    if (again == 'y') {
        main();
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}