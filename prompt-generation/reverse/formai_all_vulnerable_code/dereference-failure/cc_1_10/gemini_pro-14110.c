//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
struct AlienDictionary {
    char alienChar;
    char earthChar;
};

// Create an array of AlienDictionary structs to store the dictionary
struct AlienDictionary dictionary[] = {
    {'a', 'z'},
    {'b', 'y'},
    {'c', 'x'},
    {'d', 'w'},
    {'e', 'v'},
    {'f', 'u'},
    {'g', 't'},
    {'h', 's'},
    {'i', 'r'},
    {'j', 'q'},
    {'k', 'p'},
    {'l', 'o'},
    {'m', 'n'},
};

// Get the size of the dictionary
int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

// Function to translate an Alien language string to Earth language
char *translateAlienToEarth(char *alienString) {
    // Allocate memory for the translated string
    char *earthString = malloc(strlen(alienString) + 1);

    // Loop through each character in the Alien language string
    for (int i = 0; i < strlen(alienString); i++) {
        // Find the corresponding Earth language character in the dictionary
        for (int j = 0; j < dictionarySize; j++) {
            if (alienString[i] == dictionary[j].alienChar) {
                earthString[i] = dictionary[j].earthChar;
                break;
            }
        }
    }

    // Null-terminate the translated string
    earthString[strlen(alienString)] = '\0';

    // Return the translated string
    return earthString;
}

// Function to translate an Earth language string to Alien language
char *translateEarthToAlien(char *earthString) {
    // Allocate memory for the translated string
    char *alienString = malloc(strlen(earthString) + 1);

    // Loop through each character in the Earth language string
    for (int i = 0; i < strlen(earthString); i++) {
        // Find the corresponding Alien language character in the dictionary
        for (int j = 0; j < dictionarySize; j++) {
            if (earthString[i] == dictionary[j].earthChar) {
                alienString[i] = dictionary[j].alienChar;
                break;
            }
        }
    }

    // Null-terminate the translated string
    alienString[strlen(earthString)] = '\0';

    // Return the translated string
    return alienString;
}

// Main function
int main() {
    // Get the Alien language string from the user
    char alienString[100];
    printf("Enter an Alien language string: ");
    scanf("%s", alienString);

    // Translate the Alien language string to Earth language
    char *earthString = translateAlienToEarth(alienString);

    // Print the translated Earth language string
    printf("Earth language string: %s\n", earthString);

    // Translate the Earth language string back to Alien language
    char *alienString2 = translateEarthToAlien(earthString);

    // Print the translated Alien language string
    printf("Alien language string: %s\n", alienString2);

    // Free the allocated memory
    free(earthString);
    free(alienString2);

    return 0;
}