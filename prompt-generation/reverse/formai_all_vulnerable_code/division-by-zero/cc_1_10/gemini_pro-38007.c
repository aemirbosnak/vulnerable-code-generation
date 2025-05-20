//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the number of sides for the dice
#define NUM_SIDES 6

// Define the maximum number of dice to roll
#define MAX_DICE 10

// Define the maximum number of rolls to perform
#define MAX_ROLLS 1000

// Function to generate a random number between 1 and the number of sides
int roll_die(int num_sides) {
    return rand() % num_sides + 1;
}

// Function to roll a number of dice and return the sum of the results
int roll_dice(int num_dice, int num_sides) {
    int sum = 0;
    for (int i = 0; i < num_dice; i++) {
        sum += roll_die(num_sides);
    }
    return sum;
}

// Function to simulate rolling a number of dice a number of times and print the results
void simulate_dice_rolls(int num_dice, int num_sides, int num_rolls) {
    int results[num_rolls];
    for (int i = 0; i < num_rolls; i++) {
        results[i] = roll_dice(num_dice, num_sides);
    }

    // Print the results
    printf("Results of rolling %d %d-sided dice %d times:\n", num_dice, num_sides, num_rolls);
    for (int i = 0; i < num_rolls; i++) {
        printf("%d\n", results[i]);
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of dice to roll from the user
    int num_dice;
    printf("Enter the number of dice to roll (1-%d): ", MAX_DICE);
    scanf("%d", &num_dice);

    // Get the number of sides for the dice from the user
    int num_sides;
    printf("Enter the number of sides for the dice (1-%d): ", NUM_SIDES);
    scanf("%d", &num_sides);

    // Get the number of rolls to perform from the user
    int num_rolls;
    printf("Enter the number of rolls to perform (1-%d): ", MAX_ROLLS);
    scanf("%d", &num_rolls);

    // Simulate rolling the dice and print the results
    simulate_dice_rolls(num_dice, num_sides, num_rolls);

    return 0;
}