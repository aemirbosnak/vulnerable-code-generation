//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store the word and its count
typedef struct word_count {
    char *word;
    int count;
} word_count;

// Function to compare two word_count structs by their counts
int compare_word_counts(const void *a, const void *b) {
    const word_count *word_count_a = (const word_count *)a;
    const word_count *word_count_b = (const word_count *)b;

    return word_count_b->count - word_count_a->count;
}

// Function to count the words in a string
int count_words(char *string) {
    int word_count = 0;

    // Split the string into words using strtok()
    char *token = strtok(string, " ");

    // Count the words until the end of the string is reached
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    return word_count;
}

// Function to find the most frequently occurring words in a string
char **find_most_frequent_words(char *string, int num_words) {
    // Allocate memory for the array of word_count structs
    word_count *word_counts = malloc(sizeof(word_count) * num_words);

    // Split the string into words using strtok()
    char *token = strtok(string, " ");

    // Initialize the word_counts array
    int i = 0;
    while (token != NULL && i < num_words) {
        word_counts[i].word = malloc(strlen(token) + 1);
        strcpy(word_counts[i].word, token);
        word_counts[i].count = 1;
        i++;
        token = strtok(NULL, " ");
    }

    // Count the occurrences of each word
    while (token != NULL) {
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(token, word_counts[j].word) == 0) {
                word_counts[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            // The word has not been found in the array, so add it
            word_counts[i].word = malloc(strlen(token) + 1);
            strcpy(word_counts[i].word, token);
            word_counts[i].count = 1;
            i++;
        }

        token = strtok(NULL, " ");
    }

    // Sort the word_counts array by the count of each word
    qsort(word_counts, num_words, sizeof(word_count), compare_word_counts);

    // Allocate memory for the array of most frequent words
    char **most_frequent_words = malloc(sizeof(char *) * num_words);

    // Copy the most frequent words into the array
    for (int i = 0; i < num_words; i++) {
        most_frequent_words[i] = word_counts[i].word;
    }

    // Free the memory allocated for the word_counts array
    for (int i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    // Return the array of most frequent words
    return most_frequent_words;
}

// Function to print the most frequently occurring words in a string
void print_most_frequent_words(char **most_frequent_words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", most_frequent_words[i], i + 1);
    }
}

// Main function
int main() {
    // Get the input string from the user
    char string[1000];
    printf("Enter a string: ");
    gets(string);

    // Count the words in the string
    int word_count = count_words(string);

    // Find the most frequently occurring words in the string
    char **most_frequent_words = find_most_frequent_words(string, 10);

    // Print the most frequently occurring words
    print_most_frequent_words(most_frequent_words, 10);

    // Free the memory allocated for the array of most frequent words
    for (int i = 0; i < 10; i++) {
        free(most_frequent_words[i]);
    }
    free(most_frequent_words);

    return 0;
}