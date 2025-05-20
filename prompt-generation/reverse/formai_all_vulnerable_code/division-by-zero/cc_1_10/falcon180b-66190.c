//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000 // Maximum number of sides on the die
#define MAX_DICE 1000 // Maximum number of dice to roll

int main() {
    int num_dice, num_sides, i, j, total = 0;
    int dice[MAX_DICE]; // Array to store the values of each die
    char again;

    srand(time(NULL)); // Seed the random number generator with the current time

    // Get the number of dice and sides from the user
    printf("How many dice do you want to roll? (1-1000): ");
    scanf("%d", &num_dice);
    printf("How many sides do you want on each die? (1-1000): ");
    scanf("%d", &num_sides);

    // Roll the dice and calculate the total
    for (i = 0; i < num_dice; i++) {
        dice[i] = rand() % num_sides + 1; // Roll the die and store the value in the array
        total += dice[i]; // Add the value to the total
    }

    // Print the results
    printf("\nYou rolled %d dice with %d sides each:\n", num_dice, num_sides);
    for (i = 0; i < num_dice; i++) {
        printf("%d ", dice[i]); // Print each die value
    }
    printf("\nThe total is: %d\n", total);

    // Ask the user if they want to roll again
    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &again);

    while (again == 'y' || again == 'Y') {
        // Roll the dice again and calculate the total
        for (i = 0; i < num_dice; i++) {
            dice[i] = rand() % num_sides + 1; // Roll the die and store the value in the array
            total += dice[i]; // Add the value to the total
        }

        // Print the results
        printf("\nYou rolled %d dice with %d sides each:\n", num_dice, num_sides);
        for (i = 0; i < num_dice; i++) {
            printf("%d ", dice[i]); // Print each die value
        }
        printf("\nThe total is: %d\n", total);

        // Ask the user if they want to roll again
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &again);
    }

    return 0;
}