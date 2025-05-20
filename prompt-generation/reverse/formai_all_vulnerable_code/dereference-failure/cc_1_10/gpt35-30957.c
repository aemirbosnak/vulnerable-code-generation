//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50 // Maximum length of a word
#define MAX_NUM_WORDS 1000 // Maximum number of words in a file

// Function to convert a word to lowercase
void toLowerCase(char *word) {
    int i;
    for(i=0; word[i]; i++){
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word is spelled correctly
int spellCheck(char *word, char **dictionary, int numWords) {
    int i;
    for(i=0; i<numWords; i++){
        if(strcmp(word, dictionary[i]) == 0){
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    char *dictionary[MAX_NUM_WORDS];
    char word[MAX_WORD_LEN];
    char fileName[50];
    int i, numWords = 0;

    // Read dictionary
    printf("Enter the name of the dictionary file: ");
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Unable to open file!\n");
        return 1;
    }
    while(fscanf(fp, "%s", word) != EOF){
        toLowerCase(word);
        dictionary[numWords] = malloc(strlen(word)+1);
        strcpy(dictionary[numWords], word);
        numWords++;
    }
    fclose(fp);

    // Read input file and check for spelling errors
    printf("Enter the name of the input file: ");
    scanf("%s", fileName);
    fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Unable to open file!\n");
        return 1;
    }
    while(fscanf(fp, "%s", word) != EOF){
        toLowerCase(word);
        if(!spellCheck(word, dictionary, numWords)){
            printf("Spelling error: %s\n", word);
        }
    }
    fclose(fp);

    // Free memory
    for(i=0; i<numWords; i++){
        free(dictionary[i]);
    }

    return 0;
}