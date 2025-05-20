//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

typedef struct Word {
    char **words;
    int size;
} WordList;

WordList *createWordList(int size) {
    WordList *list = malloc(sizeof(WordList));
    list->words = malloc(sizeof(char *) * size);
    list->size = size;
    return list;
}

void addWordToWordList(WordList *list, char *word) {
    list->words[list->size++] = strdup(word);
}

int main() {
    time_t start, end;
    int wordsTyped = 0;
    char word[MAX_WORDS];

    WordList *list = createWordList(MAX_WORDS);

    start = time(NULL);

    printf("Start typing:\n");

    while (wordsTyped < WORDS_PER_LINE) {
        scanf("%s", word);
        addWordToWordList(list, word);
        wordsTyped++;
    }

    end = time(NULL);

    printf("Time taken: %d seconds\n", end - start);

    printf("Number of words typed: %d\n", wordsTyped);

    printf("Words typed:\n");

    for (int i = 0; i < wordsTyped; i++) {
        printf("%s\n", list->words[i]);
    }

    return 0;
}