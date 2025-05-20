//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the maximum length of the compressed output
#define MAX_COMPRESSED_LENGTH 1000

// Declare the maximum length of the input to be compressed
#define MAX_INPUT_LENGTH 10000

// Declare the structure to hold the repeated sequences
typedef struct RepeatSequence {
    int startIndex;
    int length;
} RepeatSequence;

// Function to compress the input string and return the compressed output
char* compressString(char* inputString) {
    // Declare an array of RepeatSequence structs to hold the repeated sequences
    RepeatSequence repeatedSequences[MAX_INPUT_LENGTH] = {0};

    // Declare a variable to hold the number of repeated sequences found
    int numRepeatedSequences = 0;

    // Declare a variable to hold the length of the input string
    int inputStringLength = strlen(inputString);

    // Declare a variable to hold the index for the compressed output string
    int compressedIndex = 0;

    // Declare a variable to hold the index for the input string
    int inputIndex = 0;

    // Declare a character array to hold the compressed output string
    char* compressedString = malloc(MAX_COMPRESSED_LENGTH * sizeof(char));

    // Loop through the input string and identify repeated sequences of characters
    while (inputIndex < inputStringLength) {
        // Declare a variable to hold the current character being examined
        char currentCharacter = inputString[inputIndex];

        // Declare a variable to hold the length of the current repeated sequence
        int currentSequenceLength = 0;

        // Loop through the rest of the input string to identify repeated sequences of characters
        for (int i = inputIndex + 1; i < inputStringLength; i++) {
            if (inputString[i] == currentCharacter) {
                currentSequenceLength++;
            } else {
                break;
            }
        }

        // If a repeated sequence was found, add it to the array of repeated sequences
        if (currentSequenceLength > 0) {
            repeatedSequences[numRepeatedSequences].startIndex = inputIndex;
            repeatedSequences[numRepeatedSequences].length = currentSequenceLength + 1;
            numRepeatedSequences++;

            // Increment the input index by the length of the repeated sequence
            inputIndex += currentSequenceLength + 1;
        } else {
            // If no repeated sequence was found, simply add the character to the compressed output string
            compressedString[compressedIndex] = currentCharacter;
            compressedIndex++;
            inputIndex++;
        }
    }

    // Loop through the array of repeated sequences and replace them with their compressed versions
    for (int i = 0; i < numRepeatedSequences; i++) {
        // Declare a variable to hold the index of the repeated sequence in the input string
        int startIndex = repeatedSequences[i].startIndex;

        // Declare a variable to hold the length of the repeated sequence
        int sequenceLength = repeatedSequences[i].length;

        // Declare a variable to hold the compressed version of the repeated sequence
        char compressedSequence[5];

        // If the length of the repeated sequence is greater than 3, compress it
        if (sequenceLength > 3) {
            // Convert the length of the repeated sequence to a string
            sprintf(compressedSequence, "%d", sequenceLength);

            // Add the length of the repeated sequence to the compressed output string
            for (int j = 0; j < strlen(compressedSequence); j++) {
                compressedString[compressedIndex] = compressedSequence[j];
                compressedIndex++;
            }
        }

        // Add the repeated sequence to the compressed output string
        compressedString[compressedIndex] = inputString[startIndex];
        compressedIndex++;

        // Update the input index to skip over the repeated sequence
        inputIndex = startIndex + sequenceLength;
    }

    // Add a null terminator to the end of the compressed output string
    compressedString[compressedIndex] = '\0';

    // Return the compressed output string
    return compressedString;
}

int main() {
    // Declare a test string to be compressed
    char inputString[] = "aaabbbbccccddde";

    // Compress the test string
    char* compressedString = compressString(inputString);

    // Print out the compressed string
    printf("Compressed string: %s\n", compressedString);

    // Free up memory for the compressed string
    free(compressedString);

    return 0;
}