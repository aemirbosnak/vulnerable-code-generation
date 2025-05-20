//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[1024];
    int lineCount = 0;
    int totalWords = 0;

    WordCount* wordCounts = malloc(MAX_WORDS * sizeof(WordCount));
    if (wordCounts == NULL) {
        printf("Memory error.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        lineCount++;
        char* word = strtok(line, " \t\n\r\f");
        while (word!= NULL) {
            totalWords++;
            WordCount* count = bsearch(word, wordCounts, totalWords, sizeof(WordCount), compareWords);
            if (count == NULL) {
                count = wordCounts + totalWords;
                totalWords++;
                count->word[0] = '\0';
            }
            count->count++;
            word = strtok(NULL, " \t\n\r\f");
        }
    }

    fclose(file);

    qsort(wordCounts, totalWords, sizeof(WordCount), compareWords);

    printf("Total words: %d\n", totalWords);
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);
    return 0;
}