//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function to compare two strings (case insensitive)
int compareStrings(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2)
        return 1;

    for (int i = 0; i < len1; i++) {
        if (tolower(str1[i])!= tolower(str2[i]))
            return 1;
    }

    return 0;
}

// Function to split a string into words
void splitString(char *input, char **words) {
    char *token = strtok(input, ",.!?;:");
    int wordCount = 0;

    while (token!= NULL) {
        if (wordCount >= MAX_WORDS) {
            printf("Error: Too many words in input.\n");
            exit(1);
        }

        strcpy(words[wordCount], token);
        wordCount++;

        token = strtok(NULL, ",.!?;:");
    }
}

// Function to count word frequencies
void countWordFrequencies(char **words, int numWords, WordFrequency *frequencies) {
    for (int i = 0; i < numWords; i++) {
        int found = 0;

        for (int j = 0; j < i; j++) {
            if (compareStrings(words[i], words[j]) == 0) {
                frequencies[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(frequencies[numWords].word, words[i]);
            frequencies[numWords].count = 1;
            numWords++;
        }
    }
}

// Function to print word frequencies
void printWordFrequencies(WordFrequency *frequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char input[MAX_WORD_LENGTH * 1000]; // Maximum input size: 1MB
    fgets(input, sizeof(input), inputFile);
    fclose(inputFile);

    char *words[MAX_WORDS];
    WordFrequency frequencies[MAX_WORDS];

    splitString(input, words);
    countWordFrequencies(words, strlen(input), frequencies);
    printWordFrequencies(frequencies, strlen(input));

    return 0;
}