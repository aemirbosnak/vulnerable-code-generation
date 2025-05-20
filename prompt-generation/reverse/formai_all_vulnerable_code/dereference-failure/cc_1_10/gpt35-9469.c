//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

struct Word {
    char value[MAX_WORD_LENGTH];
    int frequency;
};

struct WordCount {
    struct Word *words;
    int count;
    int capacity;
};

int compareWords(const void *w1, const void *w2) {
    struct Word *word1 = (struct Word *) w1;
    struct Word *word2 = (struct Word *) w2;

    return strcmp(word1->value, word2->value);
}

int findWordIndex(struct WordCount *wordCount, char *word) {
    for (int i = 0; i < wordCount->count; i++) {
        if (strcmp(wordCount->words[i].value, word) == 0) {
            return i;
        }
    }

    return -1;
}

void addWord(struct WordCount *wordCount, char *word) {
    int index = findWordIndex(wordCount, word);

    if (index == -1) {
        if (wordCount->count == wordCount->capacity) {
            wordCount->capacity = wordCount->capacity * 2;
            wordCount->words = (struct Word *) realloc(wordCount->words, sizeof(struct Word) * wordCount->capacity);
        }

        index = wordCount->count;
        wordCount->words[index].frequency = 0;
        strcpy(wordCount->words[index].value, word);

        wordCount->count++;
    }

    wordCount->words[index].frequency++;
}

void printWordCount(struct WordCount *wordCount) {
    qsort(wordCount->words, wordCount->count, sizeof(struct Word), compareWords);

    for (int i = 0; i < wordCount->count; i++) {
        printf("%s: %d\n", wordCount->words[i].value, wordCount->words[i].frequency);
    }
}

int main() {
    char *text = "C is a general-purpose, imperative computer programming language, supporting structured programming, lexical variable scope and recursion, while a static type system prevents many unintended operations.";

    struct WordCount wordCount;
    wordCount.count = 0;
    wordCount.capacity = 1;
    wordCount.words = (struct Word *) malloc(sizeof(struct Word));

    char currentWord[MAX_WORD_LENGTH];
    int currentWordIndex = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            currentWord[currentWordIndex] = tolower(text[i]);
            currentWordIndex++;
        } else {
            if (currentWordIndex > 0) {
                currentWord[currentWordIndex] = '\0';
                addWord(&wordCount, currentWord);

                currentWordIndex = 0;
            }
        }
    }

    if (currentWordIndex > 0) {
        currentWord[currentWordIndex] = '\0';
        addWord(&wordCount, currentWord);
    }

    printWordCount(&wordCount);

    free(wordCount.words);

    return 0;
}