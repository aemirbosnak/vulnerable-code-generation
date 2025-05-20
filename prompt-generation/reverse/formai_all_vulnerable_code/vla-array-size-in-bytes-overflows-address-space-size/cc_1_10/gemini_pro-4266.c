//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for each die
#define D4_SIDES 4
#define D6_SIDES 6
#define D8_SIDES 8
#define D10_SIDES 10
#define D12_SIDES 12
#define D20_SIDES 20

// Define the dice rolling function
int roll_die(int sides) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and the number of sides
    int roll = rand() % sides + 1;

    // Return the roll
    return roll;
}

// Define the main function
int main() {
    // Get the number of dice to roll from the user
    int num_dice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    // Get the type of dice to roll from the user
    int die_type;
    printf("What type of dice do you want to roll? (4, 6, 8, 10, 12, or 20) ");
    scanf("%d", &die_type);

    // Roll the dice and print the results
    int rolls[num_dice];
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = roll_die(die_type);
        printf("Die %d: %d\n", i + 1, rolls[i]);
    }

    // Calculate the total roll
    int total_roll = 0;
    for (int i = 0; i < num_dice; i++) {
        total_roll += rolls[i];
    }

    // Print the total roll
    printf("Total roll: %d\n", total_roll);

    return 0;
}