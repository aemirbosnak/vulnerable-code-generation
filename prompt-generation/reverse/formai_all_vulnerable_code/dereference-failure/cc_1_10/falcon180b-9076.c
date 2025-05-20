//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_NUM_LINES 1000000
#define MAX_NUM_WORDS 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    char line[MAX_LINE_LENGTH];
    int numWords;
    WordCount *words;
} LineInfo;

void initLineInfo(LineInfo *lineInfo) {
    lineInfo->numWords = 0;
    lineInfo->words = (WordCount *)malloc(MAX_NUM_WORDS * sizeof(WordCount));
}

void addWord(LineInfo *lineInfo, char *word) {
    int i;
    for (i = 0; i < lineInfo->numWords; i++) {
        if (strcmp(lineInfo->words[i].word, word) == 0) {
            lineInfo->words[i].count++;
            return;
        }
    }
    if (lineInfo->numWords >= MAX_NUM_WORDS) {
        printf("Error: Maximum number of words exceeded\n");
        exit(1);
    }
    strcpy(lineInfo->words[lineInfo->numWords].word, word);
    lineInfo->words[lineInfo->numWords].count = 1;
    lineInfo->numWords++;
}

void printLineInfo(LineInfo *lineInfo) {
    int i;
    printf("Line: %s\n", lineInfo->line);
    printf("Number of words: %d\n", lineInfo->numWords);
    for (i = 0; i < lineInfo->numWords; i++) {
        printf("Word %d: %s (%d)\n", i, lineInfo->words[i].word, lineInfo->words[i].count);
    }
}

void freeLineInfo(LineInfo *lineInfo) {
    free(lineInfo->words);
}

void processLine(char *line, int lineNum, LineInfo *lineInfo) {
    char *word;
    char *start = line;
    int numWords = 0;
    while ((word = strtok(start, " \t\n\r\f\v"))!= NULL) {
        addWord(lineInfo, word);
        numWords++;
        start = NULL;
    }
    if (numWords == 0) {
        printf("Error: Empty line %d\n", lineNum);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int lineNum = 0;
    LineInfo lineInfo;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        exit(1);
    }

    initLineInfo(&lineInfo);

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        lineNum++;
        processLine(line, lineNum, &lineInfo);
    }

    fclose(fp);
    printf("Line statistics:\n");
    printLineInfo(&lineInfo);
    freeLineInfo(&lineInfo);

    return 0;
}