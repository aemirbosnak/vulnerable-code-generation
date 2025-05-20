//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(FILE *file, WordFrequency *wordFrequencies) {
    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < strlen(token); i++) {
                if (!isalpha(token[i])) {
                    token[i] = '\0';
                    break;
                }
            }
            strcpy(wordFrequencies->word, token);
            wordFrequencies->frequency++;
            wordFrequencies++;
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void writeFile(FILE *file, WordFrequency *wordFrequencies) {
    fprintf(file, "Word\tFrequency\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            fprintf(file, "%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    WordFrequency wordFrequencies[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    readFile(inputFile, wordFrequencies);

    writeFile(outputFile, wordFrequencies);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}