//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define INITIAL_CAPACITY 10

typedef struct {
    char **words;
    int *counts;
    int size;
    int capacity;
} WordFrequencyCounter;

void init_counter(WordFrequencyCounter *counter) {
    counter->size = 0;
    counter->capacity = INITIAL_CAPACITY;
    counter->words = (char **)malloc(sizeof(char *) * counter->capacity);
    counter->counts = (int *)malloc(sizeof(int) * counter->capacity);
}

void free_counter(WordFrequencyCounter *counter) {
    for (int i = 0; i < counter->size; i++) {
        free(counter->words[i]);
    }
    free(counter->words);
    free(counter->counts);
}

void add_word(WordFrequencyCounter *counter, const char *word) {
    for (int i = 0; i < counter->size; i++) {
        if (strcmp(counter->words[i], word) == 0) {
            counter->counts[i]++;
            return;
        }
    }

    if (counter->size >= counter->capacity) {
        counter->capacity *= 2;
        counter->words = realloc(counter->words, sizeof(char *) * counter->capacity);
        counter->counts = realloc(counter->counts, sizeof(int) * counter->capacity);
    }

    counter->words[counter->size] = strdup(word);
    counter->counts[counter->size] = 1;
    counter->size++;
}

void print_frequencies(WordFrequencyCounter *counter) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < counter->size; i++) {
        printf("%s: %d\n", counter->words[i], counter->counts[i]);
    }
}

void process_file(const char *filename) {
    WordFrequencyCounter counter;
    init_counter(&counter);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%49s", word) == 1) {
        add_word(&counter, word);
    }

    fclose(file);
    print_frequencies(&counter);
    free_counter(&counter);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    return EXIT_SUCCESS;
}