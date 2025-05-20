//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 20
#define INITIAL_CAPACITY 10

typedef struct {
    char **words;
    int capacity;
    int size;
} WordArray;

void initialize(WordArray *array) {
    array->words = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    array->capacity = INITIAL_CAPACITY;
    array->size = 0;
}

void resize(WordArray *array) {
    array->capacity *= 2;
    char **new_words = (char **)malloc(array->capacity * sizeof(char *));
    memcpy(new_words, array->words, array->size * sizeof(char *));
    free(array->words);
    array->words = new_words;
}

void add_word(WordArray *array, char *word) {
    if (array->size == array->capacity) {
        resize(array);
    }
    array->words[array->size++] = strdup(word);
}

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_array(WordArray *array) {
    qsort(array->words, array->size, sizeof(char *), compare);
    for (int i = 0; i < array->size; i++) {
        printf("%s ", array->words[i]);
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("input.txt", "r");
    char line[MAX_LINE_LENGTH];
    WordArray words = {NULL, INITIAL_CAPACITY, 0};

    initialize(&words);

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            add_word(&words, word);
            word = strtok(NULL, " ");
        }
    }

    print_array(&words);

    for (int i = 0; i < words.size; i++) {
        free(words.words[i]);
    }
    free(words.words);

    return 0;
}