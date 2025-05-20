//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to hold word and its frequency
typedef struct {
    char *word;
    int count;
} WordFreq;

// Function to compare two WordFreq structs (for sorting)
int compare(const void *a, const void *b) {
    return ((WordFreq *)b)->count - ((WordFreq *)a)->count; // Sort in descending order
}

// Function to clean and normalize a word
char* clean_word(const char *word) {
    int len = strlen(word);
    char *cleaned = malloc(len + 1);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(word[i])) {
            cleaned[j++] = tolower(word[i]); // Lowercase conversion
        }
    }
    cleaned[j] = '\0';
    return cleaned;
}

// Function to find word frequencies
void count_word_frequencies(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char **words = NULL;
    int size = 0;
    int capacity = 10;

    words = malloc(capacity * sizeof(char *)); // Initial capacity

    char buffer[256];
    while (fscanf(file, "%255s", buffer) == 1) {
        char *word = clean_word(buffer);

        // Check if the word already exists
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(words[i], word) == 0) {
                found = 1;
                break;
            }
        }

        // If new word, add it to the list
        if (!found) {
            if (size >= capacity) {
                capacity *= 2; // Double the capacity if needed
                words = realloc(words, capacity * sizeof(char *));
            }
            words[size++] = word;
        } else {
            free(word); // Already counted
        }
    }

    fclose(file);

    WordFreq *freq_array = malloc(size * sizeof(WordFreq));
    for (int i = 0; i < size; i++) {
        freq_array[i].word = words[i];
        freq_array[i].count = 1;

        // Increment count for duplicates
        for (int j = 0; j < size; j++) {
            if (i != j && strcmp(words[i], words[j]) == 0) {
                freq_array[i].count++;
            }
        }
    }

    // Sort by frequency
    qsort(freq_array, size, sizeof(WordFreq), compare);

    // Output the results
    printf("Word Frequency Counts:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", freq_array[i].word, freq_array[i].count);
        free(freq_array[i].word); // Free each word
    }

    free(freq_array);
    free(words);
}

// The main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    count_word_frequencies(argv[1]);

    return 0;
}