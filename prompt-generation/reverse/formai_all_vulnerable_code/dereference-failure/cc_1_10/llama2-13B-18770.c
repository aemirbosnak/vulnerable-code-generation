//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 1000

struct word {
    char *text;
    size_t length;
};

void word_count(const char *input) {
    size_t words_found = 0;
    size_t current_word_length = 0;
    char *current_word = NULL;

    // Create a list of words to count
    struct word *words = calloc(MAX_WORDS, sizeof(struct word));

    // Iterate over the input string
    for (size_t i = 0; i < strlen(input); i++) {
        // Check if we're at the end of a word
        if (isalpha(input[i]) && current_word_length > 0) {
            // Add the current word to the list
            words[words_found].text = current_word;
            words[words_found].length = current_word_length;

            // Reset the current word and length
            current_word = NULL;
            current_word_length = 0;

            // Increment the number of words found
            words_found++;
        }

        // Add the current character to the current word
        current_word_length++;
        current_word = realloc(current_word, current_word_length);
        current_word[current_word_length - 1] = input[i];

        // Check if we've reached the end of the input
        if (i == strlen(input) - 1) {
            // Add the current word to the list
            words[words_found].text = current_word;
            words[words_found].length = current_word_length;
        }
    }

    // Print the word count
    printf("Found %zu words\n", words_found);

    // Free the memory allocated for the word list
    free(words);
}

int main(void) {
    char input[] = "Hello, world! How are you today?";

    word_count(input);

    return 0;
}