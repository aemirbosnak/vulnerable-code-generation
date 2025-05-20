//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int isAlpha(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

int splitWord(char *line, Word *words, int *wordsCount) {
    char currentWord[WORD_LENGTH];
    int currentWordLength = 0;

    toLower(line);

    for (int i = 0; line[i]; i++) {
        if (isDelimiter(line[i])) {
            if (currentWordLength > 0) {
                strncpy(words[*wordsCount].word, currentWord, WORD_LENGTH);
                words[*wordsCount].count = 1;
                (*wordsCount)++;

                if (*wordsCount >= MAX_WORDS) {
                    printf("Error: Too many words.\n");
                    return 1;
                }

                currentWordLength = 0;
            }

            if (line[i] != ' ' && i > 0 && isDelimiter(line[i - 1])) {
                words[*wordsCount - 1].count++;
            }

            continue;
        }

        if (isAlpha(line[i])) {
            currentWord[currentWordLength++] = line[i];
        }
    }

    if (currentWordLength > 0) {
        strncpy(words[*wordsCount].word, currentWord, WORD_LENGTH);
        words[*wordsCount].count = 1;
        (*wordsCount)++;
    }

    return 0;
}

int main(int argc, char **argv) {
    FILE *file;
    char filename[100];
    char line[1024];
    Word words[MAX_WORDS];
    int wordsCount = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        int error = splitWord(line, words, &wordsCount);

        if (error) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    printf("\nWord Frequency Table:\n");
    printf("------------------------\n");

    for (int i = 0; i < wordsCount; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    return 0;
}