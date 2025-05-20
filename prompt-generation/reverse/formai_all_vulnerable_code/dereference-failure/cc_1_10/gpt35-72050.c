//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define maximum length of input string
#define MAX 10000

// Function to remove special characters from string
void removeSpecialChars(char *str)
{
    // Initialize variables
    int i, j;
    char ch;

    // Loop through string and remove special characters
    for (i = 0; str[i] != '\0'; ++i) {
        ch = str[i];
        if (!(isalnum(ch) || isspace(ch))) {
            for (j = i; str[j] != '\0'; ++j) {
                str[j] = str[j+1];
            }
            --i;
        }
    }
}

// Function to convert all characters to lowercase
void toLowercase(char *str)
{
    // Initialize variables
    int i;

    // Loop through string and convert all characters to lowercase
    for (i = 0; str[i] != '\0'; ++i) {
        str[i] = tolower(str[i]);
    }
}

// Function to count occurrences of words in string
void countWords(char *str, int *count, char **words, int *numWords)
{
    // Initialize variables
    int i, j, k, l;
    char word[MAX];

    // Loop through string
    for (i = 0; str[i] != '\0'; ++i) {

        // Copy word into buffer
        for (j = i, k = 0; str[j] != '\0' && str[j] != ' '; ++j, ++k) {
            word[k] = str[j];
        }
        word[k] = '\0';

        // Check if word is already in list of words
        for (l = 0; l < *numWords; ++l) {
            if (strcmp(words[l], word) == 0) {
                ++count[l];
                break;
            }
        }

        // If word is not already in list of words, add it
        if (l == *numWords) {
            strcpy(words[*numWords], word);
            count[*numWords] = 1;
            ++*numWords;
        }

        // Set index to end of current word
        i = j;
    }
}

// Function to print most common words in string
void printMostCommonWords(char *str)
{
    // Initialize variables
    int i, j, maxCount, numWords = 0;
    int count[MAX] = {0};
    char *words[MAX];
    char tempStr[MAX];

    // Copy input string to temporary string
    strcpy(tempStr, str);

    // Remove special characters from string
    removeSpecialChars(tempStr);

    // Convert all characters to lowercase
    toLowercase(tempStr);

    // Split string into words
    for (i = 0; i < MAX; ++i) {
        words[i] = (char*)malloc(MAX*sizeof(char));
        if (!words[i]) {
            printf("Error: memory allocation failed.\n");
            exit(1);
        }
    }
    countWords(tempStr, count, words, &numWords);

    // Print most common words
    printf("The most common words are:\n");
    for (i = 0; i < 10; ++i) {
        maxCount = 0;
        for (j = 0; j < numWords; ++j) {
            if (count[j] > maxCount) {
                maxCount = count[j];
            }
        }
        for (j = 0; j < numWords; ++j) {
            if (count[j] == maxCount) {
                printf("%s (%d occurrences)\n", words[j], count[j]);
                count[j] = 0;
            }
        }
    }

    // Free memory
    for (i = 0; i < MAX; ++i) {
        free(words[i]);
    }
}

// Main function
int main()
{
    // Initialize variables
    char inputString[MAX];

    // Get input string from user
    printf("Enter text to summarize:\n");
    fgets(inputString, MAX, stdin);

    // Print most common words in input string
    printMostCommonWords(inputString);

    // Exit program
    return 0;
}