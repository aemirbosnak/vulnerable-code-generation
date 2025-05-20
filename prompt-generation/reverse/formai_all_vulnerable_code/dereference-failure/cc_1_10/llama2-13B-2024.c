//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

// Structure to store words and their frequencies
typedef struct {
    char *word;
    int frequency;
} word_frequency;

// Function to check for correct spelling
int check_spelling(char *sentence) {
    int i, j, k;
    word_frequency *words;
    int incorrect_count = 0;

    // Initialize word frequency list
    words = calloc(MAX_SENTENCE_LENGTH, sizeof(word_frequency));

    // Tokenize sentence into individual words
    for (i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) {
            // Check if word is in dictionary
            for (j = 0; j < MAX_DICTIONARY_SIZE; j++) {
                if (strcmp(words[j].word, sentence + i - words[j].word) == 0) {
                    // Word found in dictionary, increment frequency
                    words[j].frequency++;
                    break;
                }
            }

            // If word not found in dictionary, mark as incorrect
            if (j == MAX_DICTIONARY_SIZE) {
                incorrect_count++;
            }
        }
    }

    // Print correct and incorrect words
    for (j = 0; j < MAX_SENTENCE_LENGTH; j++) {
        if (words[j].frequency > 0) {
            printf("Correct word: %s (%d times)\n", words[j].word, words[j].frequency);
        } else {
            printf("Incorrect word: %s\n", words[j].word);
        }
    }

    // Free memory
    free(words);

    return incorrect_count;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    // Get sentence from user
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Check for correct spelling
    int incorrect_count = check_spelling(sentence);

    // Print result
    if (incorrect_count == 0) {
        printf("Congratulations! Your sentence is spelled correctly!\n");
    } else {
        printf("Oops! Your sentence contains %d spelling errors.\n", incorrect_count);
    }

    return 0;
}