//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: You must provide exactly two arguments. Example usage:\n");
        printf("./wordcount \"input.txt\" \"output.txt\"\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (inputFile == NULL) {
        printf("Error: Could not open file %s for reading.\n", argv[1]);
        return 1;
    }

    if (outputFile == NULL) {
        printf("Error: Could not open file %s for writing.\n", argv[2]);
        return 1;
    }

    int wordCount = 0;
    int charCount = 0;
    int longestWordLength = 0;
    int currentWordLength = 0;
    char currentChar;
    char longestWord[100];

    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (isalpha(currentChar)) {
            currentWordLength += 1;
        } else {
            if (currentWordLength > 0) {
                wordCount += 1;
                charCount += currentWordLength;
                if (currentWordLength > longestWordLength) {
                    longestWordLength = currentWordLength;
                    fseek(inputFile, -currentWordLength, SEEK_CUR);
                    fread(longestWord, sizeof(char), longestWordLength, inputFile);
                }
            }
            currentWordLength = 0;
        }
    }

    if (currentWordLength > 0) {
        wordCount += 1;
        charCount += currentWordLength;
        if (currentWordLength > longestWordLength) {
            longestWordLength = currentWordLength;
            fseek(inputFile, -currentWordLength, SEEK_CUR);
            fread(longestWord, sizeof(char), longestWordLength, inputFile);
        }
    }

    fprintf(outputFile, "The input file contains %d words and %d characters.\n", wordCount, charCount);
    fprintf(outputFile, "The longest word in the input file is \"%s\" with %d letters.\n", longestWord, longestWordLength);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}