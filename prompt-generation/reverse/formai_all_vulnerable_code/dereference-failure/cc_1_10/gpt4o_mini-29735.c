//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int size;
    int capacity;
} WordFrequencyCounter;

void init_counter(WordFrequencyCounter *counter) {
    counter->words = malloc(INITIAL_CAPACITY * sizeof(WordCount));
    counter->size = 0;
    counter->capacity = INITIAL_CAPACITY;
}

void resize_counter(WordFrequencyCounter *counter) {
    counter->capacity *= 2;
    counter->words = realloc(counter->words, counter->capacity * sizeof(WordCount));
}

void add_word(WordFrequencyCounter *counter, const char *word) {
    for (int i = 0; i < counter->size; i++) {
        if (strcmp(counter->words[i].word, word) == 0) {
            counter->words[i].count++;
            return;
        }
    }
    
    // Add new word
    if (counter->size == counter->capacity) {
        resize_counter(counter);
    }
    
    counter->words[counter->size].word = strdup(word);
    counter->words[counter->size].count = 1;
    counter->size++;
}

int compare_words(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

void sort_counter(WordFrequencyCounter *counter) {
    qsort(counter->words, counter->size, sizeof(WordCount), compare_words);
}

void free_counter(WordFrequencyCounter *counter) {
    for (int i = 0; i < counter->size; i++) {
        free(counter->words[i].word);
    }
    free(counter->words);
}

void print_counter(const WordFrequencyCounter *counter) {
    for (int i = 0; i < counter->size; i++) {
        printf("%s: %d\n", counter->words[i].word, counter->words[i].count);
    }
}

bool is_word_character(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void process_text(WordFrequencyCounter *counter, FILE *file) {
    char word[MAX_WORD_LENGTH];
    int index = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (is_word_character(c)) {
            word[index++] = tolower(c); // Convert to lowercase
        } else {
            if (index > 0) { // If we have a word stored
                word[index] = '\0'; // Null-terminate the string
                add_word(counter, word);
                index = 0; // Reset index for next word
            }
        }
    }
    // Handle case where file ends with a word
    if (index > 0) {
        word[index] = '\0';
        add_word(counter, word);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordFrequencyCounter counter;
    init_counter(&counter);

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        free_counter(&counter);
        return EXIT_FAILURE;
    }

    process_text(&counter, file);
    fclose(file);

    sort_counter(&counter);
    print_counter(&counter);
    free_counter(&counter);

    return EXIT_SUCCESS;
}