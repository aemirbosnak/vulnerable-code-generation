//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print an error message and exit
void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Function to roll a dice and return the result
int roll_dice(int sides) {
    if (sides < 1) {
        print_error("Number of sides must be greater than 0");
    }
    return (rand() % sides) + 1;
}

// Function to display the results of the dice rolls
void display_results(int *results, int count) {
    printf("You rolled:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll %d: %d\n", i + 1, results[i]);
    }
}

// Function to print the welcome message
void print_welcome() {
    printf("Welcome to the Dice Roller Program!\n");
    printf("You can roll a dice of any number of sides.\n");
    printf("Let's start your rolling adventure!\n");
}

// Function to ask the user how many sides the dice should have
int get_number_of_sides() {
    int sides;
    printf("Enter the number of sides for the dice: ");
    if (scanf("%d", &sides) != 1) {
        print_error("Invalid input. Please enter a number.");
    }
    return sides;
}

// Function to ask the user how many times they want to roll the dice
int get_number_of_rolls() {
    int rolls;
    printf("Enter the number of times you want to roll the dice: ");
    if (scanf("%d", &rolls) != 1 || rolls < 1) {
        print_error("Invalid input. Please enter a positive number.");
    }
    return rolls;
}

// Function to initiate the dice rolling feature
void roll_dice_multiple_times(int sides, int rolls) {
    int *results = (int *)malloc(rolls * sizeof(int));
    if (results == NULL) {
        print_error("Memory allocation failed");
    }
    
    printf("Rolling the dice...\n");
    for (int i = 0; i < rolls; i++) {
        results[i] = roll_dice(sides);
    }
    
    display_results(results, rolls);
    free(results);
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    print_welcome();
    
    int sides = get_number_of_sides();
    int rolls = get_number_of_rolls();
    
    roll_dice_multiple_times(sides, rolls);
    
    printf("Thank you for using the Dice Roller Program! Goodbye!\n");
    return 0;
}