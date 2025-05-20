//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int roll_die(int sides) {
    // Initialize random seed
    srand(time(NULL));

    // Generate a random number between 1 and the number of sides
    int roll = rand() % sides + 1;

    return roll;
}

// Function to roll multiple dice
int *roll_dice(int num_dice, int sides) {
    // Allocate memory for the array of dice rolls
    int *rolls = malloc(sizeof(int) * num_dice);

    // Roll each die and store the result in the array
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = roll_die(sides);
    }

    return rolls;
}

// Function to print the results of a dice roll
void print_rolls(int *rolls, int num_dice) {
    // Print the rolls
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }

    // Print a newline
    printf("\n");
}

// Function to get the sum of a dice roll
int get_sum(int *rolls, int num_dice) {
    // Initialize sum to 0
    int sum = 0;

    // Add each roll to the sum
    for (int i = 0; i < num_dice; i++) {
        sum += rolls[i];
    }

    return sum;
}

// Main function
int main() {
    // Get the number of dice to roll from the user
    int num_dice;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    // Get the number of sides on the dice from the user
    int sides;
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);

    // Roll the dice
    int *rolls = roll_dice(num_dice, sides);

    // Print the results of the dice roll
    printf("You rolled: ");
    print_rolls(rolls, num_dice);

    // Get the sum of the dice roll
    int sum = get_sum(rolls, num_dice);

    // Print the sum of the dice roll
    printf("The sum of the dice roll is: %d\n", sum);

    // Free the memory allocated for the array of dice rolls
    free(rolls);

    return 0;
}