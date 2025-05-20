//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *word1 = (WordCount *) a;
    WordCount *word2 = (WordCount *) b;
    return strcmp(word1->word, word2->word);
}

int getWordCounts(char *text, WordCount *wordCounts, int maxWords) {
    char *word = strtok(text, ",.?!;:");
    int count = 0;

    while (word!= NULL && count < maxWords) {
        strcpy(wordCounts[count].word, word);
        count++;
        word = strtok(NULL, ",.?!;:");
    }

    qsort(wordCounts, count, sizeof(WordCount), compareWords);

    return count;
}

void printWordCounts(WordCount *wordCounts, int count) {
    printf("Word Counts:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int maxWords = MAX_WORDS;
    WordCount wordCounts[MAX_WORDS];
    int wordCount = getWordCounts(text, wordCounts, maxWords);

    printf("Top %d Words:\n", wordCount);
    printWordCounts(wordCounts, wordCount);

    return 0;
}