//FormAI DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 50 // Maximum word length

// Function to convert all characters of a string to lowercase
void toLowercase(char *word) {
    int i;
    for(i=0; word[i]; i++){
        word[i] = tolower(word[i]);
    }
}

// Function to remove punctuation symbols from a string
void removePunctuations(char *word) {
    int i, j;
    for(i=0; word[i]; i++) {
        while(!isalpha(word[i])){
            if(word[i] == '\0') return; // end of string
            for(j=i; word[j]; j++){
                word[j] = word[j+1];
            }
            word[j]='\0';
        }
    }
}

// Function to check if a word is spelled correctly
int isSpelledCorrectly(char *word, char *dictionary[], int numWordsInDictionary) {
    int i, cmpResult;
    for(i=0; i<numWordsInDictionary; i++) {
        cmpResult = strcmp(word, dictionary[i]);
        if(cmpResult == 0) return 1; // word is found in dictionary
        else if(cmpResult < 0) return 0; // word not found in the dictionary and can't be found after it
    }
    return 0; // word not found in dictionary
}

int main() {
    // Read dictionary of words
    FILE *dictFile;
    dictFile = fopen("dictionary.txt", "r");
    if(dictFile == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    char **dictionary = malloc(MAX_LENGTH * sizeof(char*));
    int numWordsInDictionary = 0;
    char buffer[MAX_LENGTH];
    while(fgets(buffer, MAX_LENGTH, dictFile) != NULL) {
        // Remove newline character from end of string
        buffer[strcspn(buffer, "\n")] = 0;
        // Store word in dictionary
        dictionary[numWordsInDictionary] = malloc(MAX_LENGTH * sizeof(char));
        strcpy(dictionary[numWordsInDictionary], buffer);
        numWordsInDictionary++;
    }
    fclose(dictFile);

    // Input word to check the spelling
    char inputWord[MAX_LENGTH];
    printf("Enter a word to check its spelling: ");
    scanf("%s", inputWord);
    // Convert input word to lowercase and remove any punctuation symbols
    toLowercase(inputWord);
    removePunctuations(inputWord);
    // Check if input word is spelled correctly
    if(isSpelledCorrectly(inputWord, dictionary, numWordsInDictionary)) {
        printf("Word is spelled correctly!\n");
    }
    else {
        printf("Word is misspelled!\n");
    }
    // Free memory allocated for dictionary
    int i;
    for(i=0; i<numWordsInDictionary; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    return 0;
}