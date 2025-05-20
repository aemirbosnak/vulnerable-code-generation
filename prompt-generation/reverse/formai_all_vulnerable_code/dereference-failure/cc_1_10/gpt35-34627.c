//FormAI DATASET v1.0 Category: Compression algorithms ; Style: happy
// Hello there! I'm so happy to show you this interesting C Compression Algorithm!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function takes a string and returns its compressed version.
char *compress(char *input) {
    int len = strlen(input);  // Get length of the input string.
    char *output = malloc(sizeof(char) * len); // Allocate memory for the output string.

    int count = 1, j = 0;
    char curr_char = input[0];

    // Loop through each character in the input string.
    for (int i = 1; i <= len; i++) {
        if (input[i] == curr_char) {
            count++;
        } else {
            // Append the current character with its count to the output string.
            output[j++] = curr_char;
            output[j++] = count + '0';  // Convert count to ASCII character.

            // Set the current character and count to the new values.
            curr_char = input[i];
            count = 1;
        }
    }

    // Append null character to the end of the output string.
    output[j] = '\0';

    // If the compressed string is longer than the original string, return the original string.
    if (strlen(output) > len) {
        return input;
    } else {
        return output;
    }
}

int main() {
    printf("Welcome to the C Compression Algorithm program!\n\n");

    char input[101];
    printf("Please enter a string to compress (max 100 characters): ");
    fgets(input, 101, stdin);

    // Remove newline character from the input string.
    input[strcspn(input, "\n")] = '\0';

    printf("Compressed string: %s\n", compress(input));

    return 0;
}