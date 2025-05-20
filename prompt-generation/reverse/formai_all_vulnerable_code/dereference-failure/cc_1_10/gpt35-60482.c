//FormAI DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

void processFile(FILE* inputFile, FILE* outputFile);

int main(int argc, char** argv) {
    // Check for required arguments
    if (argc != 3) {
        printf("Usage: %s inputFile outputFile\n", argv[0]);
        return -1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    FILE* outputFile = fopen(argv[2], "w");

    if (inputFile == NULL) {
        printf("Unable to open input file.\n");
        return -1;
    }

    if (outputFile == NULL) {
        printf("Unable to open output file.\n");
        return -1;
    }

    processFile(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

void processFile(FILE* inputFile, FILE* outputFile) {
    char word[MAX_WORD_LENGTH];

    while (fscanf(inputFile, "%s", word) != EOF) {
        int wordLength = strlen(word);

        // Check if the word ends with a dot
        if (word[wordLength - 1] == '.') {
            // Remove the dot from the word
            word[wordLength - 1] = '\0';
            wordLength--;
        }

        // Check if the word is longer than 3 characters
        if (wordLength > 3) {
            // Capitalize the first letter of the word
            word[0] = toupper(word[0]);

            // Write the processed word to the output file
            fprintf(outputFile, "%s ", word);
        }
    }
}