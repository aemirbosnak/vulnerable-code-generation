//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Alien dictionary
char alienDict[] = "ZXCVBNSDFGHJKLREWQ";

// Human dictionary
char humanDict[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to translate human to alien
char *human2alien(char *human) {
    // Allocate memory for the alien string
    char *alien = malloc(strlen(human) + 1);

    // Convert each character
    for (int i = 0; i < strlen(human); i++) {
        alien[i] = alienDict[strchr(humanDict, toupper(human[i])) - humanDict];
    }

    // Null-terminate the alien string
    alien[strlen(human)] = '\0';

    // Return the alien string
    return alien;
}

// Function to translate alien to human
char *alien2human(char *alien) {
    // Allocate memory for the human string
    char *human = malloc(strlen(alien) + 1);

    // Convert each character
    for (int i = 0; i < strlen(alien); i++) {
        human[i] = humanDict[strchr(alienDict, toupper(alien[i])) - alienDict];
    }

    // Null-terminate the human string
    human[strlen(alien)] = '\0';

    // Return the human string
    return human;
}

int main() {
    // Welcome message
    printf("👽 Welcome to the Alien Language Translator! 👽\n");

    // Input human and alien strings
    char human[101], alien[101];
    printf("Enter a human string: ");
    scanf("%s", human);
    printf("Enter an alien string: ");
    scanf("%s", alien);

    // Translate and display results
    printf("\nHuman to Alien Translation: %s\n", human2alien(human));
    printf("Alien to Human Translation: %s\n", alien2human(alien));

    // Farewell message
    printf("🛸 Thank you for using the Alien Language Translator! 🛸\n");

    return 0;
}