//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CONSPIRACIES 10
#define MAX_CONSPIRACY_LEN 100

// An array of conspiracy theories
const char *conspiracies[NUM_CONSPIRACIES] = {
    "The moon landing was faked.",
    "Elvis Presley is still alive.",
    "The government is hiding the truth about aliens.",
    "The Bilderberg Group controls the world.",
    "The Illuminati is a real organization.",
    "The Loch Ness Monster is real.",
    "Crop circles are made by aliens.",
    "The Bermuda Triangle is a place of mystery.",
    "The Titanic was sunk by a German U-boat.",
    "The JFK assassination was a conspiracy."
};

// A function to generate a random conspiracy theory
char *generate_conspiracy() {
    // Get a random number between 0 and NUM_CONSPIRACIES - 1
    int random_index = rand() % NUM_CONSPIRACIES;

    // Return the conspiracy theory at the random index
    return strdup(conspiracies[random_index]);
}

// A function to print a conspiracy theory
void print_conspiracy(char *conspiracy) {
    // Print the conspiracy theory
    printf("**Conspiracy Theory:** %s\n", conspiracy);

    // Free the memory allocated for the conspiracy theory
    free(conspiracy);
}

// The main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random conspiracy theory
    char *conspiracy = generate_conspiracy();

    // Print the conspiracy theory
    print_conspiracy(conspiracy);

    return 0;
}