//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50 // Maximum word length
#define MAX_WORDS 1000 // Maximum number of unique words to store

typedef struct WordData {
    char word[MAX_WORD_LEN];
    int frequency;
} WordData;

WordData *wordList[MAX_WORDS];

/**
 * Compare function for qsort() to sort the wordList array in descending order
 * based on word frequency.
 */
int compareWordsDescending(const void *a, const void *b) {
    WordData **w1 = (WordData **)a;
    WordData **w2 = (WordData **)b;
    return (*w2)->frequency - (*w1)->frequency;
}

/**
 * Case-insensitive version of strcmp().
 */
int stricmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && tolower(*s1) == tolower(*s2)) {
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

/**
 * Add a word to the word list.
 */
void addWord(const char *word) {
    // First search the word list for an existing entry
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordList[i] == NULL) {
            break;
        }
        if (stricmp(word, wordList[i]->word) == 0) {
            wordList[i]->frequency++;
            return;
        }
    }

    // If we didn't find an existing entry, add a new one to the end of the list
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordList[i] == NULL) {
            wordList[i] = (WordData *)malloc(sizeof(WordData));
            strncpy(wordList[i]->word, word, MAX_WORD_LEN);
            wordList[i]->frequency = 1;
            break;
        }
    }

    if (i == MAX_WORDS) {
        printf("Error: Max word count reached\n");
        exit(1);
    }
}

/**
 * Print the word frequency report.
 */
void printReport() {
    qsort(wordList, MAX_WORDS, sizeof(WordData *), compareWordsDescending);
    printf("Word Frequency Report\n");
    printf("---------------------\n");
    printf("Rank  Frequency  Word\n");
    printf("----  ---------  ----\n");
    int rank = 1;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordList[i] == NULL) {
            break;
        }
        printf("%-5d %-9d  %s\n", rank++, wordList[i]->frequency, wordList[i]->word);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp;
    char word[MAX_WORD_LEN + 1];
    memset(word, 0, sizeof(word));

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    int c, i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[i++] = tolower(c);
            if (i > MAX_WORD_LEN) {
                printf("Error: Max word length reached\n");
                exit(1);
            }
        } else if (i > 0) {
            addWord(word);
            i = 0;
            memset(word, 0, sizeof(word));
        }
    }
    if (i > 0) {
        addWord(word);
    }

    fclose(fp);

    printReport();

    return 0;
}