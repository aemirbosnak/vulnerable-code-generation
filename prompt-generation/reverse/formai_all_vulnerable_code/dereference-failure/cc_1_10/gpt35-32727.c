//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 100

// This function converts all characters to lowercase
void toLower(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

// This function removes unwanted characters from a string
void formatWord(char *str) {
    int i, j;
    for (i = 0, j = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// This function checks if a word is already in the list or not
int isPresent(char **words, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Could not open file %s", fileName);
        return 1;
    }

    char **words = malloc(sizeof(char *));
    int *counts = malloc(sizeof(int));
    int size = 0;

    char word[MAX_WORD_SIZE];
    while (fscanf(file, "%s", word) == 1) {
        formatWord(word);   // Remove unwanted characters from word
        toLower(word);      // Convert all characters to lowercase

        // Check if word is already in the list, if yes then increase its count else add it to the list
        int index = isPresent(words, size, word);
        if (index >= 0) {
            counts[index]++;
        } else {
            size++;
            words = realloc(words, size * sizeof(char *));
            counts = realloc(counts, size * sizeof(int));
            words[size-1] = malloc(strlen(word) + 1);
            strcpy(words[size-1], word);
            counts[size-1] = 1;
        }
    }

    // Sort the words array in descending order of word count
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (counts[j] < counts[j+1]) {
                int temp = counts[j];
                counts[j] = counts[j+1];
                counts[j+1] = temp;

                char *temp2 = words[j];
                words[j] = words[j+1];
                words[j+1] = temp2;
            }
        }
    }

    // Print the frequency of each word in the file
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < size; i++) {
        printf("%-15s%d\n", words[i], counts[i]);
    }

    // Free memory allocated to words array
    for (int i = 0; i < size; i++) {
        free(words[i]);
    }
    free(words);
    free(counts);

    fclose(file);
    return 0;
}