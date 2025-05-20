//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    char c;
    char currentWord[MAX_WORD_LENGTH + 1];
    int wordCount = 0;

    int i, j;
    int lettersInWord = 0;
    int numWords = 0;

    FILE* inputFile;
    inputFile = fopen("input.txt", "r"); // Replace with desired input file name

    if (inputFile == NULL) {
        printf("Error: input file cannot be opened.\n");
        return 1;
    }

    int* frequencyTable = (int*)malloc(26 * sizeof(int));

    for (i = 0; i < 26; i++) {
        frequencyTable[i] = 0;
    }

    while ((c = fgetc(inputFile)) != EOF) {
        if (isalpha(c)) {
            currentWord[lettersInWord++] = tolower(c);
        } else {
            if (lettersInWord > 0) {
                currentWord[lettersInWord] = '\0';
                numWords++;
                frequencyTable[currentWord[0] - 'a']++;

                lettersInWord = 0;
            }
        }
    }

    if (lettersInWord > 0) {
        currentWord[lettersInWord] = '\0';
        numWords++;
        frequencyTable[currentWord[0] - 'a']++;
    }

    int totalWords = 0;

    printf("Word\t       Frequency\n");
    printf("----------------------------\n");

    for (i = 0; i < 26; i++) {
        if (frequencyTable[i] > 0) {
            totalWords += frequencyTable[i];
            printf("%c\t       %d\n", 'A' + i, frequencyTable[i]);
        }
    }

    printf("\nTotal:\t       %d\n", totalWords);

    fclose(inputFile);

    return 0;
}