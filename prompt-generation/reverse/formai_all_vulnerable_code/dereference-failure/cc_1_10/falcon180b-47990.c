//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char *line = NULL;
    size_t len = 0;
    int numWords = 0;
    struct WordCount wordCounts[MAX_WORDS];

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while ((getline(&line, &len, inputFile))!= -1) {
        char *wordStart = line;
        char *wordEnd = wordStart;
        while (isspace(*wordEnd)) {
            wordEnd++;
        }
        int wordLen = wordEnd - wordStart;
        if (wordLen > MAX_WORD_LENGTH) {
            printf("Warning: Word '%s' is too long and will be truncated.\n", line);
            wordLen = MAX_WORD_LENGTH;
        }
        strncpy(wordCounts[numWords].word, wordStart, wordLen);
        wordCounts[numWords].word[wordLen] = '\0';
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Warning: Maximum number of words (%d) reached.\n", MAX_WORDS);
            break;
        }
    }

    fclose(inputFile);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}