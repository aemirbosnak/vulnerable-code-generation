//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll dice
void roll_dice(int num_dice, int num_sides) {
    int i, result;

    // Roll dice and print results
    for (i = 0; i < num_dice; i++) {
        result = rand_num(1, num_sides);
        printf("Roll %d: %d\n", i+1, result);
    }
}

int main() {
    int num_dice, num_sides;
    char play_again;

    // Seed random number generator with current time
    srand(time(NULL));

    // Get user input for number of dice and number of sides
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter number of sides: ");
    scanf("%d", &num_sides);

    // Roll dice
    roll_dice(num_dice, num_sides);

    // Ask user if they want to play again
    printf("Do you want to roll the dice again? (y/n): ");
    scanf(" %c", &play_again);

    // Loop until user decides to quit
    while (play_again == 'y' || play_again == 'Y') {
        // Roll dice again
        roll_dice(num_dice, num_sides);

        // Ask user if they want to play again
        printf("Do you want to roll the dice again? (y/n): ");
        scanf(" %c", &play_again);
    }

    return 0;
}