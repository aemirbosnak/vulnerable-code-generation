//LLAMA2-13B DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define MIN_NUMBER_OF_WORDS 5

// Structure to store a word and its frequency
typedef struct {
    char *word;
    int frequency;
} word_frequency;

// Function to generate a random word from a list of words
word_frequency *get_random_word(word_frequency *words, int num_words) {
    int i = rand() % num_words;
    word_frequency *word = words + i;
    return word;
}

// Function to print the most common word in a list of words
void print_most_common_word(word_frequency *words, int num_words) {
    int max_frequency = 0;
    char *max_word = NULL;

    for (int i = 0; i < num_words; i++) {
        if (words[i].frequency > max_frequency) {
            max_frequency = words[i].frequency;
            max_word = words[i].word;
        }
    }

    printf("The most common word is: %s\n", max_word);
}

// Function to generate a list of words and their frequencies
word_frequency *generate_word_frequencies(int num_words) {
    word_frequency *words = calloc(num_words, sizeof(word_frequency));

    for (int i = 0; i < num_words; i++) {
        words[i].word = calloc(1, strlen(words[i].word) + 1);
        words[i].frequency = 1;
    }

    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            words[i].frequency += words[j].frequency;
            words[j].frequency = 0;
        }
    }

    return words;
}

int main() {
    srand(time(NULL));

    // Generate a list of words and their frequencies
    word_frequency *words = generate_word_frequencies(MIN_NUMBER_OF_WORDS);

    // Print the most common word
    print_most_common_word(words, MIN_NUMBER_OF_WORDS);

    // Free the memory allocated for the words
    free(words);

    return 0;
}