//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

// function to remove all non-letter characters from a string
void strip_non_letters(char* str) {
    int i, j;
    for (i = 0, j = 0; str[j]; j++) {
        if (isalpha(str[j])) {
            str[i++] = tolower(str[j]);
        }
    }
    str[i] = '\0';
}

// function to sort an array of strings in lexicographical order
void sort_strings(char** strings, int numStrings) {
    int i, j;
    char* temp;

    for (i = 0; i < numStrings - 1; i++) {
        for (j = i + 1; j < numStrings; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

int main() {
    char* text = "The quick brown fox jumps over the lazy dog. The dog barks at the fox, but the fox keeps running. The end.";

    char** words = malloc(MAX_WORDS * sizeof(char*));
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = malloc(MAX_LENGTH * sizeof(char));
    }

    int wordCount = 0;

    // extract individual words from text, strip non-letter characters, and store in words array
    char* currWord = strtok(text, " .,");
    while (currWord != NULL) {
        strip_non_letters(currWord);
        if (strlen(currWord) > 0) {
            strcpy(words[wordCount++], currWord);
        }
        currWord = strtok(NULL, " .,");
    }

    // sort the words array
    sort_strings(words, wordCount);

    // print the sorted words array
    printf("Frequency analysis results:\n\n");
    printf("Word\tCount\n");
    printf("------------\n");
    int currCount = 0;
    for (int i = 0; i < wordCount; i++) {
        if (i == 0 || strcmp(words[i], words[i-1]) != 0) {
            if (currCount > 0) {
                printf("%s\t%d\n", words[i-1], currCount);
            }
            currCount = 1;
        } else {
            currCount++;
        }
    }
    printf("%s\t%d\n", words[wordCount-1], currCount);

    // free dynamically allocated memory
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}