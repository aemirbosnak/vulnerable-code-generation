//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a file
#define MAX_WORDS 1000

// Create a struct to store a word and its count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count;

// Create an array of word_count structs to store the words and their counts
word_count word_counts[MAX_WORDS];

// Get the next word from the file
char *get_next_word(FILE *fp) {
    // Allocate memory for the word
    char *word = malloc(MAX_WORD_LENGTH);

    // Get the next word from the file
    int c = fgetc(fp);
    int i = 0;
    while (c != EOF && !isspace(c)) {
        word[i++] = c;
        c = fgetc(fp);
    }
    word[i] = '\0';

    // Return the word
    return word;
}

// Increment the count of the given word
void increment_word_count(char *word) {
    // Find the index of the word in the array of word_counts
    int index = -1;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            index = i;
            break;
        }
    }

    // If the word is not in the array, add it to the array
    if (index == -1) {
        strcpy(word_counts[MAX_WORDS - 1].word, word);
        word_counts[MAX_WORDS - 1].count = 0;
        index = MAX_WORDS - 1;
    }

    // Increment the count of the word
    word_counts[index].count++;
}

// Print the words and their counts
void print_word_counts() {
    // Print the header
    printf("Word\tCount\n");

    // Print the words and their counts
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

// Main function
int main() {
    // Open the file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    // Get the next word from the file
    char *word = get_next_word(fp);

    // While there are still words in the file
    while (word != NULL) {
        // Increment the count of the word
        increment_word_count(word);

        // Free the memory allocated for the word
        free(word);

        // Get the next word from the file
        word = get_next_word(fp);
    }

    // Close the file
    fclose(fp);

    // Print the words and their counts
    print_word_counts();

    return 0;
}