//FormAI DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct for the compressed data
struct CompressedData {
    char *compressedString;
    int compressedLength;
};

// Function to compress a string using a custom algorithm
struct CompressedData compress(char *inputString, int inputLength) {
    struct CompressedData compressedData;

    // Allocate memory for the compressed string
    char *compressedString = (char *) malloc(sizeof(char) * (inputLength / 2 + 1));

    // Set the first character of the compressed string to the first character of the input string
    compressedString[0] = inputString[0];
    int compressedIndex = 1, count = 1;

    // Iterate through the input string, counting consecutive characters
    for (int i = 1; i < inputLength; i++) {
        if (inputString[i] == inputString[i - 1]) {
            count++;
        } else {
            // If the character changes, add the count to the compressed string and reset the count
            compressedString[compressedIndex++] = '0' + count;
            count = 1;
            compressedString[compressedIndex++] = inputString[i];
        }
    }

    // Add the final count to the compressed string
    compressedString[compressedIndex++] = '0' + count;

    // Set the length of the compressed string and return the struct
    compressedData.compressedLength = compressedIndex;
    compressedData.compressedString = compressedString;

    return compressedData;
}

int main() {
    // Get the input string from the user
    char inputString[100];
    printf("Enter the string to be compressed: ");
    scanf("%s", inputString);

    // Get the length of the input string
    int inputLength = strlen(inputString);

    // Call the compress function to get the compressed data
    struct CompressedData compressedData = compress(inputString, inputLength);

    // Print out the compressed string
    printf("Compressed string: %s\n", compressedData.compressedString);

    // Print out the original length and the compressed length
    printf("Original length: %d, Compressed length: %d\n", inputLength, compressedData.compressedLength);

    return 0;
}