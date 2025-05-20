//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random number between min and max
int random_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random conspiracy theory
char *generate_conspiracy_theory() {

    // Seed the random number generator
    srand(time(NULL));

    // Lists of possible words and phrases for each category
    char *subjects[] = {"aliens", "government", "celebrities", "vaccines", "moon landing"};
    char *actions[] = {"are controlling", "are spying on", "are hiding", "are faking", "are manipulating"};
    char *reasons[] = {"for profit", "to control the population", "to suppress the truth", "for their own amusement", "to test our limits"};
    char *evidence[] = {"secret documents", "eyewitness accounts", "unexplained phenomena", "strange coincidences", "suspicious patterns"};

    // Generate a random subject, action, reason, and evidence
    int subject_index = random_range(0, sizeof(subjects) / sizeof(char *) - 1);
    int action_index = random_range(0, sizeof(actions) / sizeof(char *) - 1);
    int reason_index = random_range(0, sizeof(reasons) / sizeof(char *) - 1);
    int evidence_index = random_range(0, sizeof(evidence) / sizeof(char *) - 1);

    // Concatenate the words and phrases into a conspiracy theory
    char *theory = malloc(256 * sizeof(char));
    strcpy(theory, subjects[subject_index]);
    strcat(theory, " ");
    strcat(theory, actions[action_index]);
    strcat(theory, " ");
    strcat(theory, reasons[reason_index]);
    strcat(theory, " ");
    strcat(theory, evidence[evidence_index]);

    // Return the conspiracy theory
    return theory;
}

// Main function
int main() {

    // Generate a random conspiracy theory
    char *theory = generate_conspiracy_theory();

    // Print the conspiracy theory to the console
    printf("The truth is out there: %s\n", theory);

    // Free the memory allocated for the conspiracy theory
    free(theory);

    return 0;
}