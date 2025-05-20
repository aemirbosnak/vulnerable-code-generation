//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char **words;
    int *freq;
    int size;
    int capacity;
} WordFreqTable;

// Function to create a new Word Frequency Table
WordFreqTable* create_table() {
    WordFreqTable *table = (WordFreqTable*)malloc(sizeof(WordFreqTable));
    table->words = (char**)malloc(INITIAL_CAPACITY * sizeof(char*));
    table->freq = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    table->size = 0;
    table->capacity = INITIAL_CAPACITY;
    return table;
}

// Function to add a word to the frequency table
void add_word(WordFreqTable *table, const char *word) {
    // Check if the table needs to expand
    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->words = (char**)realloc(table->words, table->capacity * sizeof(char*));
        table->freq = (int*)realloc(table->freq, table->capacity * sizeof(int));
    }

    // Check if the word is already in the table
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->words[i], word) == 0) {
            table->freq[i]++;
            return;
        }
    }

    // Add the new word
    table->words[table->size] = strdup(word);
    table->freq[table->size] = 1;
    table->size++;
}

// Function to clean up and free the table
void free_table(WordFreqTable *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->words[i]);
    }
    free(table->words);
    free(table->freq);
    free(table);
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to process the text file
void process_file(const char *filename, WordFreqTable *table) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%99s", word) == 1) {
        to_lowercase(word);
        add_word(table, word);
    }

    fclose(file);
}

// Function to save results to a file
void save_results(const char *filename, WordFreqTable *table) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open output file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < table->size; i++) {
        fprintf(file, "%s: %d\n", table->words[i], table->freq[i]);
    }

    fclose(file);
    printf("Results saved to %s\n", filename);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file> [output_file]\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = (argc > 2) ? argv[2] : "output.txt";

    WordFreqTable *table = create_table();
    process_file(input_filename, table);

    printf("Word Frequency Count:\n");
    for (int i = 0; i < table->size; i++) {
        printf("%s: %d\n", table->words[i], table->freq[i]);
    }

    save_results(output_filename, table);
    free_table(table);
    return 0;
}