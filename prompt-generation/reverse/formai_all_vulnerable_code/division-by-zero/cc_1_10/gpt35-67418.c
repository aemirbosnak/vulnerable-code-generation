//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, modifier, rollSum = 0;
    char enter;

    srand(time(0)); // ensure randomization

    printf("Welcome to the Cyberpunk Dice Roller!\n");

    // prompt user for number of dice and sides
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides do the dice have? ");
    scanf("%d", &numSides);

    // prompt user for modifier
    printf("Enter a modifier (positive or negative): ");
    scanf("%d", &modifier);

    // roll the dice
    printf("Rolling %d %d-sided dice...\n", numDice, numSides);
    for(int i = 1; i <= numDice; i++) {
        int roll = rand() % numSides + 1;
        printf("Die %d rolled: %d\n", i, roll);
        rollSum += roll;
    }

    // add the modifier and display result
    int total = rollSum + modifier;
    printf("Total roll: %d\n", total);

    // prompt user to roll again or exit
    printf("Press enter to roll again, or 'q' to quit.\n");
    scanf(" %c", &enter); // space before %c to consume newline char

    // loop to repeatedly roll the dice
    while(enter != 'q') {
        numDice = 0; // reset numDice for new input
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        if(numDice == 0) {
            printf("Invalid input. Must roll at least one die.\n");
            continue;
        }

        printf("How many sides do the dice have? ");
        scanf("%d", &numSides);

        printf("Enter a modifier (positive or negative): ");
        scanf("%d", &modifier);

        rollSum = 0; // reset rollSum for new roll
        printf("Rolling %d %d-sided dice...\n", numDice, numSides);
        for(int i = 1; i <= numDice; i++) {
            int roll = rand() % numSides + 1;
            printf("Die %d rolled: %d\n", i, roll);
            rollSum += roll;
        }

        total = rollSum + modifier;
        printf("Total roll: %d\n", total);

        printf("Press enter to roll again, or 'q' to quit.\n");
        scanf(" %c", &enter);
    }

    printf("Thanks for using Cyberpunk Dice Roller!\n");

    return 0;
}