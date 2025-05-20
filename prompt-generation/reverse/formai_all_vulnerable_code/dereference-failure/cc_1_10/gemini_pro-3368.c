//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to create a heart-shaped string
char *createHeart(int size) {
    // Allocate memory for the string
    char *heart = malloc(sizeof(char) * size * size);

    // Set the initial character to a space
    heart[0] = ' ';

    // Iterate over the rows of the heart
    for (int i = 1; i < size; i++) {
        // Iterate over the columns of the heart
        for (int j = 0; j < size; j++) {
            // Calculate the distance from the center of the heart
            int distance = abs(i - size / 2) + abs(j - size / 2);

            // If the distance is less than or equal to half the size of the heart, set the character to an asterisk
            if (distance <= size / 2) {
                heart[i * size + j] = '*';
            } else {
                // Otherwise, set the character to a space
                heart[i * size + j] = ' ';
            }
        }
    }

    // Set the null terminator at the end of the string
    heart[size * size] = '\0';

    // Return the heart string
    return heart;
}

// Function to print a string centered on the screen
void printCentered(char *string) {
    // Get the length of the string
    int length = strlen(string);

    // Calculate the number of spaces to print before the string
    int padding = (80 - length) / 2;

    // Print the spaces before the string
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }

    // Print the string
    printf("%s", string);

    // Print the spaces after the string
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }

    // Print a newline character
    printf("\n");
}

int main() {
    // Create a heart-shaped string
    char *heart = createHeart(20);

    // Print the heart string centered on the screen
    printCentered(heart);

    // Free the memory allocated for the heart string
    free(heart);

    return 0;
}