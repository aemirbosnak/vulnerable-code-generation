//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToLowercase(char* string) {
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + ('a' - 'A');
        }
    }
}

int main() {
    printf("Welcome to the C Word Frequency Counter program!");

    char* inputString = (char*) malloc(sizeof(char) * 1000);
    printf("\n\nPlease enter the text to count the frequency of each word: ");
    fgets(inputString, 1000, stdin);

    convertToLowercase(inputString);

    char* currentWord = (char*) malloc(sizeof(char) * 100);
    int currentIndexInWord = 0;
    int currentIndexInString = 0;
    int frequency[1000];
    int count = 0;

    for(int i = 0; i < strlen(inputString); i++) {
        if(inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\t'){
            currentWord[currentIndexInWord] = '\0';
            currentIndexInWord = 0;
            frequency[count] = 1;
            count++;

            for(int j = i + 1; j < strlen(inputString); j++) {
                if(strncmp(currentWord, &inputString[j], strlen(currentWord)) == 0) {
                    frequency[count-1]++;
                }
            }
        } else {
            currentWord[currentIndexInWord] = inputString[i];
            currentIndexInWord++;
        }
    }

    printf("\nWord\t\tFrequency");
    for(int i = 0; i < count; i++) {
        if(frequency[i] != 0) {
            printf("\n%-10s\t\t%d", currentWord[i], frequency[i]);
        }
    }

    free(inputString);
    free(currentWord);
    return 0;
}