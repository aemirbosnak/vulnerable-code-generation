//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LEN 1024
#define MIN_STRING_LEN 3

// Define a struct to hold the data for each word
typedef struct {
    char *word;
    int count;
} word_data_t;

// Define a function to generate a random word
word_data_t* get_random_word(void) {
    int i;
    word_data_t *wd = malloc(sizeof(word_data_t));
    for (i = 0; i < MIN_STRING_LEN; i++) {
        wd->word[i] = 'a' + (rand() % 26);
    }
    wd->count = 1;
    return wd;
}

// Define a function to increment the count of a word
void increment_count(word_data_t *wd) {
    wd->count++;
}

// Define a function to print the data for each word
void print_word_data(word_data_t *wd) {
    printf("%s: %d\n", wd->word, wd->count);
}

// Define the recursive function to generate all possible words
word_data_t* generate_all_words(int len) {
    if (len == 1) {
        // Base case: len = 1, return a single word
        word_data_t *wd = get_random_word();
        wd->count = 1;
        return wd;
    }

    // Recursive case: len > 1, generate all possible words of length len-1
    word_data_t *wd = malloc(sizeof(word_data_t));
    wd->word = malloc(len * sizeof(char));
    for (int i = 0; i < len - 1; i++) {
        wd->word[i] = 'a' + (rand() % 26);
    }
    wd->count = 1;

    // Recursively call generate_all_words() for each possible word of length len-1
    word_data_t *child_wd = generate_all_words(len - 1);
    for (int i = 0; i < child_wd->count; i++) {
        // Append the word to the parent word
        strcat(wd->word, child_wd->word);
        increment_count(wd);
    }

    // Free the child word data
    free(child_wd);

    return wd;
}

int main(void) {
    srand(time(NULL));

    // Generate all possible words of length 5
    word_data_t *wd = generate_all_words(5);

    // Print the data for each word
    for (int i = 0; i < wd->count; i++) {
        print_word_data(wd);
    }

    return 0;
}