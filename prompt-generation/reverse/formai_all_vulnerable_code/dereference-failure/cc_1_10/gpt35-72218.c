//FormAI DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50

void processWords(FILE *inputFile, FILE *outputFile);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Please provide input and output file names as arguments.\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Failed to open input file %s\n", argv[1]);
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Failed to open output file %s\n", argv[2]);
        return 1;
    }

    processWords(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

void processWords(FILE *inputFile, FILE *outputFile) {
    char word[MAX_WORD_LENGTH];
    bool inWord = false;
    int c;
    int wordLength = 0;

    while ((c = fgetc(inputFile)) != EOF) {
        if (isalnum(c)) {
            if (!inWord) {
                inWord = true;
                wordLength = 0;
            }
            if (wordLength < MAX_WORD_LENGTH - 1) {
                word[wordLength++] = (char) c;
            }
        } else {
            if (inWord) {
                inWord = false;
                word[wordLength] = '\0';
                fprintf(outputFile, "word: %s\n", word);
            }
        }
    }

    if (inWord) {
        inWord = false;
        word[wordLength] = '\0';
        fprintf(outputFile, "word: %s\n", word);
    }
}