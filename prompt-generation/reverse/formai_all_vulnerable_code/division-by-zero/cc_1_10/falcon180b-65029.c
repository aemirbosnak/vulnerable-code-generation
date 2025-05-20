//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 100

// Struct to hold dice information
typedef struct {
    int num_sides;
    int num_dice;
} Dice;

// Function to roll the dice
void roll_dice(Dice dice, int *results) {
    int i, j;
    srand(time(NULL)); // Seed the random number generator with the current time

    // Roll each die and store the result in the results array
    for (i = 0; i < dice.num_dice; i++) {
        results[i] = rand() % dice.num_sides + 1; // Add 1 to include the top side of the die
    }
}

// Function to print the results of the dice roll
void print_results(int num_dice, int *results) {
    int i;
    for (i = 0; i < num_dice; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

int main() {
    int num_dice, num_sides;
    Dice dice;
    int results[MAX_DICE];

    // Get user input for number of dice and sides per die
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter number of sides per die: ");
    scanf("%d", &num_sides);

    // Set up the dice struct
    dice.num_sides = num_sides;
    dice.num_dice = num_dice;

    // Roll the dice
    roll_dice(dice, results);

    // Print the results
    printf("Rolled %d %d-sided dice:\n", num_dice, num_sides);
    print_results(num_dice, results);

    return 0;
}