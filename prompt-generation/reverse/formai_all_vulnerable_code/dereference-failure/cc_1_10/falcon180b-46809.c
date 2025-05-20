//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 10000
#define MAX_WORD_SIZE 50
#define MAX_LINE_SIZE 500

typedef struct {
    int count;
    char word[MAX_WORD_SIZE];
} WordCount;

typedef struct {
    char word[MAX_WORD_SIZE];
    int lineNumber;
    int count;
} WordLineCount;

int main() {

    FILE *logFile;
    char logLine[MAX_LINE_SIZE];
    char *word;
    char *delimiters = " \t\n\r\f\v";
    WordCount *wordCounts = (WordCount*) malloc(MAX_LOG_SIZE * sizeof(WordCount));
    int numWords = 0;
    int numLines = 0;
    int i, j;

    logFile = fopen("logfile.txt", "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(logLine, MAX_LINE_SIZE, logFile)!= NULL) {
        numLines++;

        // Tokenize the line into words
        word = strtok(logLine, delimiters);
        while (word!= NULL) {
            numWords++;

            // Convert word to lowercase and remove trailing whitespace
            i = strlen(word) - 1;
            while (isspace(word[i])) {
                word[i] = '\0';
                i--;
            }

            for (j = 0; j < MAX_WORD_SIZE - 1; j++) {
                if (wordCounts[numWords - 1].word[j] == '\0') {
                    strncat(wordCounts[numWords - 1].word, word, j < strlen(word)? j : strlen(word));
                    break;
                }
            }

            if (j == MAX_WORD_SIZE - 1) {
                printf("Error: Word is too long.\n");
                exit(1);
            }

            wordCounts[numWords - 1].count++;

            word = strtok(NULL, delimiters);
        }
    }

    fprintf(stdout, "Number of lines: %d\n", numLines);
    fprintf(stdout, "Number of words: %d\n", numWords);

    printf("\nWord\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(logFile);

    return 0;
}