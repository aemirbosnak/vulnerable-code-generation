//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10000
#define MIN_LENGTH 1

struct word {
    char *word;
    int count;
};

int main() {
    // Get the text to be analyzed
    char text[MAX_LENGTH];
    printf("Enter the text to be analyzed (max 10000 characters): ");
    fgets(text, MAX_LENGTH, stdin);

    // Tokenize the text into individual words
    char *token = strtok(text, " ");
    struct word *word_array = malloc(sizeof(struct word) * 10);
    int i = 0;
    while (token != NULL && i < 10) {
        word_array[i].word = token;
        word_array[i].count = 1;
        token = strtok(NULL, " ");
        i++;
    }

    // Calculate the total number of words
    int total_words = i;

    // Calculate the average word length
    int avg_word_length = 0;
    for (int j = 0; j < i; j++) {
        avg_word_length += strlen(word_array[j].word);
    }
    avg_word_length /= i;

    // Calculate the standard deviation of word lengths
    int std_dev = 0;
    for (int j = 0; j < i; j++) {
        std_dev += pow(avg_word_length - strlen(word_array[j].word), 2);
    }
    std_dev /= i;

    // Print the results
    printf("Word Count:\n");
    for (int j = 0; j < i; j++) {
        printf("  %s (%d)\n", word_array[j].word, word_array[j].count);
    }
    printf("Average Word Length: %d\n", avg_word_length);
    printf("Standard Deviation of Word Lengths: %d\n", std_dev);

    // Free memory
    free(word_array);

    return 0;
}