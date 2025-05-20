//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_CAPACITY 10

typedef struct {
    char *word;
    int count;
} WordFrequency;

typedef struct {
    WordFrequency *items;
    int size;
    int capacity;
} FrequencyList;

FrequencyList* createFrequencyList(int capacity) {
    FrequencyList *list = malloc(sizeof(FrequencyList));
    list->size = 0;
    list->capacity = capacity;
    list->items = malloc(capacity * sizeof(WordFrequency));
    return list;
}

void freeFrequencyList(FrequencyList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->items[i].word);
    }
    free(list->items);
    free(list);
}

void resizeFrequencyList(FrequencyList *list) {
    list->capacity *= 2;
    list->items = realloc(list->items, list->capacity * sizeof(WordFrequency));
}

void addWord(FrequencyList *list, const char *word) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->items[i].word, word) == 0) {
            list->items[i].count++;
            return;
        }
    }
    if (list->size >= list->capacity) {
        resizeFrequencyList(list);
    }
    list->items[list->size].word = strdup(word);
    list->items[list->size].count = 1;
    list->size++;
}

int compare(const void *a, const void *b) {
    WordFrequency *wf1 = (WordFrequency *)a;
    WordFrequency *wf2 = (WordFrequency *)b;
    return wf2->count - wf1->count; // Sort in descending order
}

void printFrequencies(FrequencyList *list) {
    qsort(list->items, list->size, sizeof(WordFrequency), compare);
    printf("\nWord frequencies:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s: %d\n", list->items[i].word, list->items[i].count);
    }
}

void processText(FrequencyList *list, const char *text) {
    char *copy = strdup(text);
    char *token = strtok(copy, " \n\t.,!?\"';:()");
    while (token != NULL) {
        // Convert to lower case for case-insensitive counting
        for (int i = 0; token[i]; i++) {
            token[i] = tolower((unsigned char)token[i]);
        }
        addWord(list, token);
        token = strtok(NULL, " \n\t.,!?\"';:()");
    }
    free(copy);
}

int main() {
    FrequencyList *wordList = createFrequencyList(INITIAL_CAPACITY);
    char *text = malloc(1000 * sizeof(char)); // Buffer for input text
    printf("Enter text (type 'END' on a new line to finish):\n");

    // Read input until "END" is encountered
    size_t len = 0;
    while (fgets(text, 1000, stdin)) {
        if (strcmp(text, "END\n") == 0) {
            break;
        }
        processText(wordList, text);
    }

    printFrequencies(wordList);
    free(text);
    freeFrequencyList(wordList);
    return 0;
}