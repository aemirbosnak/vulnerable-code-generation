//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 1;

    // Iterate through the input string
    while (input[i]) {
        // If the current character is the same as the previous one
        if (input[i] == input[i - 1]) {
            // Increment the count
            count++;
        } else {
            // Write the count and the character to the output string
            output[j++] = count;
            output[j++] = input[i];
            count = 1;
        }
        i++;
    }

    // Write the last count and character to the output string
    output[j++] = count;
    output[j++] = input[i - 1];
    output[j++] = '\0';
}

// Function to decompress the input string
void decompress(char* input, char* output) {
    int i = 0, j = 0;

    // Iterate through the input string
    while (input[i]) {
        // If the first character is not a count
        if (input[i]!= '\0') {
            // Write the character to the output string
            output[j++] = input[i++];
        } else {
            // Write the count and the character to the output string
            int count = input[i++];
            while (count--) {
                output[j++] = input[i++];
            }
        }
    }

    output[j] = '\0';
}

int main() {
    char input[1000], output[2000];

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, input);

    // Print the decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}