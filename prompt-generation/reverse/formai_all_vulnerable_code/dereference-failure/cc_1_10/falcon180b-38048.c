//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORDS_PER_LINE 10

typedef struct {
    char *word;
    int length;
    int index;
} Word;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordsPerLine = 0;
    int lineNumber = 0;
    int totalWords = 0;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lineNumber++;
        totalWords += countWords(line, wordsPerLine);
        printf("Line %d has %d words.\n", lineNumber, wordsPerLine);
        wordsPerLine = 0;
    }

    printf("Total words: %d\n", totalWords);

    fclose(file);
    return 0;
}

int countWords(char *line, int *wordsPerLine) {
    char *wordStart = line;
    int wordLength = 0;
    int totalWords = 0;

    while (isspace(*wordStart)) {
        wordStart++;
    }

    while (*wordStart!= '\0' &&!isspace(*wordStart)) {
        wordLength++;
        if (wordLength == MAX_WORD_LENGTH) {
            printf("Error: word too long!\n");
            return -1;
        }
        if (totalWords >= MAX_WORDS_PER_LINE) {
            printf("Error: too many words per line!\n");
            return -1;
        }
        Word *newWord = (Word *) malloc(sizeof(Word));
        strncpy(newWord->word, wordStart, wordLength);
        newWord->length = wordLength;
        newWord->index = totalWords;
        totalWords++;
        wordStart += wordLength;
        if (*wordStart!= '\0') {
            *wordStart = '\0';
            wordStart++;
        }
    }

    *wordsPerLine = totalWords;
    return totalWords;
}