//FormAI DATASET v1.0 Category: Word Count Tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100 // Maximum length of a word
#define MAX_NUM_WORDS 1000 // Maximum number of unique words to store

int wordCount(char *filename, char **words, int *counts);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    char **words = (char **) malloc(sizeof(char *) * MAX_NUM_WORDS);
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        words[i] = (char *) malloc(sizeof(char) * MAX_WORD_LENGTH);
    }

    int *counts = (int *) calloc(MAX_NUM_WORDS, sizeof(int));

    int numWords = wordCount(filename, words, counts);

    printf("%d unique words found in %s:\n", numWords, filename);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        free(words[i]);
    }
    free(words);
    free(counts);

    return 0;
}

// Read the file and count the frequency of each unique word
int wordCount(char *filename, char **words, int *counts) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int numWords = 0;
    char temp[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", temp) == 1) {
        // Convert the word to lower case
        for (int i = 0; i < strlen(temp); i++) {
            temp[i] = tolower(temp[i]);
        }

        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i], temp) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        // If the word is not already in the array, add it
        if (!found) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: too many words in file\n");
                exit(1);
            }
            strcpy(words[numWords], temp);
            counts[numWords] = 1;
            numWords++;
        }
    }

    fclose(fp);
    return numWords;
}