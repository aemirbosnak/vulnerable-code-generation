//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random conspiracy theory
char* generate_conspiracy_theory() {
    // Array of conspiracy theories
    char* theories[] = {
        "The moon landing was faked",
        "Lizard people control the government",
        "9/11 was an inside job",
        "The Illuminati is real",
        "Area 51 is hiding the existence of aliens",
        "The world is controlled by a secret cabal",
        "Coronavirus was created in a lab",
        "Tesla had invented a cosmic energy weapon before his death, but it was hidden from the public",
        "The government is using chemtrails to control the population",
        "The Earth is hollow and there's a secret civilization living inside",
        "The Titanic was sunk as part of an insurance scam",
        "The Federal Reserve is a tool used by the wealthy to control the economy",
        "The Bermuda Triangle is a portal to another dimension",
        "The government is in cahoots with Big Pharma to hide the cure for cancer",
        "Elvis Presley faked his own death",
        "The Loch Ness Monster is real and being covered up by the government"
    };

    // Length of the array of theories
    int num_theories = sizeof(theories) / sizeof(char*);

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random index within the range of the array
    int index = rand() % num_theories;

    // Allocate memory for the conspiracy theory string
    char* theory = (char*) malloc(strlen(theories[index]) + 1);

    // Copy the conspiracy theory string into the allocated memory
    strcpy(theory, theories[index]);

    return theory;
}

int main() {
    // Generate a random conspiracy theory
    char* theory = generate_conspiracy_theory();

    // Print the conspiracy theory
    printf("Conspiracy Theory: %s\n", theory);

    // Free the memory allocated for the conspiracy theory string
    free(theory);

    return 0;
}