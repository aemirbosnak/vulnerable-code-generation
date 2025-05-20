//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove punctuation from a string
char* removePunctuation(char* str) {
    char* result = malloc(strlen(str) + 1);
    int i = 0;
    for(int j = 0; j < strlen(str); j++) {
        if(!isspace(str[j]) &&!ispunct(str[j])) {
            result[i] = tolower(str[j]);
            i++;
        }
    }
    result[i] = '\0';
    return result;
}

// Function to calculate the frequency of each word in a string
int* calculateWordFrequency(char* str) {
    int* frequency = malloc(26 * sizeof(int));
    for(int i = 0; i < 26; i++) {
        frequency[i] = 0;
    }
    char* word = strtok(str, " ");
    while(word!= NULL) {
        char* cleanedWord = removePunctuation(word);
        if(cleanedWord!= NULL) {
            frequency[cleanedWord[0] - 'a']++;
            free(cleanedWord);
        }
        word = strtok(NULL, " ");
    }
    return frequency;
}

// Function to check if a string is spam or not
int isSpam(char* str, int* frequency) {
    double sum = 0;
    for(int i = 0; i < 26; i++) {
        sum += frequency[i];
    }
    double average = sum / 26;
    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(frequency[i] > average) {
            count++;
        }
    }
    return count > 0;
}

int main() {
    char* str = "Viagra is the best, buy now!";
    int* frequency = calculateWordFrequency(str);
    if(isSpam(str, frequency)) {
        printf("Spam detected!\n");
    } else {
        printf("Not spam.\n");
    }
    free(frequency);
    return 0;
}