//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to convert a string to lower case
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a string is a valid word
bool is_valid_word(const char *word) {
    while (*word) {
        if (!isalnum(*word) && *word != '-') {
            return false;
        }
        word++;
    }
    return true;
}

// Function to compare two WordFrequency structures by frequency
int compare_frequency(const void *a, const void *b) {
    return ((WordFrequency *)b)->frequency - ((WordFrequency *)a)->frequency;
}

// Function to read the file and count word frequencies
void count_word_frequencies(const char *filename, WordFrequency words[], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        if (is_valid_word(word)) {
            bool found = false;
            for (int i = 0; i < *word_count; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].frequency++;
                    found = true;
                    break;
                }
            }
            if (!found && *word_count < MAX_WORDS) {
                strcpy(words[*word_count].word, word);
                words[*word_count].frequency = 1;
                (*word_count)++;
            }
        }
    }
    fclose(file);
}

// Function to print the summary of word frequencies
void print_summary(WordFrequency words[], int word_count, int top_n) {
    printf("\n=== Text Summary ===\n");
    qsort(words, word_count, sizeof(WordFrequency), compare_frequency);
    for (int i = 0; i < top_n && i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
    printf("=====================\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <top_n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int top_n = atoi(argv[2]);

    if (top_n <= 0) {
        fprintf(stderr, "Please enter a positive number for top_n\n");
        return EXIT_FAILURE;
    }

    WordFrequency words[MAX_WORDS];
    int word_count = 0;

    count_word_frequencies(filename, words, &word_count);
    
    printf("Total unique words: %d\n", word_count);
    print_summary(words, word_count, top_n);

    return EXIT_SUCCESS;
}