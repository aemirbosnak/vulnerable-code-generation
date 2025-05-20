//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1000000 // Maximum size of the log file
#define MAX_WORD_LENGTH 50 // Maximum length of a word
#define MAX_NUM_WORDS 1000 // Maximum number of words to analyze
#define MIN_WORD_LENGTH 3 // Minimum length of a word
#define MAX_NUM_ANALYSIS_WORDS 100 // Maximum number of analysis words

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int numWords;
} WordFrequencyList;

void readLogFile(FILE *logFile, char *logContent) {
    fseek(logFile, 0, SEEK_END);
    int fileSize = ftell(logFile);
    rewind(logFile);

    if (fileSize > MAX_LOG_SIZE) {
        printf("Error: Log file is too large.\n");
        exit(1);
    }

    logContent = (char *) malloc((fileSize + 1) * sizeof(char));
    fread(logContent, fileSize, 1, logFile);
    logContent[fileSize] = '\0';
}

void analyzeWords(char *logContent, WordFrequencyList *wordFrequencyList) {
    char *word = strtok(logContent, " ");
    while (word!= NULL) {
        if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
            WordFrequency *foundWord = NULL;
            for (int i = 0; i < wordFrequencyList->numWords; i++) {
                if (strcmp(wordFrequencyList->words[i].word, word) == 0) {
                    foundWord = &wordFrequencyList->words[i];
                    break;
                }
            }

            if (foundWord == NULL) {
                if (wordFrequencyList->numWords >= MAX_NUM_ANALYSIS_WORDS) {
                    printf("Warning: Maximum number of analysis words reached.\n");
                    break;
                }

                foundWord = &wordFrequencyList->words[wordFrequencyList->numWords];
                strcpy(foundWord->word, word);
                foundWord->frequency = 1;
                wordFrequencyList->numWords++;
            } else {
                foundWord->frequency++;
            }
        }

        word = strtok(NULL, " ");
    }
}

void printWordFrequencies(WordFrequencyList *wordFrequencyList) {
    printf("Word frequencies:\n");
    for (int i = 0; i < wordFrequencyList->numWords; i++) {
        printf("%s: %d\n", wordFrequencyList->words[i].word, wordFrequencyList->words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Error: Incorrect number of arguments.\n");
        return 1;
    }

    FILE *logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    char *logContent = NULL;
    readLogFile(logFile, logContent);
    fclose(logFile);

    WordFrequencyList wordFrequencyList = {NULL, 0};
    analyzeWords(logContent, &wordFrequencyList);

    printWordFrequencies(&wordFrequencyList);

    for (int i = 0; i < wordFrequencyList.numWords; i++) {
        free(wordFrequencyList.words[i].word);
    }
    free(wordFrequencyList.words);

    free(logContent);

    return 0;
}