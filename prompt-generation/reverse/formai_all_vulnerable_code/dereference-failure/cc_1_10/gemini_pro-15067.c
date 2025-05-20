//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_WORD_COUNT 1000
#define MAX_SUMMARY_LENGTH 256

// Tokenizes a sentence into words, separating by spaces.
// Returns the number of words found.
int tokenize_sentence(const char *sentence, char *words[]) {
    int word_count = 0;
    char *word_start = (char *)sentence;
    while (*word_start != '\0') {
        // Skip leading whitespace
        while (isspace(*word_start)) {
            word_start++;
        }

        // If we've reached the end of the sentence, break out of the loop
        if (*word_start == '\0') {
            break;
        }

        // Find the end of the word
        char *word_end = word_start;
        while (*word_end != '\0' && !isspace(*word_end)) {
            word_end++;
        }

        // Copy the word into the array
        int word_length = word_end - word_start;
        words[word_count] = malloc(word_length + 1);
        memcpy(words[word_count], word_start, word_length);
        words[word_count][word_length] = '\0';

        // Increment the word count and move on to the next word
        word_count++;
        word_start = word_end;
    }

    return word_count;
}

// Calculates the frequency of each word in the sentence.
// Returns a pointer to the frequency array.
int *calculate_word_frequencies(const char *sentence, int word_count) {
    int *frequencies = calloc(word_count, sizeof(int));
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < word_count; j++) {
            if (strcmp(sentence[i], sentence[j]) == 0) {
                frequencies[i]++;
            }
        }
    }

    return frequencies;
}

// Sorts the words by their frequency, in descending order.
// Returns a pointer to the sorted array of word indices.
int *sort_words_by_frequency(int *frequencies, int word_count) {
    int *sorted_indices = malloc(word_count * sizeof(int));
    for (int i = 0; i < word_count; i++) {
        sorted_indices[i] = i;
    }

    // Sort the indices by frequency
    for (int i = 0; i < word_count; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (frequencies[sorted_indices[i]] < frequencies[sorted_indices[j]]) {
                int temp = sorted_indices[i];
                sorted_indices[i] = sorted_indices[j];
                sorted_indices[j] = temp;
            }
        }
    }

    return sorted_indices;
}

// Creates a summary of the sentence, using the top N most frequent words.
// Returns a pointer to the summary string.
char *summarize_sentence(const char *sentence, int *sorted_indices, int num_words) {
    char *summary = malloc(MAX_SUMMARY_LENGTH);
    int summary_length = 0;
    for (int i = 0; i < num_words; i++) {
        int word_index = sorted_indices[i];
        summary_length += strlen(sentence[word_index]) + 1;
        if (summary_length >= MAX_SUMMARY_LENGTH) {
            break;
        }
        strcat(summary, sentence[word_index]);
        strcat(summary, " ");
    }

    return summary;
}

// The main function.
int main() {
    // Get the sentence from the user.
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to summarize: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Tokenize the sentence into words.
    char *words[MAX_WORD_COUNT];
    int word_count = tokenize_sentence(sentence, words);

    // Calculate the frequency of each word in the sentence.
    int *frequencies = calculate_word_frequencies(sentence, word_count);

    // Sort the words by their frequency, in descending order.
    int *sorted_indices = sort_words_by_frequency(frequencies, word_count);

    // Create a summary of the sentence, using the top N most frequent words.
    char *summary = summarize_sentence(sentence, sorted_indices, 5);

    // Print the summary to the console.
    printf("Summary: %s\n", summary);

    // Free the allocated memory.
    free(words);
    free(frequencies);
    free(sorted_indices);
    free(summary);

    return 0;
}