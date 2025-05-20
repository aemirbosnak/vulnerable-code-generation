//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the word and its frequency
typedef struct word_freq {
    char *word;
    int freq;
} word_freq;

// Structure to hold an array of word_freq structures
typedef struct word_freq_array {
    word_freq *words;
    int size;
} word_freq_array;

// Function to create a new word_freq_array
word_freq_array *new_word_freq_array() {
    word_freq_array *array = malloc(sizeof(word_freq_array));
    array->words = NULL;
    array->size = 0;
    return array;
}

// Function to add a word to the word_freq_array
void add_word(word_freq_array *array, char *word) {
    // Check if the word is already in the array
    for (int i = 0; i < array->size; i++) {
        if (strcmp(array->words[i].word, word) == 0) {
            array->words[i].freq++;
            return;
        }
    }

    // If the word is not in the array, add it
    array->words = realloc(array->words, (array->size + 1) * sizeof(word_freq));
    array->words[array->size].word = strdup(word);
    array->words[array->size].freq = 1;
    array->size++;
}

// Function to print the word_freq_array
void print_word_freq_array(word_freq_array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%s: %d\n", array->words[i].word, array->words[i].freq);
    }
}

// Function to free the word_freq_array
void free_word_freq_array(word_freq_array *array) {
    for (int i = 0; i < array->size; i++) {
        free(array->words[i].word);
    }
    free(array->words);
    free(array);
}

// Main function
int main() {
    // Create a new word_freq_array
    word_freq_array *array = new_word_freq_array();

    // Open the file containing the text
    FILE *file = fopen("sherlock_holmes.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Remove punctuation from the word
            char *p = token;
            while (*p != '\0') {
                if (*p == '.' || *p == ',' || *p == ';' || *p == ':') {
                    *p = '\0';
                }
                p++;
            }

            // Convert the word to lowercase
            for (int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }

            // Add the word to the word_freq_array
            add_word(array, token);

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // Print the word_freq_array
    print_word_freq_array(array);

    // Free the word_freq_array
    free_word_freq_array(array);

    return 0;
}