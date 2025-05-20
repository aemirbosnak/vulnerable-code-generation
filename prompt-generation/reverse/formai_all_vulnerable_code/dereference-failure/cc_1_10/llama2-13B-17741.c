//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to hold the word count data
struct word_count {
    char *word;
    size_t count;
};

// Function to count the number of words in a given string
size_t count_words(const char *str) {
    // Initialize an empty array to store the word counts
    struct word_count *word_counts = calloc(1, sizeof(struct word_count));

    // Iterate through the string and count the number of words
    for (size_t i = 0; i < strlen(str); i++) {
        // Check if the current character is a word boundary (space or punctuation)
        if (isspace(str[i]) || str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?' || str[i] == '(' || str[i] == ')') {
            // If it is, increment the count for the previous word
            word_counts[word_counts->count].count++;
            // Reset the word count to 0 for the next word
            word_counts[word_counts->count].count = 0;
        }
        // If the current character is not a word boundary, add it to the current word count
        else {
            word_counts[word_counts->count].count++;
        }
    }
    // Return the total number of words in the string
    return word_counts->count;
}

// Function to print the word count data
void print_word_counts(const struct word_count *word_counts) {
    for (size_t i = 0; i < word_counts->count; i++) {
        printf("%d: %s\n", i + 1, word_counts[i].word);
    }
}

int main() {
    // Define a string to count the words in
    char str[] = "Hello, world! How are you today? I am fine, thank you. How about you?";

    // Call the count_words function to count the number of words in the string
    size_t word_count = count_words(str);

    // Call the print_word_counts function to print the word count data
    print_word_counts(word_count);

    return 0;
}