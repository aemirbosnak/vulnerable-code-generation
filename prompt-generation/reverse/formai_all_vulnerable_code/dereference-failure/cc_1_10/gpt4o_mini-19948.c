//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Function to perform Run-Length Encoding
void runLengthEncode(char *input, char *output) {
    int length = strlen(input);
    int count;
    int outputIndex = 0;

    for (int i = 0; i < length; i++) {
        // Count occurrences of the same character
        count = 1;
        while (i < length - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Add character and its count to the output
        outputIndex += snprintf(output + outputIndex, MAX_LENGTH - outputIndex, "%c%d", input[i], count);
    }
}

// Function to perform Run-Length Decoding
void runLengthDecode(char *input, char *output) {
    int outputIndex = 0;
    char currentChar;
    int count;

    for (int i = 0; input[i] != '\0'; i++) {
        currentChar = input[i];

        // Move to get the number
        i++;
        count = 0;
        while (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        // Add the character 'count' times to the output
        for (int j = 0; j < count; j++) {
            output[outputIndex++] = currentChar;
        }
        outputIndex--; // Adjust for the loop's increment
    }
    output[outputIndex] = '\0'; // Null-terminate the output string
}

int main() {
    char input[MAX_LENGTH], compressed[MAX_LENGTH], decompressed[MAX_LENGTH];

    printf("== Welcome to the Enthusiastic RLE Compression Program! ==\n");
    printf("Please enter a string to compress: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    // Compressing the input string
    runLengthEncode(input, compressed);
    printf("\nCompressed String: %s\n", compressed);

    // Decompressing the compressed string
    runLengthDecode(compressed, decompressed);
    printf("Decompressed String: %s\n", decompressed);

    return 0;
}