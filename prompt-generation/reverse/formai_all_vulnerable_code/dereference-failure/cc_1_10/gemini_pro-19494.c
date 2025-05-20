//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice and sides
#define NUM_DICE 2
#define NUM_SIDES 6

// Function to roll a single die
int roll_die() {
    return rand() % NUM_SIDES + 1;
}

// Function to roll multiple dice
int* roll_dice(int num_dice) {
    int* rolls = malloc(sizeof(int) * num_dice);
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = roll_die();
    }
    return rolls;
}

// Function to print the results of rolling dice
void print_dice(int* rolls, int num_dice) {
    printf("Rolled %d dice:\n", num_dice);
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

// Function to play a simple dice game
void play_dice_game() {
    // Get the number of dice to roll from the user
    int num_dice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    // Roll the dice
    int* rolls = roll_dice(num_dice);

    // Print the results
    print_dice(rolls, num_dice);

    // Calculate the sum of the rolls
    int sum = 0;
    for (int i = 0; i < num_dice; i++) {
        sum += rolls[i];
    }

    // Print the sum
    printf("The sum of the rolls is %d\n", sum);

    // Free the memory allocated for the rolls
    free(rolls);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Play the dice game
    play_dice_game();

    return 0;
}