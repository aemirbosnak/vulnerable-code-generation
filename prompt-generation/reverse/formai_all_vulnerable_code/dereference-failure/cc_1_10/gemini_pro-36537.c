//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// List of funny conspiracy theories
char *theories[] = {
    "The moon is made of cheese.",
    "Aliens built the pyramids.",
    "Elvis is still alive and living on Mars.",
    "The government is controlled by a secret society of lizard people.",
    "The Earth is flat.",
    "The Illuminati is a real thing and they're plotting to take over the world.",
    "Chemtrails are being used to control the population.",
    "The Holocaust never happened.",
    "9/11 was an inside job.",
    "The CIA is behind the assassination of JFK.",
};

// List of funny reasons
char *reasons[] = {
    "Because it's delicious.",
    "Because they needed a place to store their pharaohs.",
    "Because he faked his death to avoid paying his taxes.",
    "Because they're the only ones smart enough to rule us.",
    "Because it's the only way to explain the curvature of the horizon.",
    "Because they want to enslave us all.",
    "Because they're trying to poison us.",
    "Because it's a hoax.",
    "Because the government is hiding the truth.",
    "Because the CIA is a bunch of evil bastards.",
};

// Function to generate a random conspiracy theory
char *random_conspiracy_theory() {
    // Get a random theory and reason
    char *theory = theories[rand() % (sizeof(theories) / sizeof(char *))];
    char *reason = reasons[rand() % (sizeof(reasons) / sizeof(char *))];

    // Concatenate the theory and reason into a single string
    char *conspiracy_theory = malloc(strlen(theory) + strlen(reason) + 3);
    strcpy(conspiracy_theory, theory);
    strcat(conspiracy_theory, " because ");
    strcat(conspiracy_theory, reason);

    // Return the conspiracy theory
    return conspiracy_theory;
}

// Main function
int main() {
    // Generate a random conspiracy theory
    char *conspiracy_theory = random_conspiracy_theory();

    // Print the conspiracy theory to the console
    printf("%s\n", conspiracy_theory);

    // Free the memory allocated for the conspiracy theory
    free(conspiracy_theory);

    return 0;
}