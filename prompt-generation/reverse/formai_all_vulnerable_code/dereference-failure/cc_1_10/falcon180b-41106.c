//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 10000
#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void readLog(char *logFilePath, char logBuffer[MAX_LOG_SIZE]);
void tokenize(char *logBuffer, WordCount wordCounts[MAX_WORD_SIZE]);
void printWordCounts(WordCount wordCounts[MAX_WORD_SIZE], int numWords);

int main() {
    char logFilePath[MAX_LOG_SIZE];
    printf("Enter the path of the log file: ");
    scanf("%s", logFilePath);

    char logBuffer[MAX_LOG_SIZE];
    readLog(logFilePath, logBuffer);

    WordCount wordCounts[MAX_WORD_SIZE];
    tokenize(logBuffer, wordCounts);

    int numWords = 0;
    for (int i = 0; i < MAX_WORD_SIZE; i++) {
        if (wordCounts[i].count > 0) {
            numWords++;
        }
    }

    printf("\nWord Count Analysis:\n");
    printWordCounts(wordCounts, numWords);

    return 0;
}

void readLog(char *logFilePath, char logBuffer[MAX_LOG_SIZE]) {
    FILE *logFile = fopen(logFilePath, "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    fseek(logFile, 0, SEEK_END);
    int logFileSize = ftell(logFile);
    rewind(logFile);

    if (logFileSize >= MAX_LOG_SIZE) {
        printf("Log file is too large.\n");
        exit(1);
    }

    fread(logBuffer, 1, logFileSize, logFile);
    fclose(logFile);
}

void tokenize(char *logBuffer, WordCount wordCounts[MAX_WORD_SIZE]) {
    char *token = strtok(logBuffer, ",.?!:;\"'()[]{}<>");
    while (token!= NULL) {
        int i = 0;
        while (i < MAX_WORD_SIZE && wordCounts[i].count > 0) {
            i++;
        }

        if (i < MAX_WORD_SIZE) {
            strcpy(wordCounts[i].word, token);
            wordCounts[i].count = 1;
        } else {
            printf("Too many unique words in log file.\n");
            exit(1);
        }

        token = strtok(NULL, ",.?!:;\"'()[]{}<>");
    }
}

void printWordCounts(WordCount wordCounts[MAX_WORD_SIZE], int numWords) {
    printf("\nTotal number of words: %d\n", numWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}