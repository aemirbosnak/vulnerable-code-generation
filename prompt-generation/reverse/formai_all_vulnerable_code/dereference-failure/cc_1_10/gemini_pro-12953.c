//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to decode alien language
char *decode(char *str) {
    int i, j, k;
    int len = strlen(str);

    // Create a 2D array to store the decoded characters
    char decoded[len][len];

    // Iterate over the rows of the array
    for (i = 0; i < len; i++) {
        // Iterate over the columns of the array
        for (j = 0; j < len; j++) {
            // Get the character at the current index
            char c = str[i * len + j];

            // Get the index of the character in the alphabet
            int index = c - 'a';

            // Decode the character
            char decodedChar = 'a' + (index + len - i - 1) % len;

            // Store the decoded character in the array
            decoded[i][j] = decodedChar;
        }
    }

    // Create a new string to store the decoded message
    char *result = malloc(len + 1);

    // Iterate over the rows of the array
    for (i = 0; i < len; i++) {
        // Iterate over the columns of the array
        for (j = 0; j < len; j++) {
            // Get the decoded character at the current index
            char c = decoded[i][j];

            // Append the decoded character to the result string
            result[i * len + j] = c;
        }
    }

    // Add a null terminator to the result string
    result[len] = '\0';

    // Return the result string
    return result;
}

// Main function
int main() {
    // Get the input string
    char *str = "hello";

    // Decode the input string
    char *decodedStr = decode(str);

    // Print the decoded string
    printf("%s", decodedStr);

    // Free the allocated memory
    free(decodedStr);

    return 0;
}