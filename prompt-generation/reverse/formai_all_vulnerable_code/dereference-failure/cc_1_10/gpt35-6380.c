//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2

typedef struct {
    char* word;
    int count;
} word_count_t;

void add_word(char* word, word_count_t** word_counts, int* size, int* capacity) {
    // If the word already exists in the list of word counts, increment its count
    for (int i = 0; i < *size; i++) {
        if (strcmp(word_counts[i]->word, word) == 0) {
            word_counts[i]->count++;
            return;
        }
    }
    
    // If the list is at capacity, double its size
    if (*size == *capacity) {
        *capacity *= GROWTH_FACTOR;
        *word_counts = realloc(*word_counts, *capacity * sizeof(word_count_t));
    }
    
    // Add the new word to the list
    int length = strlen(word);
    char* word_copy = malloc((length + 1) * sizeof(char));
    strcpy(word_copy, word);
    word_count_t* new_word_count = malloc(sizeof(word_count_t));
    new_word_count->word = word_copy;
    new_word_count->count = 1;
    (*word_counts)[*size] = *new_word_count;
    (*size)++;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening %s\n", argv[1]);
        return 1;
    }
    
    // Initialize list of word counts with initial capacity
    word_count_t* word_counts = malloc(INITIAL_CAPACITY * sizeof(word_count_t));
    int size = 0;
    int capacity = INITIAL_CAPACITY;
    
    // Loop through each word in the file and add it to the list of word counts
    char word[MAX_WORD_LENGTH];
    int i = 0;
    int c = fgetc(fp);
    while (c != EOF) {
        if (isalpha(c)) {
            word[i] = tolower(c);
            i++;
        } else if (i > 0) {
            word[i] = '\0';
            add_word(word, &word_counts, &size, &capacity);
            i = 0;
        }
        c = fgetc(fp);
    }
    if (i > 0) {
        word[i] = '\0';
        add_word(word, &word_counts, &size, &capacity);
    }
    
    // Print out each word and its count
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
    
    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(word_counts[i].word);
        free(&word_counts[i]);
    }
    free(word_counts);
    fclose(fp);
    
    return 0;
}