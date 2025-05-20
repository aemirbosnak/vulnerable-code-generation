//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    char line[1000];
    int numWords = 0, i;
    WordCount words[MAX_WORDS];

    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            numWords++;
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                strcpy(words[numWords-1].word, token);
                words[numWords-1].count = 1;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}