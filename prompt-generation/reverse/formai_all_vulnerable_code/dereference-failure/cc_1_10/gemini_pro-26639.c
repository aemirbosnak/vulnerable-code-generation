//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a file
#define MAX_WORDS 10000

// Define the structure of a word
typedef struct word {
    char *word;
    int count;
} word;

// Define the structure of a word list
typedef struct word_list {
    word *words;
    int size;
} word_list;

// Create a new word list
word_list *new_word_list() {
    word_list *wl = malloc(sizeof(word_list));
    wl->words = malloc(sizeof(word) * MAX_WORDS);
    wl->size = 0;
    return wl;
}

// Add a word to a word list
void add_word(word_list *wl, char *word) {
    int i;
    // Check if the word is already in the list
    for (i = 0; i < wl->size; i++) {
        if (strcmp(wl->words[i].word, word) == 0) {
            wl->words[i].count++;
            return;
        }
    }
    // If the word is not in the list, add it
    wl->words[wl->size].word = malloc(strlen(word) + 1);
    strcpy(wl->words[wl->size].word, word);
    wl->words[wl->size].count = 1;
    wl->size++;
}

// Print a word list
void print_word_list(word_list *wl) {
    int i;
    for (i = 0; i < wl->size; i++) {
        printf("%s: %d\n", wl->words[i].word, wl->words[i].count);
    }
}

// Free a word list
void free_word_list(word_list *wl) {
    int i;
    for (i = 0; i < wl->size; i++) {
        free(wl->words[i].word);
    }
    free(wl->words);
    free(wl);
}

// Read a file into a word list
word_list *read_file(char *filename) {
    FILE *fp;
    char buffer[MAX_WORD_LENGTH];
    word_list *wl = new_word_list();
    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }
    // Read the file line by line
    while (fgets(buffer, MAX_WORD_LENGTH, fp)) {
        // Tokenize the line into words
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            // Add the word to the word list
            add_word(wl, token);
            // Get the next token
            token = strtok(NULL, " ");
        }
    }
    // Close the file
    fclose(fp);
    // Return the word list
    return wl;
}

// Sort a word list by count
void sort_word_list(word_list *wl) {
    int i, j;
    word temp;
    for (i = 0; i < wl->size - 1; i++) {
        for (j = i + 1; j < wl->size; j++) {
            if (wl->words[i].count < wl->words[j].count) {
                temp = wl->words[i];
                wl->words[i] = wl->words[j];
                wl->words[j] = temp;
            }
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    // Read the file into a word list
    word_list *wl = read_file(argv[1]);
    if (wl == NULL) {
        return 1;
    }
    // Sort the word list by count
    sort_word_list(wl);
    // Print the word list
    print_word_list(wl);
    // Free the word list
    free_word_list(wl);
    return 0;
}