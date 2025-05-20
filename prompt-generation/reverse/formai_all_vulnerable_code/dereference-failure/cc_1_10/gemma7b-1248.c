//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000

typedef struct Word {
    char **words;
    int size;
    int capacity;
} WordList;

WordList *createWordList() {
    WordList *list = malloc(sizeof(WordList));
    list->words = malloc(sizeof(char *) * MAX_WORDS);
    list->size = 0;
    list->capacity = MAX_WORDS;
    return list;
}

void addWordToList(WordList *list, char *word) {
    list->words[list->size++] = word;
    if (list->size == list->capacity) {
        list->words = realloc(list->words, sizeof(char *) * list->capacity * 2);
        list->capacity *= 2;
    }
}

int main() {
    WordList *list = createWordList();
    char *word = "Hello, world!";
    addWordToList(list, word);

    word = "This is a long sentence that will be added to the list.";
    addWordToList(list, word);

    word = "The quick brown fox jumps over the lazy dog.";
    addWordToList(list, word);

    time_t start = time(NULL);
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < list->size; j++) {
            printf("%s ", list->words[j]);
        }
    }
    time_t end = time(NULL);

    printf("\nTime taken: %ld seconds\n", end - start);

    return 0;
}