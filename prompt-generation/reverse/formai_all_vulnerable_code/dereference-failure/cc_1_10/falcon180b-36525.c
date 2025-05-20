//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    char translation[MAX_WORD_SIZE];
} WordTranslation;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_SIZE];
    char word[MAX_WORD_SIZE];
    char translation[MAX_WORD_SIZE];
    WordTranslation *wordTranslations = NULL;
    int numTranslations = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read in words and translations
    while (fgets(line, MAX_WORD_SIZE, inputFile)!= NULL) {
        sscanf(line, "%s %s", word, translation);

        // Allocate memory for new translation
        WordTranslation *newTranslation = malloc(sizeof(WordTranslation));
        if (newTranslation == NULL) {
            printf("Error allocating memory for new translation.\n");
            exit(1);
        }

        // Copy word and translation into new translation
        strcpy(newTranslation->word, word);
        strcpy(newTranslation->translation, translation);

        // Add new translation to list
        wordTranslations = realloc(wordTranslations, sizeof(WordTranslation) * ++numTranslations);
        if (wordTranslations == NULL) {
            printf("Error reallocating memory for word translations.\n");
            exit(1);
        }
        wordTranslations[numTranslations - 1] = *newTranslation;
    }

    // Close input file
    fclose(inputFile);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write translations to output file
    for (int i = 0; i < numTranslations; i++) {
        fprintf(outputFile, "%s %s\n", wordTranslations[i].word, wordTranslations[i].translation);
    }

    // Close output file
    fclose(outputFile);

    // Free memory
    for (int i = 0; i < numTranslations; i++) {
        free(wordTranslations[i].word);
        free(wordTranslations[i].translation);
    }
    free(wordTranslations);

    return 0;
}