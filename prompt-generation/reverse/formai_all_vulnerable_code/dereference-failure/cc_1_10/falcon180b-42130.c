//Falcon-180B DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 2;
    }

    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *p = line;
        while (*p!= '\0') {
            if (isspace(*p)) {
                *p = '\0';
            }
            p++;
        }
        p = line;
        while (*p!= '\0') {
            strcpy(word, p);
            p += strlen(p) + 1;
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: too many words\n");
                    return 3;
                }
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}