//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 1

// Structure to store word information
typedef struct {
    char *word;
    size_t length;
} word_t;

// Function to count the number of words in a string
size_t count_words(const char *str) {
    size_t word_count = 0;
    word_t *words = NULL;

    // Split the string into individual words
    char *token = strtok(str, " ");
    while (token != NULL && token[0] != '\0') {
        // Allocate memory for the word
        words = realloc(words, (word_count + 1) * sizeof(word_t));
        if (words == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        // Store the word in the array
        words[word_count].word = token;
        words[word_count].length = strcspn(token, " ");
        word_count++;

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Free the memory allocated for the words
    free(words);

    return word_count;
}

int main() {
    // Define the string to count words in
    char str[] = "The quick brown fox jumps over the lazy dog";

    // Count the number of words in the string
    size_t word_count = count_words(str);

    // Print the number of words
    printf("There are %zu words in the string.\n", word_count);

    return 0;
}