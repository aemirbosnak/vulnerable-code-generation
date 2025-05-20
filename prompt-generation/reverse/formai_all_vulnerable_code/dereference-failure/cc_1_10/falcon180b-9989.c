//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice, num_sides, num_rolls;
    int *dice_rolls;
    double mean, variance, std_dev;
    int i, j, k;

    // Ask user for number of dice, number of sides, and number of rolls
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter number of sides: ");
    scanf("%d", &num_sides);
    printf("Enter number of rolls: ");
    scanf("%d", &num_rolls);

    // Allocate memory for dice rolls
    dice_rolls = (int *) malloc(num_dice * num_rolls * sizeof(int));

    // Roll the dice
    srand(time(NULL));
    for (i = 0; i < num_dice * num_rolls; i++) {
        dice_rolls[i] = rand() % num_sides + 1;
    }

    // Calculate mean, variance, and standard deviation
    mean = 0.0;
    for (i = 0; i < num_dice * num_rolls; i++) {
        mean += dice_rolls[i];
    }
    mean /= num_dice * num_rolls;

    variance = 0.0;
    for (i = 0; i < num_dice * num_rolls; i++) {
        variance += (dice_rolls[i] - mean) * (dice_rolls[i] - mean);
    }
    variance /= num_dice * num_rolls;

    std_dev = sqrt(variance);

    // Print results
    printf("Number of dice: %d\n", num_dice);
    printf("Number of sides: %d\n", num_sides);
    printf("Number of rolls: %d\n", num_rolls);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard deviation: %.2f\n", std_dev);

    // Free memory
    free(dice_rolls);

    return 0;
}