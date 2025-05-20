//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 50

// Structure to hold a word and its frequency
typedef struct word_frequency {
    char *word;
    int frequency;
} word_frequency;

// Function to count the frequency of each word in a sentence
void count_word_frequencies(char *sentence) {
    word_frequency *word_frequencies = (word_frequency *)calloc(1, sizeof(word_frequency));
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        if (strlen(token) > 0) {
            word_frequencies[0].word = token;
            word_frequencies[0].frequency = 1;
        }
        token = strtok(NULL, " ");
    }
}

// Function to print the most frequent word in a sentence
void print_most_frequent_word(word_frequency *word_frequencies) {
    int max_frequency = 0;
    char *max_word = NULL;
    for (int i = 0; i < sizeof(word_frequencies) / sizeof(word_frequencies[0]); i++) {
        if (word_frequencies[i].frequency > max_frequency) {
            max_frequency = word_frequencies[i].frequency;
            max_word = word_frequencies[i].word;
        }
    }
    printf("The most frequent word in the sentence is: %s\n", max_word);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Count the frequency of each word in the sentence
    word_frequency word_frequencies[10];
    count_word_frequencies(sentence);

    // Print the most frequent word in the sentence
    print_most_frequent_word(word_frequencies);

    return 0;
}