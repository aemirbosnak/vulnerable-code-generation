//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char word[MAX_SENTENCE_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;

    return strcmp(wordA->word, wordB->word);
}

char *cleanString(char *string) {
    int i, j;
    char *clean = malloc(strlen(string) + 1);

    for (i = 0, j = 0; string[i]!= '\0'; i++) {
        if (isalpha(string[i])) {
            clean[j++] = tolower(string[i]);
        }
    }

    clean[j] = '\0';
    return clean;
}

int getWordCount(char *sentence) {
    int count = 0;
    char *word;

    word = strtok(sentence, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_SENTENCE_LENGTH];
    Word words[MAX_WORDS];
    int numWords = 0;
    qsort_r(words, 0, MAX_WORDS, compareWords);

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        char *cleanLine = cleanString(line);
        int wordCount = getWordCount(cleanLine);

        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        for (int i = 0; i < wordCount; i++) {
            char *word = strtok(cleanLine, " ");

            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }

        free(cleanLine);
    }

    fclose(inputFile);

    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}