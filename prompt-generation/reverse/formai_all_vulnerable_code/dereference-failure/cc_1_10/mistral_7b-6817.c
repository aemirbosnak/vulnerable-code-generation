//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50

typedef struct Word {
    char words[WORD_SIZE];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

bool isAlpha(char c) {
    return (isalpha(c) || isspace(c) || c == '\'' || c == '\'' || c == '\'s\'');
}

bool isDelimiter(char c) {
    return isspace(c) || c == '\'' || c == '\'s\'';
}

void processWord(Word *words, int *numWords, char *line) {
    int i;
    bool found = false;
    Word *current;

    toLower(line);

    for (i = 0; i < *numWords && strcmp(line, words[i].words) != 0; i++);

    if (i < *numWords) {
        words[i].count++;
    } else {
        if (*numWords >= MAX_WORDS) {
            Word *newWords = realloc(words, sizeof(Word) * (*numWords + MAX_WORDS));
            if (!newWords) {
                fprintf(stderr, "Memory error!\n");
                exit(EXIT_FAILURE);
            }
            strcpy(newWords[*numWords].words, line);
            newWords[*numWords].count = 1;
            words = newWords;
            *numWords += 1;
        } else {
            strcpy(words[*numWords].words, line);
            words[*numWords].count = 1;
            *numWords += 1;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1024];
    Word words[MAX_WORDS];
    int numWords = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp)) {
        char *wordStart, *wordEnd;
        bool inWord = false;

        for (wordStart = line, wordEnd = wordStart; *wordStart; wordStart++) {
            if (!inWord && isAlpha(*wordStart)) {
                wordStart--;
                inWord = true;
            }
            if (inWord && (isDelimiter(*wordEnd) || *wordEnd == '\0')) {
                processWord(words, &numWords, wordStart);
                wordStart++;
                inWord = false;
            }
        }
        if (inWord) {
            processWord(words, &numWords, line + (wordStart - line));
        }
    }

    fclose(fp);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].words, words[i].count);
    }

    return EXIT_SUCCESS;
}