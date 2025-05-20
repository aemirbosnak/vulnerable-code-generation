//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// List of potential conspiracy theories
const char *theories[] = {
    "The moon landing was faked.",
    "The Earth is flat.",
    "The government is controlled by aliens.",
    "The Illuminati is a real organization.",
    "Vaccines cause autism.",
    "9/11 was an inside job.",
    "The world is going to end in 2012.",
    "The CIA killed JFK.",
    "Elvis is still alive.",
    "Bigfoot is real.",
    "The Loch Ness Monster is real."
};

// List of potential witnesses
const char *witnesses[] = {
    "Anonymous sources",
    "Government whistleblowers",
    "Scientists",
    "Historians",
    "Religious leaders",
    "Celebrities",
    "Ordinary people",
    "You",
    "Your friends",
    "Your family",
    "Your pets"
};

// List of potential evidence
const char *evidence[] = {
    "Secret documents",
    "Eyewitness testimony",
    "Physical evidence",
    "Circumstantial evidence",
    "Logic",
    "Gut feeling",
    "Dreams",
    "Coincidences",
    "Hoaxes",
    "Misinterpretations",
    "Lies"
};

// Generate a random conspiracy theory
char *generate_conspiracy_theory() {
    // Get a random number generator
    srand(time(NULL));

    // Get a random theory
    char *theory = theories[rand() % (sizeof(theories) / sizeof(char *))];

    // Get a random witness
    char *witness = witnesses[rand() % (sizeof(witnesses) / sizeof(char *))];

    // Get a random piece of evidence
    char *evidence = evidence[rand() % (sizeof(evidence) / sizeof(char *))];

    // Format the conspiracy theory
    char *conspiracy_theory = malloc(strlen(theory) + strlen(witness) + strlen(evidence) + 20);
    sprintf(conspiracy_theory, "I was shocked when I found out that %s, %s. The proof? %s.", theory, witness, evidence);

    // Return the conspiracy theory
    return conspiracy_theory;
}

// Print a random conspiracy theory
void print_conspiracy_theory() {
    // Generate a random conspiracy theory
    char *conspiracy_theory = generate_conspiracy_theory();

    // Print the conspiracy theory
    printf("%s\n", conspiracy_theory);

    // Free the memory allocated for the conspiracy theory
    free(conspiracy_theory);
}

// Main function
int main() {
    // Print a random conspiracy theory
    print_conspiracy_theory();

    // Return 0
    return 0;
}