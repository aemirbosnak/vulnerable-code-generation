//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THEORIES 100

// Array of conspiracy theories
char *theories[] = {
    "The moon landing was a hoax.",
    "The US government is hiding aliens at Area 51.",
    "9/11 was an inside job.",
    "The Earth is flat.",
    "Vaccines cause autism.",
    "The government is using mind control on its citizens.",
    "The Illuminati is a real organization that controls the world.",
    "The Bilderberg Group is a secret meeting of the world's elite.",
    "The New World Order is a plan to establish a one-world government.",
    "The CIA is behind the assassination of JFK."
};

// Array of random words
char *words[] = {
    "government", "secret", "aliens", "moon", "Earth", "flat", "vaccines", "autism", "mind control", "Illuminati", "Bilderberg Group", "New World Order", "CIA", "JFK", "assassination"
};

// Function to generate a random conspiracy theory
char *generate_theory() {
    // Get a random number for the theory
    int theory_index = rand() % MAX_THEORIES;

    // Get a random number for the words
    int word1_index = rand() % (sizeof(words) / sizeof(char *));
    int word2_index = rand() % (sizeof(words) / sizeof(char *));

    // Combine the theory and words to create a new theory
    char *new_theory = malloc(strlen(theories[theory_index]) + strlen(words[word1_index]) + strlen(words[word2_index]) + 1);
    sprintf(new_theory, "%s %s %s", theories[theory_index], words[word1_index], words[word2_index]);

    // Return the new theory
    return new_theory;
}

// Function to print a conspiracy theory
void print_theory(char *theory) {
    printf("%s\n", theory);
}

// Main function
int main() {
    // Generate 10 random conspiracy theories
    for (int i = 0; i < 10; i++) {
        char *theory = generate_theory();
        print_theory(theory);
        free(theory);
    }

    return 0;
}