//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of words to store
#define MAX_WORDS 1000

// Define the maximum length of a word
#define MAX_WORD_LEN 20

// Define the structure of a word entry
typedef struct word_entry {
    char word[MAX_WORD_LEN];
    int count;
} word_entry;

// Define the structure of the word frequency counter
typedef struct word_frequency_counter {
    word_entry words[MAX_WORDS];
    int num_words;
} word_frequency_counter;

// Create a new word frequency counter
word_frequency_counter* create_word_frequency_counter() {
    word_frequency_counter* wfc = malloc(sizeof(word_frequency_counter));
    wfc->num_words = 0;
    return wfc;
}

// Destroy a word frequency counter
void destroy_word_frequency_counter(word_frequency_counter* wfc) {
    free(wfc);
}

// Add a word to the word frequency counter
void add_word(word_frequency_counter* wfc, char* word) {
    int i;
    // Convert the word to lowercase
    for (i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    // Check if the word is already in the counter
    for (i = 0; i < wfc->num_words; i++) {
        if (strcmp(wfc->words[i].word, word) == 0) {
            wfc->words[i].count++;
            return;
        }
    }
    // If the word is not already in the counter, add it
    if (wfc->num_words < MAX_WORDS) {
        strcpy(wfc->words[wfc->num_words].word, word);
        wfc->words[wfc->num_words].count = 1;
        wfc->num_words++;
    }
}

// Print the word frequency counter
void print_word_frequency_counter(word_frequency_counter* wfc) {
    int i;
    for (i = 0; i < wfc->num_words; i++) {
        printf("%s: %d\n", wfc->words[i].word, wfc->words[i].count);
    }
}

// Read a file and add its words to the word frequency counter
void read_file(word_frequency_counter* wfc, char* filename) {
    FILE* fp = fopen(filename, "r");
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word) != EOF) {
        add_word(wfc, word);
    }
    fclose(fp);
}

// Main function
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Create a word frequency counter
    word_frequency_counter* wfc = create_word_frequency_counter();

    // Read the file
    read_file(wfc, argv[1]);

    // Print the word frequency counter
    print_word_frequency_counter(wfc);

    // Destroy the word frequency counter
    destroy_word_frequency_counter(wfc);

    return 0;
}