//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1024];
    char word[MAX_WORD_LEN];
    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));
    int numWords = 0;
    int i;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:-_=+\"'()[]{}<>");
        while (token!= NULL) {
            int len = strlen(token);
            if (len > 0 && len <= MAX_WORD_LEN) {
                for (i = 0; i < len; i++) {
                    if (!isalpha(token[i])) {
                        token[i] = '\0';
                        len = i;
                        break;
                    }
                }
                strcpy(word, token);
                WordCount *count = bsearch(word, wordCounts, numWords, sizeof(WordCount), compareWords);
                if (count == NULL) {
                    count = realloc(wordCounts, (numWords + 1) * sizeof(WordCount));
                    count[numWords].word[0] = '\0';
                    count[numWords].count = 1;
                    numWords++;
                } else {
                    count->count++;
                }
            }
            token = strtok(NULL, ",.?!;:-_=+\"'()[]{}<>");
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (i = 0; i < numWords; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    free(wordCounts);
    fclose(file);

    return 0;
}