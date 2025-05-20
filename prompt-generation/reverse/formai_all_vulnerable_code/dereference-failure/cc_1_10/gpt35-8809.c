//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

//A helper function to compare two strings
int compareStrings(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    printf("Welcome to the Sherlock Holmes Word Frequency Counter\n\n");
    printf("Please enter the filename you would like to analyze: ");
  
    char filename[50];
    scanf("%s", filename);
  
    FILE* inputFile = fopen(filename, "r");
  
    if (inputFile == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
  
    printf("\nAnalyzing file...\n");
  
    char currentWord[MAX_WORD_LEN];
  
    char** words = (char**)malloc(MAX_WORDS * sizeof(char*));
    int* frequencies = (int*)malloc(MAX_WORDS * sizeof(int));
  
    int numWords = 0;
    int i, j;
  
    while (fscanf(inputFile, "%s", currentWord) != EOF) {
        for (i = 0; currentWord[i] != '\0'; i++) {
            if (ispunct(currentWord[i])) {
                currentWord[i] = '\0'; //replace punctuation with null character
                break;
            }
            currentWord[i] = tolower(currentWord[i]);
        }
    
        //check if word is already in array and increment frequency if so
        for (j = 0; j < numWords; j++) {
            if (strcmp(words[j], currentWord) == 0) {
                frequencies[j]++;
                break;
            }
        }
    
        //if word is not already in array, add it and set frequency to 1
        if (j == numWords) {
            words[numWords] = (char*)malloc(strlen(currentWord) + 1);
            strcpy(words[numWords], currentWord);
            frequencies[numWords] = 1;
            numWords++;
        }
    }
  
    printf("\nAnalysis complete. Here are the results:\n\n");

    //sort the words alphabetically using quicksort
    qsort(words, numWords, sizeof(char*), compareStrings);
  
    //print out the words and their corresponding frequencies
    for (i = 0; i < numWords; i++) {
        printf("%-15s %d\n", words[i], frequencies[i]);
    }
  
    //free up memory
    for (i = 0; i < numWords; i++) {
        free(words[i]);
    }
  
    free(words);
    free(frequencies);
  
    fclose(inputFile);
  
    return 0;
}