//FormAI DATASET v1.0 Category: Spell checking ; Style: detailed
//C Spell Checking Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

int main() {
    //initialize variables
    FILE *inputFile, *outputFile, *dictionaryFile;
    char inputFilename[MAX_WORD_LENGTH], outputFilename[MAX_WORD_LENGTH], dictionary[MAX_WORDS][MAX_WORD_LENGTH];
    int i = 0, numWords = 0;
    char* word;
    char line[MAX_WORDS];
    int lineLength;
    int j = 0, k = 0;
    char currentWord[MAX_WORD_LENGTH];
    char checkWord[MAX_WORD_LENGTH];

    //get names of input and output file from user
    printf("Enter the name of the input file: ");
    scanf("%s", inputFilename);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFilename);

    //open input and output file and dictionary
    inputFile = fopen(inputFilename, "r");
    outputFile = fopen(outputFilename, "w");
    dictionaryFile = fopen(DICTIONARY_FILE, "r");

    //copy dictionary file contents to array
    while (fgets(line, MAX_WORDS, dictionaryFile)) {
        lineLength = strlen(line);
        if (line[lineLength - 1] == '\n')
            line[lineLength - 1] = '\0';
        strcpy(dictionary[i], line);
        i++;
    }
    numWords = i;
    //close dictionary
    fclose(dictionaryFile);

    //process each word in input file for spelling errors
    while (fscanf(inputFile, "%s", currentWord) != EOF) {
        //strip punctuation from the word
        for (i = 0, j = 0; i < strlen(currentWord); i++) {
            if (isalpha(currentWord[i])) {
                currentWord[j] = tolower(currentWord[i]);
                j++;
            }
        }
        currentWord[j] = '\0';

        //compare word with dictionary content
        for (i = 0; i < numWords; i++) {
            strcpy(checkWord, dictionary[i]);
            if (strcmp(currentWord, checkWord) == 0) {
                break;
            }
        }
        //if word is not present in dictionary, write to output file
        if (i == numWords) {
            fprintf(outputFile, "%s\n", currentWord);
        }
    }

    //close input and output file
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}