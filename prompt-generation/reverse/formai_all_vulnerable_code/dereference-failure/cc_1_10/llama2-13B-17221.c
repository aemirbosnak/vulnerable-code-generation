//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define LIST_SIZE 10

// Define a struct to hold a word and its length
typedef struct {
    char *word;
    size_t length;
} word_t;

// Function to generate a random word and its length
word_t* generate_word(void) {
    char letters[20] = "abcdefghijklmnopqrstuvwxyz";
    size_t length = rand() % 20 + 1;
    word_t* word = malloc(sizeof(word_t));
    word->word = malloc(length * sizeof(char));
    for (size_t i = 0; i < length; i++) {
        word->word[i] = letters[rand() % 20];
    }
    word->length = length;
    return word;
}

// Function to sort the list of words by length
void sort_words(word_t** words, size_t num_words) {
    // Use a bubble sort algorithm to sort the list
    for (size_t i = 0; i < num_words - 1; i++) {
        for (size_t j = 0; j < num_words - i - 1; j++) {
            if (words[j]->length > words[j + 1]->length) {
                word_t* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// Function to print the list of words
void print_words(word_t** words, size_t num_words) {
    for (size_t i = 0; i < num_words; i++) {
        printf("%s (%zu) ", words[i]->word, words[i]->length);
    }
    printf("\n");
}

int main(void) {
    // Create a list of words
    word_t** words = malloc(LIST_SIZE * sizeof(word_t*));
    for (size_t i = 0; i < LIST_SIZE; i++) {
        words[i] = generate_word();
    }

    // Sort the list of words by length
    sort_words(words, LIST_SIZE);

    // Print the list of words
    print_words(words, LIST_SIZE);

    return 0;
}