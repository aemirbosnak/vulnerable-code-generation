//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Array of conspiracy theories
char *conspiracyTheories[] = {
    "The moon landing was faked.",
    "9/11 was an inside job.",
    "The JFK assassination was a conspiracy.",
    "Aliens are among us.",
    "The government is hiding the truth about extraterrestrial life.",
    "The pharmaceutical industry is suppressing cures for cancer.",
    "The media is controlled by the elite.",
    "The world is run by a secret cabal of Satanists.",
    "The Earth is flat.",
    "We are living in a simulation."
};

// Array of random words
char *randomWords[] = {
    "artificial",
    "extraterrestrial",
    "government",
    "hidden",
    "illuminati",
    "matrix",
    "mind control",
    "new world order",
    "reptilian",
    "secret"
};

// Function to generate a random number between 0 and n-1
int randomNumber(int n) {
    return rand() % n;
}

// Function to generate a random conspiracy theory
char *generateConspiracyTheory() {
    // Choose a random conspiracy theory from the array
    char *conspiracyTheory = conspiracyTheories[randomNumber(sizeof(conspiracyTheories) / sizeof(char *))];

    // Choose a random number of random words to add to the conspiracy theory
    int numRandomWords = randomNumber(3) + 1;

    // Add the random words to the conspiracy theory
    for (int i = 0; i < numRandomWords; i++) {
        char *randomWord = randomWords[randomNumber(sizeof(randomWords) / sizeof(char *))];
        strcat(conspiracyTheory, " ");
        strcat(conspiracyTheory, randomWord);
    }

    // Return the conspiracy theory
    return conspiracyTheory;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate 10 random conspiracy theories
    for (int i = 0; i < 10; i++) {
        char *conspiracyTheory = generateConspiracyTheory();

        // Print the conspiracy theory
        printf("%s\n", conspiracyTheory);
    }

    return 0;
}