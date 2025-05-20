//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the data structure for each element
typedef struct {
    char *name;
    char *symbol;
    int atomic_number;
    double atomic_mass;
    char *group;
    char *period;
    char *block;
    char *electron_configuration;
} Element;

// Define the array of elements
Element elements[NUM_ELEMENTS];

// Function to initialize the array of elements
void init_elements() {
    // Open the file containing the element data
    FILE *file = fopen("elements.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the element data from the file
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the element data from the line
        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        int atomic_number = atoi(strtok(NULL, ","));
        double atomic_mass = atof(strtok(NULL, ","));
        char *group = strtok(NULL, ",");
        char *period = strtok(NULL, ",");
        char *block = strtok(NULL, ",");
        char *electron_configuration = strtok(NULL, ",");

        // Store the element data in the array of elements
        Element element = {name, symbol, atomic_number, atomic_mass, group, period, block, electron_configuration};
        elements[atomic_number - 1] = element;
    }

    // Close the file
    fclose(file);
}

// Function to print the periodic table
void print_periodic_table() {
    // Print the header of the periodic table
    printf("   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  | 11  | 12  | 13  | 14  | 15  | 16  | 17  | 18  |\n");
    printf("---+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");

    // Print the body of the periodic table
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        // Print the row number
        printf("%2d |", i + 1);

        // Print the element name, symbol, and atomic number
        printf(" %s (%s) %2d |", elements[i].name, elements[i].symbol, elements[i].atomic_number);
    }

    // Print the footer of the periodic table
    printf("\n---+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
}

// Function to play the periodic table quiz
void play_periodic_table_quiz() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get a random element from the periodic table
    int random_element = rand() % NUM_ELEMENTS;

    // Ask the user to guess the element
    printf("Guess the element with atomic number %d: ", elements[random_element].atomic_number);
    char guess[1024];
    scanf("%s", guess);

    // Check if the user's guess is correct
    if (strcmp(guess, elements[random_element].name) == 0) {
        printf("Congratulations! You guessed correctly.\n");
    } else {
        printf("Sorry, that's not correct. The correct answer is %s.\n", elements[random_element].name);
    }
}

// Main function
int main() {
    // Initialize the array of elements
    init_elements();

    // Print the periodic table
    print_periodic_table();

    // Play the periodic table quiz
    play_periodic_table_quiz();

    return 0;
}