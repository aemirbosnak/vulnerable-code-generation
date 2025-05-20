//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_SIZE 1000000 // Maximum number of lines in log file
#define MAX_WORD_SIZE 100 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void readLogFile(const char* filename, WordCount* wordCounts, int maxWords);
void printWordCounts(WordCount* wordCounts, int numWords);

int main() {
    char logFileName[100];
    printf("Enter the name of the log file: ");
    scanf("%s", logFileName);

    FILE* logFile = fopen(logFileName, "r");
    if (logFile == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    WordCount wordCounts[100];
    int numWords = 0;

    readLogFile(logFileName, wordCounts, 100);
    printf("\nWord Counts:\n");
    printWordCounts(wordCounts, numWords);

    fclose(logFile);
    return 0;
}

void readLogFile(const char* filename, WordCount* wordCounts, int maxWords) {
    FILE* logFile = fopen(filename, "r");
    if (logFile == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    char line[MAX_LOG_SIZE];
    int lineNum = 0;
    while (fgets(line, MAX_LOG_SIZE, logFile)!= NULL) {
        int wordCount = 0;
        char* word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int len = strlen(word);
            if (len > MAX_WORD_SIZE) {
                len = MAX_WORD_SIZE;
            }
            strncpy(wordCounts[wordCount].word, word, len);
            wordCounts[wordCount].word[len] = '\0';
            wordCounts[wordCount].count++;
            wordCount++;
            word = strtok(NULL, ",.?!;:");
        }
        lineNum++;
        if (lineNum >= maxWords) {
            break;
        }
    }

    fclose(logFile);
}

void printWordCounts(WordCount* wordCounts, int numWords) {
    printf("Total words: %d\n", numWords);
    printf("Word\t\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }
}