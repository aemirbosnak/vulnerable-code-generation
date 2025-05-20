//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compressString(const char *input, char *output) {
    int length = strlen(input); // Get the length of the input string
    int count, index = 0; // Count for occurrences, index for output position

    // Traverse the input string
    for (int i = 0; i < length; i++) {
        count = 1; // Initialize count for each character

        // Count occurrences of the current character
        while (i + 1 < length && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append the count and character to the output
        index += sprintf(output + index, "%d%c", count, input[i]);
    }

    output[index] = '\0'; // Null terminate the output string
}

int main() {
    // Create a buffer for user input
    char input[256];
    char output[512]; // Ensure output is large enough

    // Welcome message
    printf("Welcome to the Magical Compression Garden!\n");
    printf("Enter a string to see it blossom in compressed form:\n");

    // Read input from user
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    if (strlen(input) == 0) {
        printf("No input provided! The garden shows its emptiness...\n");
        return 1;
    }

    // Compressing the user input
    compressString(input, output);

    // Show the results
    printf("Original String: %s\n", input);
    printf("Compressed Form: %s\n", output);

    // Farewell message
    printf("Thank you for visiting the Compression Garden. Until we meet again!\n");
    
    return 0;
}