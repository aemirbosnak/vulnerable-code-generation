//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100

// Structure to store word and its frequency
typedef struct {
    char *word;
    int frequency;
} word_frequency;

// Function to count the number of words in a given string
int count_words(char *str) {
    int i, word_count = 0;

    // Iterate through each character in the string
    for (i = 0; str[i] != '\0'; i++) {
        // If the current character is a space, increment the word count
        if (str[i] == ' ') {
            word_count++;
        }
    }

    return word_count;
}

// Function to count the frequency of each word in a given string
void count_word_frequencies(char *str) {
    int i, j, word_count = 0;
    word_frequency *word_frequencies = (word_frequency *)calloc(MAX_NUMBER_OF_WORDS, sizeof(word_frequency));

    // Iterate through each character in the string
    for (i = 0; str[i] != '\0'; i++) {
        // If the current character is a space, increment the word count
        if (str[i] == ' ') {
            word_count++;
        }

        // Reset the word frequency structure
        word_frequencies[word_count].word = NULL;
        word_frequencies[word_count].frequency = 0;

        // Iterate through each character after the current one
        for (j = i + 1; str[j] != '\0'; j++) {
            // If the current character is a word, increment its frequency
            if (isalpha(str[j])) {
                word_frequencies[word_count].word = str + i;
                word_frequencies[word_count].frequency++;
                break;
            }
        }
    }

    // Print the word frequencies
    for (i = 0; i < MAX_NUMBER_OF_WORDS; i++) {
        if (word_frequencies[i].word != NULL) {
            printf("%d. %s (%d)\n", i + 1, word_frequencies[i].word, word_frequencies[i].frequency);
        }
    }

    free(word_frequencies);
}

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog";
    int word_count = count_words(str);
    count_word_frequencies(str);
    return 0;
}