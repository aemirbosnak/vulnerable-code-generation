//FormAI DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 1000

void checkSpelling(char *dictionaryFileName, char *inputFileName, char *outputFileName);
void loadDictionary(char *dictionaryFileName, char ***dictionary, int *size);
int binarySearch(char **dictionary, int size, char *target);
void toLowerCase(char *str);
void spellCheckLine(char **dictionary, int size, char *line, FILE *outputFile);

int main() {
    char *dictionaryFileName = "dictionary.txt";
    char *inputFileName = "input.txt";
    char *outputFileName = "output.txt";

    checkSpelling(dictionaryFileName, inputFileName, outputFileName);

    return 0;
}

void checkSpelling(char *dictionaryFileName, char *inputFileName, char *outputFileName) {
    char **dictionary;
    int dictionarySize;

    loadDictionary(dictionaryFileName, &dictionary, &dictionarySize);

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL) {
        printf("Error opening file: %s\n", inputFileName);
        exit(1);
    }

    if (outputFile == NULL) {
        printf("Error creating file: %s\n", outputFileName);
        exit(1);
    }

    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, inputFile) != NULL) {
        spellCheckLine(dictionary, dictionarySize, line, outputFile);
    }

    free(dictionary);

    fclose(inputFile);
    fclose(outputFile);

    printf("Spell checking complete. Results written to %s.\n", outputFileName);
}

void loadDictionary(char *dictionaryFileName, char ***dictionary, int *size) {
    FILE *dictionaryFile = fopen(dictionaryFileName, "r");

    if (dictionaryFile == NULL) {
        printf("Error opening file: %s\n", dictionaryFileName);
        exit(1);
    }

    // Count number of lines in dictionary
    char ch;
    int numLines = 0;

    while ((ch = fgetc(dictionaryFile)) != EOF) {
        if (ch == '\n') {
            numLines++;
        }
    }

    // Allocate memory for dictionary
    *dictionary = (char **) malloc(numLines * sizeof(char *));
    rewind(dictionaryFile);

    // Load words into dictionary
    char word[MAX_WORD_LEN];
    int i = 0;

    while (fgets(word, MAX_WORD_LEN, dictionaryFile) != NULL) {
        // Remove newline character from end of word
        int len = strlen(word);
        word[len - 1] = '\0';

        // Allocate memory for word in dictionary
        (*dictionary)[i] = (char *) malloc((len + 1) * sizeof(char));

        // Copy word into dictionary
        strcpy((*dictionary)[i], word);

        i++;
    }

    *size = numLines;

    fclose(dictionaryFile);
}

int binarySearch(char **dictionary, int size, char *target) {
    int lo = 0;
    int hi = size - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (strcmp(target, dictionary[mid]) < 0) {
            hi = mid - 1;
        } else if (strcmp(target, dictionary[mid]) > 0) {
            lo = mid + 1;
        } else {
            return 1;
        }
    }

    return 0;
}

void toLowerCase(char *str) {
    int i;

    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void spellCheckLine(char **dictionary, int size, char *line, FILE *outputFile) {
    char *wordPtr = strtok(line, " \t\n");

    while (wordPtr != NULL) {
        char word[MAX_WORD_LEN];
        strcpy(word, wordPtr);
        toLowerCase(word);

        if (word[0] == '\0') {
            // Empty word, skip
        } else if (!isalpha(word[0])) {
            // Not a word, skip
        } else if (strlen(word) > MAX_WORD_LEN) {
            // Word too long, skip
        } else if (!binarySearch(dictionary, size, word)) {
            fprintf(outputFile, "%s ", word);
        }

        wordPtr = strtok(NULL, " \t\n");
    }

    fprintf(outputFile, "\n");
}