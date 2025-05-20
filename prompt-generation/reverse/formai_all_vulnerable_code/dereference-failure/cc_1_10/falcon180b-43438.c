//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000

int main() {
    int num_sides, num_rolls, max_value, i, j, roll;
    char *sides_str;
    char input[100];
    char *token;
    int *sides_arr;
    int total_rolls = 0;
    double avg_roll;

    printf("Welcome to the Dice Roller!\n\n");

    // Get number of sides from user
    printf("Enter the number of sides for the dice: ");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, "\n");
    num_sides = atoi(token);

    // Check if number of sides is valid
    if (num_sides <= 0 || num_sides > MAX_SIDES) {
        printf("Invalid number of sides. Please enter a number between 1 and %d.\n", MAX_SIDES);
        return 1;
    }

    // Get number of rolls from user
    printf("Enter the number of rolls: ");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, "\n");
    num_rolls = atoi(token);

    // Check if number of rolls is valid
    if (num_rolls <= 0) {
        printf("Invalid number of rolls. Please enter a positive integer.\n");
        return 1;
    }

    // Get sides as string from user
    printf("Enter the sides of the dice separated by commas: ");
    fgets(input, sizeof(input), stdin);

    // Convert string to array of integers
    sides_str = strtok(input, ",");
    sides_arr = malloc(num_sides * sizeof(int));

    for (i = 0; i < num_sides; i++) {
        sides_arr[i] = atoi(sides_str);
        total_rolls += sides_arr[i];
        sides_str = strtok(NULL, ",");
    }

    // Roll the dice
    srand(time(NULL));

    for (i = 0; i < num_rolls; i++) {
        roll = rand() % total_rolls;
        printf("Roll %d: %d\n", i+1, sides_arr[roll]);
    }

    // Calculate average roll
    avg_roll = (double) total_rolls / num_rolls;
    printf("\nAverage roll: %.2f\n", avg_roll);

    return 0;
}