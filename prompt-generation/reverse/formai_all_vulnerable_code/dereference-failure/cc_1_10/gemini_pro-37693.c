//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store word and its count
typedef struct word_count {
    char *word;
    int count;
} word_count_t;

// Function to compare two word_count_t structures
int compare_word_count(const void *a, const void *b) {
    const word_count_t *wa = (const word_count_t *)a;
    const word_count_t *wb = (const word_count_t *)b;
    return strcmp(wa->word, wb->word);
}

// Function to count words in a given string
int count_words(char *str, word_count_t **words) {
    // Allocate memory for the array of word_count_t structures
    *words = malloc(sizeof(word_count_t));

    // Initialize the count of words
    int count = 0;

    // Tokenize the string into words
    char *token = strtok(str, " ");

    // Loop through the tokens
    while (token != NULL) {
        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp((*words)[i].word, token) == 0) {
                // If the word is found, increment its count
                (*words)[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the array
        if (!found) {
            (*words) = realloc(*words, (count + 1) * sizeof(word_count_t));
            (*words)[count].word = strdup(token);
            (*words)[count].count = 1;
            count++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the count of words
    return count;
}

// Function to print the word counts
void print_word_counts(word_count_t *words, int count) {
    // Sort the array of word_count_t structures by word
    qsort(words, count, sizeof(word_count_t), compare_word_count);

    // Print the word counts
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// Main function
int main() {
    // Get the input string from the user
    char str[1024];
    printf("Enter a string: ");
    fgets(str, 1024, stdin);

    // Count the words in the string
    word_count_t *words;
    int count = count_words(str, &words);

    // Print the word counts
    print_word_counts(words, count);

    // Free the memory allocated for the array of word_count_t structures
    for (int i = 0; i < count; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}