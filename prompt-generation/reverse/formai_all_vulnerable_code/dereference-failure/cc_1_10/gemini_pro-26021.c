//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000

// Create a struct to hold each word and its count
typedef struct {
    char *word;
    int count;
} Word;

// Get the number of words in a file
int get_word_count(FILE *fp) {
    int word_count = 0;
    char c;

    // Read each character from the file
    while ((c = fgetc(fp)) != EOF) {
        // If the character is a space or a newline, we have found the end of a word
        if (isspace(c) || c == '\n') {
            word_count++;
        }
    }

    // Return the number of words
    return word_count;
}

// Get the words from a file
Word *get_words_from_file(FILE *fp, int word_count) {
    // Allocate memory for the words
    Word *words = malloc(sizeof(Word) * word_count);

    // Read each character from the file
    int word_i = 0;
    char c;
    char word_buffer[100];
    int word_buffer_i = 0;
    while ((c = fgetc(fp)) != EOF) {
        // If the character is a space or a newline, we have found the end of a word
        if (isspace(c) || c == '\n') {
            // Copy the word from the buffer to the words array
            words[word_i].word = malloc(word_buffer_i + 1);
            strcpy(words[word_i].word, word_buffer);

            // Increment the word count
            words[word_i].count = 1;

            // Reset the word buffer
            word_buffer_i = 0;
            word_i++;
        } else {
            // Add the character to the word buffer
            word_buffer[word_buffer_i++] = c;
        }
    }

    // Return the words
    return words;
}

// Sort the words by count
void sort_words(Word *words, int word_count) {
    // Use bubble sort to sort the words by count
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = 0; j < word_count - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                // Swap the words
                Word temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// Print the words and their counts
void print_words(Word *words, int word_count) {
    // Print each word and its count
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// Free the memory allocated for the words
void free_words(Word *words, int word_count) {
    // Free the memory for each word
    for (int i = 0; i < word_count; i++) {
        free(words[i].word);
    }

    // Free the memory for the words array
    free(words);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a file name
    if (argc < 2) {
        printf("Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Get the number of words in the file
    int word_count = get_word_count(fp);

    // Get the words from the file
    Word *words = get_words_from_file(fp, word_count);

    // Sort the words by count
    sort_words(words, word_count);

    // Print the words and their counts
    print_words(words, word_count);

    // Free the memory allocated for the words
    free_words(words, word_count);

    // Close the file
    fclose(fp);

    return 0;
}