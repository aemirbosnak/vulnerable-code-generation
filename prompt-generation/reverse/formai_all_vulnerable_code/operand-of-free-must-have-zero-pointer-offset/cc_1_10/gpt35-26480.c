//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate conspiracy theories
char* generate_conspiracy() {
    // Array of conspiracy theories
    char theories[10][100] = {
        "The moon landing was fake and filmed in a studio",
        "Area 51 has secret alien technology",
        "The government is hiding the cure for cancer",
        "Big Pharma is suppressing natural remedies",
        "The Illuminati control the world's governments",
        "9/11 was an inside job",
        "The world is flat",
        "The CIA killed John F. Kennedy",
        "The Rothschilds control global finance",
        "The Bilderberg Group are planning a New World Order"
    };

    // Generate a random number between 0 and 9
    int rand_num = rand() % 10;

    // Return a random conspiracy theory
    return theories[rand_num];
}

// Main function
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Print a happy message
    printf("Welcome to the Happy Conspiracy Theory Generator!\n");

    // Loop to generate conspiracy theories
    while (1) {
        // Ask the user to press any key to generate a conspiracy theory
        printf("\nPress any key to generate a conspiracy theory, or 'q' to quit: ");
        char c = getchar();

        // Exit the program if the user presses 'q'
        if (c == 'q') {
            printf("\nThanks for using the Happy Conspiracy Theory Generator!\n");
            break;  // Exit the loop
        }

        // Generate a conspiracy theory
        char* conspiracy = generate_conspiracy();

        // Print the conspiracy theory with some happy text
        printf("\nWow, did you know that %s? How wild is that!\n", conspiracy);

        // Free the memory allocated to the conspiracy theory
        free(conspiracy);
    }

    // Exit the program
    return 0;
}