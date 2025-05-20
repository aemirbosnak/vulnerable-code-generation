//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

// Function to remove non-alphanumeric characters from a string
void removeNonAlphanumeric(char* str) {
    int i = 0;
    while (*str) {
        if (isalnum(*str)) {
            str[i] = *str;
            i++;
        }
        str++;
    }
    str[i] = '\0';
}

// Function to split a string into words
void splitWords(char* str, char** words) {
    char* token = strtok(str, " ");
    int numWords = 0;
    while (token!= NULL) {
        words[numWords] = token;
        numWords++;
        token = strtok(NULL, " ");
    }
}

// Function to calculate the frequency of a word
int getFrequency(char* word, char** words, int numWords) {
    int frequency = 0;
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, words[i]) == 0) {
            frequency++;
        }
    }
    return frequency;
}

// Function to calculate the spam score of a line
int calculateSpamScore(char* line, char** words, int numWords) {
    int score = 0;
    for (int i = 0; i < numWords; i++) {
        char* word = words[i];
        int frequency = getFrequency(word, words, numWords);
        if (frequency > 1) {
            score += frequency * frequency;
        }
    }
    return score;
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];

    // Read each line from the input file
    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        // Remove non-alphanumeric characters from the line
        removeNonAlphanumeric(line);

        // Split the line into words
        splitWords(line, words);

        // Calculate the spam score of the line
        int spamScore = calculateSpamScore(line, words, strlen(line));

        // Print the line and its spam score
        printf("Line: %s\nSpam Score: %d\n\n", line, spamScore);
    }

    fclose(inputFile);
    return 0;
}