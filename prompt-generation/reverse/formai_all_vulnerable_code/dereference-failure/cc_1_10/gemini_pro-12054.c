//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure to store word and its count
typedef struct word_count {
    char *word;
    int count;
} word_count;

// Function to compare two word_count structures
int compare_word_count(const void *a, const void *b) {
    const word_count *wc1 = (const word_count *)a;
    const word_count *wc2 = (const word_count *)b;
    return strcmp(wc1->word, wc2->word);
}

// Function to count words in a file
int count_words(FILE *fp, word_count **words) {
    int word_count = 0;
    int word_length = 0;
    char c;

    while ((c = fgetc(fp)) != EOF) {
        // Skip non-alphabetic characters
        if (!isalpha(c)) {
            if (word_length > 0) {
                // Allocate memory for the word
                char *word = malloc(word_length + 1);
                if (word == NULL) {
                    return -1;
                }

                // Copy the word from the buffer
                memcpy(word, *words, word_length);
                word[word_length] = '\0';

                // Add the word to the array
                *words = realloc(*words, (word_count + 1) * sizeof(word_count));
                if (*words == NULL) {
                    return -1;
                }
                (*words)[word_count].word = word;
                (*words)[word_count].count = 1;
                word_count++;
            }
            word_length = 0;
        } else {
            // Increment the word length
            word_length++;
        }
    }

    // Add the last word to the array
    if (word_length > 0) {
        // Allocate memory for the word
        char *word = malloc(word_length + 1);
        if (word == NULL) {
            return -1;
        }

        // Copy the word from the buffer
        memcpy(word, *words, word_length);
        word[word_length] = '\0';

        // Add the word to the array
        *words = realloc(*words, (word_count + 1) * sizeof(word_count));
        if (*words == NULL) {
            return -1;
        }
        (*words)[word_count].word = word;
        (*words)[word_count].count = 1;
        word_count++;
    }

    return word_count;
}

// Function to print the word counts
void print_word_counts(word_count *words, int word_count) {
    // Sort the words by count
    qsort(words, word_count, sizeof(word_count), compare_word_count);

    // Print the word counts
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// Function to free the memory allocated for the words
void free_words(word_count *words, int word_count) {
    for (int i = 0; i < word_count; i++) {
        free(words[i].word);
    }
    free(words);
}

int main() {
    // Open the file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Count the words
    word_count *words = NULL;
    int word_count = count_words(fp, &words);
    if (word_count == -1) {
        perror("Error counting words");
        return EXIT_FAILURE;
    }

    // Print the word counts
    print_word_counts(words, word_count);

    // Free the memory allocated for the words
    free_words(words, word_count);

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}