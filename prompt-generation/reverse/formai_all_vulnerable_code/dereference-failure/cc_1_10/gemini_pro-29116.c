//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a file
#define MAX_WORDS 10000

// Define the data structure for a word
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Define the data structure for the word list
typedef struct {
    Word words[MAX_WORDS];
    int size;
} WordList;

// Function to create a new word list
WordList* new_word_list() {
    WordList* word_list = malloc(sizeof(WordList));
    word_list->size = 0;
    return word_list;
}

// Function to add a word to the word list
void add_word_to_list(WordList* word_list, char* word) {
    // Check if the word is already in the list
    for (int i = 0; i < word_list->size; i++) {
        if (strcmp(word_list->words[i].word, word) == 0) {
            // If the word is already in the list, increment its count
            word_list->words[i].count++;
            return;
        }
    }

    // If the word is not in the list, add it to the list
    strcpy(word_list->words[word_list->size].word, word);
    word_list->words[word_list->size].count = 1;
    word_list->size++;
}

// Function to read a file and add its words to the word list
void read_file(WordList* word_list, char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line into words
        char* token = strtok(line, " ");
        while (token != NULL) {
            // Add the word to the word list
            add_word_to_list(word_list, token);

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);
}

// Function to print the word list
void print_word_list(WordList* word_list) {
    for (int i = 0; i < word_list->size; i++) {
        printf("%s: %d\n", word_list->words[i].word, word_list->words[i].count);
    }
}

// Function to free the memory allocated for the word list
void free_word_list(WordList* word_list) {
    free(word_list);
}

int main(int argc, char** argv) {
    // Check if the user has provided a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a new word list
    WordList* word_list = new_word_list();

    // Read the file and add its words to the word list
    read_file(word_list, argv[1]);

    // Print the word list
    print_word_list(word_list);

    // Free the memory allocated for the word list
    free_word_list(word_list);

    return EXIT_SUCCESS;
}