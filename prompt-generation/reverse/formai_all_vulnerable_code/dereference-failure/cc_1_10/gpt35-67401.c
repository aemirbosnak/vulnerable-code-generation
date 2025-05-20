//FormAI DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_NUM_MISPELLED 100

char *dictionary[MAX_WORD_LEN];  // Array to hold dictionary words

// Function to read words from a text file and add them to the dictionary
void readDictionary(char *fileName) {
    FILE *fp = fopen(fileName, "r");  // Open file in read mode
    if (fp == NULL) {
        printf("Error: could not open file %s", fileName);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(fp, "%s", word) != EOF && i < MAX_WORD_LEN) {
        dictionary[i] = (char *) malloc(strlen(word) + 1);  // Allocate memory for the word
        strcpy(dictionary[i], word);
        i++;
    }

    fclose(fp);
}

// Function to check if a word is misspelled and suggest possible corrections
int spellCheck(char *word, char **corrections) {
    int numCorrections = 0;

    // Check if word is in the dictionary
    int found = 0;
    for (int i = 0; i < MAX_WORD_LEN && dictionary[i] != NULL; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            found = 1;
            break;
        }
    }

    // If word is not in the dictionary, suggest possible corrections
    if (!found) {
        // Generate possible corrections by inserting, deleting or replacing a character
        char tempWord[MAX_WORD_LEN];
        // Insertion
        for (int i = 0; i <= strlen(word); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                strcpy(tempWord, "");  // Clear tempWord
                strncat(tempWord, word, i);
                strncat(tempWord, &c, 1);
                strcat(tempWord, word+i);
                for (int j = 0; j < MAX_WORD_LEN && dictionary[j] != NULL; j++) {
                    if (strcmp(tempWord, dictionary[j]) == 0) {
                        corrections[numCorrections] = (char *) malloc(strlen(tempWord) + 1);
                        strcpy(corrections[numCorrections], tempWord);
                        numCorrections++;
                        goto nextCheck;  // Move on to next check
                    }
                }
            }
        }
        // Deletion
        for (int i = 0; i < strlen(word); i++) {
            strcpy(tempWord, "");  // Clear tempWord
            strncat(tempWord, word, i);
            strcat(tempWord, word+i+1);
            for (int j = 0; j < MAX_WORD_LEN && dictionary[j] != NULL; j++) {
                if (strcmp(tempWord, dictionary[j]) == 0) {
                    corrections[numCorrections] = (char *) malloc(strlen(tempWord) + 1);
                    strcpy(corrections[numCorrections], tempWord);
                    numCorrections++;
                    goto nextCheck;  // Move on to next check
                }
            }
        }
        // Replacement
        for (int i = 0; i < strlen(word); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                strcpy(tempWord, "");  // Clear tempWord
                strncat(tempWord, word, i);
                strncat(tempWord, &c, 1);
                strcat(tempWord, word+i+1);
                for (int j = 0; j < MAX_WORD_LEN && dictionary[j] != NULL; j++) {
                    if (strcmp(tempWord, dictionary[j]) == 0) {
                        corrections[numCorrections] = (char *) malloc(strlen(tempWord) + 1);
                        strcpy(corrections[numCorrections], tempWord);
                        numCorrections++;
                        goto nextCheck;  // Move on to next check
                    }
                }
            }
        }

        // If no possible corrections found, add word to the list of misspelled words
        corrections[numCorrections] = (char *) malloc(strlen(word) + 1);
        strcpy(corrections[numCorrections], word);
        numCorrections++;
    }

    // Move to next misspelled word
    nextCheck:

    return numCorrections;
}

int main() {
    // Read dictionary file
    readDictionary("dictionary.txt");

    // Open text file to be spell checked
    FILE *fp = fopen("text-to-check.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file text-to-check.txt");
        exit(1);
    }

    // Read file and spell check each word
    char word[MAX_WORD_LEN];
    char *corrections[MAX_NUM_MISPELLED];
    int numMisspelled = 0;
    while (fscanf(fp, "%s", word) != EOF && numMisspelled < MAX_NUM_MISPELLED) {
        if (spellCheck(word, corrections) > 0) {
            printf("Misspelled word: %s\n", word);
            for (int i = 0; i < MAX_NUM_MISPELLED && corrections[i] != NULL; i++) {
                printf("\tDid you mean: %s?\n", corrections[i]);
                free(corrections[i]);  // Free memory allocated for correction
            }
            numMisspelled++;
        }
    }

    fclose(fp);

    return 0;
}