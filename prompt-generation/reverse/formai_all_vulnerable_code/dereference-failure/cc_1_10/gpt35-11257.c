//FormAI DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

// Function to check if a character is a punctuation mark or not
bool isPunctuation(char c) {
    if (c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?') {
        return true;
    }
    return false;
}

// Function to convert all characters in a string to lower case
void toLowerCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to remove all punctuation marks from a string
void removePunctuation(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!isPunctuation(str[i])) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

// Function to count the number of words in a string
int countWords(char *str) {
    int count = 0;
    bool counting = false;
    int i = 0;
    while (str[i]) {
        if (isspace(str[i]) || isPunctuation(str[i])) {
            counting = false;
        } else if (!counting) {
            counting = true;
            count++;
        }
        i++;
    }
    return count;
}

// Function to tokenize a string into words
void tokenize(char *str, char **tokens) {
    int count = 0;
    bool counting = false;
    int i = 0, j = 0;
    while (str[i]) {
        if (isspace(str[i]) || isPunctuation(str[i])) {
            counting = false;
            str[i] = '\0';
        } else if (!counting) {
            counting = true;
            tokens[j] = &str[i];
            j++;
        }
        i++;
    }
}

// Function to calculate the frequency of each word in a string
void calculateFrequency(char **tokens, int numTokens, char *words[], int freq[]) {
    bool found = false;
    for (int i = 0; i < numTokens; i++) {
        found = false;
        for (int j = 0; j < numTokens; j++) {
            if (strcmp(tokens[i], words[j]) == 0) {
                freq[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy(words[numTokens], tokens[i]);
            freq[numTokens]++;
            numTokens++;
        }
    }
}

// Function to print the most frequent words in a string
void printSummary(char *text) {
    char *tokens[MAX_STRING_LENGTH];
    char words[MAX_STRING_LENGTH][MAX_STRING_LENGTH];
    int freq[MAX_STRING_LENGTH] = {0};
    int numWords = 0;
    
    // Tokenize the string and calculate the frequency of each word
    toLowerCase(text);
    removePunctuation(text);
    numWords = countWords(text);
    tokenize(text, tokens);
    calculateFrequency(tokens, numWords, words, freq);

    // Determine the three most frequent words
    int max1 = 0, max2 = 0, max3 = 0;
    int index1 = 0, index2 = 0, index3 = 0;
    for (int i = 0; i < numWords; i++) {
        if (freq[i] > max1) {
            max3 = max2;
            index3 = index2;
            max2 = max1;
            index2 = index1;
            max1 = freq[i];
            index1 = i;
        } else if (freq[i] > max2) {
            max3 = max2;
            index3 = index2;
            max2 = freq[i];
            index2 = i;
        } else if (freq[i] > max3) {
            max3 = freq[i];
            index3 = i;
        }
    }
    
    // Print the summary
    printf("Summary\n");
    printf("-------\n");
    printf("%s\n", words[index1]);
    printf("%s\n", words[index2]);
    printf("%s\n", words[index3]);
}

int main() {
    char text[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(text, MAX_STRING_LENGTH, stdin);
    printSummary(text);
    return 0;
}