//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Function to generate a random number between two numbers
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random string
char* generate_random_string(int length) {
    char* string = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        string[i] = (char) generate_random_number(97, 122);
    }

    string[length] = '\0';

    return string;
}

// Function to generate a random conspiracy theory
char* generate_conspiracy_theory() {
    // Define arrays of possible words
    char* subjects[] = {"the government", "big business", "the Illuminati", "aliens", "the New World Order"};
    char* verbs[] = {"is controlling", "is suppressing", "is hiding", "is plotting", "is manipulating"};
    char* objects[] = {"the truth", "our freedoms", "our resources", "our minds", "the future"};

    // Generate random numbers to select words from each array
    int subject_index = generate_random_number(0, 4);
    int verb_index = generate_random_number(0, 4);
    int object_index = generate_random_number(0, 4);

    // Concatenate the words into a conspiracy theory
    char* conspiracy_theory = malloc(100);
    strcpy(conspiracy_theory, subjects[subject_index]);
    strcat(conspiracy_theory, " ");
    strcat(conspiracy_theory, verbs[verb_index]);
    strcat(conspiracy_theory, " ");
    strcat(conspiracy_theory, objects[object_index]);

    return conspiracy_theory;
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random conspiracy theory
    char* conspiracy_theory = generate_conspiracy_theory();

    // Print the conspiracy theory
    printf("%s\n", conspiracy_theory);

    // Free the allocated memory
    free(conspiracy_theory);

    return 0;
}