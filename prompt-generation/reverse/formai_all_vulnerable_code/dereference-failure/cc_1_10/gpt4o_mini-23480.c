//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_SIZE 10

typedef struct {
    char **words;
    int *counts;
    int size;
    int capacity;
} WordFrequency;

// Function prototypes
WordFrequency* create_word_frequency(int initial_capacity);
void add_word(WordFrequency *wf, const char *word);
void free_word_frequency(WordFrequency *wf);
void to_lower_string(char *str);
int is_word_char(char c);
void count_words_in_file(const char *filename, WordFrequency *wf);
void print_word_frequencies(const WordFrequency *wf);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordFrequency *wf = create_word_frequency(INITIAL_SIZE);
    count_words_in_file(argv[1], wf);
    print_word_frequencies(wf);
    free_word_frequency(wf);

    return EXIT_SUCCESS;
}

WordFrequency* create_word_frequency(int initial_capacity) {
    WordFrequency *wf = (WordFrequency *)malloc(sizeof(WordFrequency));
    wf->words = (char **)malloc(sizeof(char *) * initial_capacity);
    wf->counts = (int *)malloc(sizeof(int) * initial_capacity);
    wf->size = 0;
    wf->capacity = initial_capacity;
    return wf;
}

void add_word(WordFrequency *wf, const char *word) {
    for (int i = 0; i < wf->size; i++) {
        if (strcmp(wf->words[i], word) == 0) {
            wf->counts[i]++;
            return;
        }
    }
    if (wf->size >= wf->capacity) {
        wf->capacity *= 2;
        wf->words = (char **)realloc(wf->words, sizeof(char *) * wf->capacity);
        wf->counts = (int *)realloc(wf->counts, sizeof(int) * wf->capacity);
    }
    wf->words[wf->size] = strdup(word);
    wf->counts[wf->size] = 1;
    wf->size++;
}

void free_word_frequency(WordFrequency *wf) {
    for (int i = 0; i < wf->size; i++) {
        free(wf->words[i]);
    }
    free(wf->words);
    free(wf->counts);
    free(wf);
}

void to_lower_string(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int is_word_char(char c) {
    return isalnum(c) || c == '\'';
}

void count_words_in_file(const char *filename, WordFrequency *wf) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char current_word[MAX_WORD_LENGTH];
    int index = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (is_word_char(c)) {
            current_word[index++] = c;
        } else {
            if (index > 0) {
                current_word[index] = '\0';
                to_lower_string(current_word);
                add_word(wf, current_word);
                index = 0;
            }
        }
    }
    
    // To catch any word left at the end
    if (index > 0) {
        current_word[index] = '\0';
        to_lower_string(current_word);
        add_word(wf, current_word);
    }

    fclose(file);
}

void print_word_frequencies(const WordFrequency *wf) {
    printf("Word frequencies:\n");
    for (int i = 0; i < wf->size; i++) {
        printf("%s: %d\n", wf->words[i], wf->counts[i]);
    }
}