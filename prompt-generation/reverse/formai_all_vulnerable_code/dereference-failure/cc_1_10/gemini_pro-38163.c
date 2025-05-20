//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words to store
#define MAX_WORDS 1000

// Define the structure of a word
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_t;

// Define the structure of the word list
typedef struct {
    word_t words[MAX_WORDS];
    int num_words;
} word_list_t;

// Create a new word list
word_list_t *new_word_list() {
    word_list_t *list = malloc(sizeof(word_list_t));
    list->num_words = 0;
    return list;
}

// Add a word to the word list
void add_word(word_list_t *list, char *word) {
    // Check if the word is already in the list
    for (int i = 0; i < list->num_words; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            // If the word is already in the list, increment its count
            list->words[i].count++;
            return;
        }
    }

    // If the word is not in the list, add it to the list
    strcpy(list->words[list->num_words].word, word);
    list->words[list->num_words].count = 1;
    list->num_words++;
}

// Print the word list
void print_word_list(word_list_t *list) {
    for (int i = 0; i < list->num_words; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].count);
    }
}

// Free the memory allocated for the word list
void free_word_list(word_list_t *list) {
    free(list);
}

// Read a file and count the frequency of each word
word_list_t *count_words(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create a new word list
    word_list_t *list = new_word_list();

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Tokenize the line into words
        char *word = strtok(line, " ");
        while (word != NULL) {
            // Remove punctuation from the word
            char *punct = strpbrk(word, ".,;:\"?!()");
            if (punct != NULL) {
                *punct = '\0';
            }

            // Convert the word to lowercase
            for (int i = 0; word[i] != '\0'; i++) {
                word[i] = tolower(word[i]);
            }

            // Add the word to the word list
            add_word(list, word);

            // Get the next word
            word = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    return list;
}

int main() {
    // Count the words in the file
    word_list_t *list = count_words("input.txt");

    // Print the word list
    print_word_list(list);

    // Free the memory allocated for the word list
    free_word_list(list);

    return 0;
}