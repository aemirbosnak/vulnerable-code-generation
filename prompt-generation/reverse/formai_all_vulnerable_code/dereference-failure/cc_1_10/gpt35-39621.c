//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Struct for storing conspiracy theories
typedef struct {
    char* theory;
    char* evidence;
} ConspiracyTheory;

// Function to generate a random conspiracy theory
ConspiracyTheory generateConspiracyTheory() {
    ConspiracyTheory theory;

    // Arrays of possible theories and evidence
    char* theories[] = {
        "The government is hiding contact with extraterrestrial life",
        "Chemtrails are being used to control the population",
        "The moon landing was faked",
        "9/11 was an inside job",
        "The Illuminati control the world's governments",
        "The Loch Ness Monster is real and being kept hidden",
        "Bigfoot is an alien experiment gone wrong"
    };
    char* evidence[] = {
        "leaked government documents",
        "anonymous sources within the government",
        "anecdotal reports from eyewitnesses",
        "scientific studies that have been suppressed by the government",
        "a series of coincidences that cannot be ignored"
    };

    // Generate a random index for each array
    int theoryIndex = rand() % (sizeof(theories) / sizeof(char*));
    int evidenceIndex = rand() % (sizeof(evidence) / sizeof(char*));

    // Copy the selected theory and evidence into the ConspiracyTheory struct
    theory.theory = malloc(strlen(theories[theoryIndex]) + 1);
    strcpy(theory.theory, theories[theoryIndex]);
    theory.evidence = malloc(strlen(evidence[evidenceIndex]) + 1);
    strcpy(theory.evidence, evidence[evidenceIndex]);

    return theory;
}

int main(int argc, char* argv[]) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Default values for program arguments
    int numTheories = 1;
    int maxWords = -1;

    // Parse program arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            // Number of theories to generate
            if (i + 1 < argc) {
                numTheories = atoi(argv[i + 1]);
            }
        } else if (strcmp(argv[i], "-w") == 0) {
            // Maximum number of words in each theory
            if (i + 1 < argc) {
                maxWords = atoi(argv[i + 1]);
            }
        }
    }

    // Generate and print the requested number of conspiracy theories
    for (int i = 0; i < numTheories; i++) {
        ConspiracyTheory theory = generateConspiracyTheory();

        // Limit the number of words if requested
        if (maxWords > 0) {
            char* token = strtok(theory.theory, " ");
            int numWords = 0;
            while (token != NULL && numWords < maxWords) {
                printf("%s ", token);
                token = strtok(NULL, " ");
                numWords++;
            }
            printf("(%s...)\n", theory.evidence);
        } else {
            printf("%s (%s)\n", theory.theory, theory.evidence);
        }

        // Free memory used by theory strings
        free(theory.theory);
        free(theory.evidence);
    }

    return 0;
}