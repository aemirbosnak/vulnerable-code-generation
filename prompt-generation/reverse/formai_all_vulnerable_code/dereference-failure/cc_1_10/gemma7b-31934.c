//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_COUNT 1000

typedef struct WordCount {
    char word[MAX_WORD_COUNT];
    int count;
} WordCount;

WordCount *WordCount_Create() {
    WordCount *wordCount = malloc(sizeof(WordCount));
    wordCount->word[0] = '\0';
    wordCount->count = 0;
    return wordCount;
}

void WordCount_AddWord(WordCount *wordCount, char *word) {
    int i = 0;
    for (; i < MAX_WORD_COUNT && wordCount->word[i] != '\0'; i++) {
        if (strcmp(word, wordCount->word[i]) == 0) {
            wordCount->count++;
            return;
        }
    }

    wordCount->word[i] = word;
    wordCount->count++;
}

int WordCount_GetWordCount(WordCount *wordCount) {
    return wordCount->count;
}

int main() {
    WordCount *wordCount = WordCount_Create();

    WordCount_AddWord(wordCount, "water");
    WordCount_AddWord(wordCount, "food");
    WordCount_AddWord(wordCount, "shelter");
    WordCount_AddWord(wordCount, "hope");

    int wordCount_GetWordCount = WordCount_GetWordCount(wordCount);

    printf("Total word count: %d\n", wordCount_GetWordCount);

    free(wordCount);

    return 0;
}