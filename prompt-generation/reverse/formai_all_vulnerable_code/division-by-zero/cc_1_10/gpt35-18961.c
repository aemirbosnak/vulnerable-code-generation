//FormAI DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rolls, dice, sides, i, j;
    int rollSum, rollTotal;
    char ans;

    printf("Welcome to the peaceful Dice Roller program.\n");

    do {
        rollTotal = 0; // Reset the roll total for each set of rolls
        
        printf("\nHow many dice would you like to roll? ");
        scanf("%d", &dice);

        printf("How many sides do these dice have? ");
        scanf("%d", &sides);

        printf("How many rolls would you like to make? ");
        scanf("%d", &rolls);

        printf("\nRolling %d %d-sided dice %d times...\n\n", dice, sides, rolls);

        // Set seed for random number generation
        srand(time(0));

        // Loop for each set of rolls
        for (i = 1; i <= rolls; i++) {
            printf("Roll %d: ", i);
            rollSum = 0; // Reset the roll sum for each roll

            // Loop for each dice in the set
            for (j = 1; j <= dice; j++) {
                int roll = rand() % sides + 1;
                printf("%d ", roll);
                rollSum += roll; // Add roll to the sum of rolls for this set
            }

            printf("= %d\n", rollSum); // Print the sum of rolls for this set
            rollTotal += rollSum; // Add roll sum to the total sum of rolls for all sets
        }

        // Print the total sum of all rolls
        printf("\nTotal roll sum for all sets: %d\n", rollTotal);

        // Ask the user if they want to roll again
        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &ans);
    } while (ans == 'y' || ans == 'Y');

    printf("\nThank you for using the peaceful Dice Roller program.\n");

    return 0;
}