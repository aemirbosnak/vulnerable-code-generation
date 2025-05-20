//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die
int roll_die(int num_sides) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and num_sides
    int roll = rand() % num_sides + 1;

    return roll;
}

// Function to print the results of a die roll
void print_results(int num_rolls, int num_sides) {
    // Initialize an array to store the results of the rolls
    int results[num_rolls];

    // Roll the die num_rolls times
    for (int i = 0; i < num_rolls; i++) {
        results[i] = roll_die(num_sides);
    }

    // Print the results of the rolls
    printf("The results of the %d rolls are:\n", num_rolls);
    for (int i = 0; i < num_rolls; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

// Function to print the histogram of the results of a die roll
void print_histogram(int num_rolls, int num_sides) {
    // Initialize an array to store the frequency of each outcome
    int histogram[num_sides];
    for (int i = 0; i < num_sides; i++) {
        histogram[i] = 0;
    }

    // Roll the die num_rolls times and increment the frequency of each outcome
    for (int i = 0; i < num_rolls; i++) {
        int roll = roll_die(num_sides);
        histogram[roll - 1]++;
    }

    // Print the histogram
    printf("Histogram of the results:\n");
    for (int i = 0; i < num_sides; i++) {
        printf("%d: %d\n", i + 1, histogram[i]);
    }
}

// Function to get the user's input
void get_input(int *num_rolls, int *num_sides) {
    // Prompt the user for the number of rolls
    printf("Enter the number of rolls: ");
    scanf("%d", num_rolls);

    // Prompt the user for the number of sides on the die
    printf("Enter the number of sides on the die: ");
    scanf("%d", num_sides);
}

int main() {
    // Get the user's input
    int num_rolls, num_sides;
    get_input(&num_rolls, &num_sides);

    // Print the results of the die roll
    print_results(num_rolls, num_sides);

    // Print the histogram of the results of the die roll
    print_histogram(num_rolls, num_sides);

    return 0;
}