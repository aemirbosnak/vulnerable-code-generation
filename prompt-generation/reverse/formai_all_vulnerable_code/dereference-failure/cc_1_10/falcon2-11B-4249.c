//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of words in the message
#define MAX_WORDS 100

// Define the size of the word array
#define MAX_WORD_SIZE 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 50

// Function to check if a word is in the dictionary
int isWordInDictionary(char *word) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strcasecmp(line, word) == 0) {
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Function to check if the message is spam
int isSpam(char *message) {
    int numSpamWords = 0;
    char *words[MAX_WORDS];
    char *word = NULL;
    char wordBuffer[MAX_WORD_SIZE];

    char *wordEnd = NULL;
    char *wordStart = strstr(message, " ");

    while (wordStart!= NULL) {
        wordEnd = strstr(wordStart, " ");
        if (wordEnd!= NULL) {
            strncpy(wordBuffer, wordStart, wordEnd - wordStart);
            wordBuffer[wordEnd - wordStart] = '\0';
            words[numSpamWords] = wordBuffer;
            numSpamWords++;
            wordStart = wordEnd + 1;
        } else {
            strncpy(wordBuffer, wordStart, strlen(wordStart));
            wordBuffer[strlen(wordStart)] = '\0';
            words[numSpamWords] = wordBuffer;
            numSpamWords++;
            wordStart = NULL;
        }
    }

    if (numSpamWords > 0) {
        for (int i = 0; i < numSpamWords; i++) {
            if (isWordInDictionary(words[i]) == 1) {
                printf("%s is a spam word\n", words[i]);
            }
        }
    }

    return numSpamWords > 0;
}

int main() {
    char message[MAX_WORD_SIZE];
    printf("Enter the message to be checked for spam: ");
    fgets(message, sizeof(message), stdin);

    if (isSpam(message) == 1) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}