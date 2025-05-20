//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_LEN 20
#define MAX_FILE_SIZE 100000

// Structure to store word frequency data
typedef struct {
    char *word;
    int frequency;
} word_frequency_t;

// Function to calculate word frequency
void calculate_word_frequency(const char *text, word_frequency_t *frequencies) {
    char *word = NULL;
    int i = 0;
    int frequency = 0;

    while ((word = strtok(text, " ")) != NULL) {
        // Check if word is not empty and not already in the list
        if (word[0] != '\0' && !contains(frequencies, word)) {
            frequencies = realloc(frequencies, (i + 1) * sizeof(word_frequency_t));
            frequencies[i].word = word;
            frequencies[i].frequency = 1;
            i++;
        }
    }
}

// Function to display word frequency chart
void display_chart(word_frequency_t frequencies[], int num_words) {
    int i = 0;
    int j = 0;
    int k = 0;
    int max_frequency = 0;

    // Calculate maximum frequency
    for (i = 0; i < num_words; i++) {
        if (frequencies[i].frequency > max_frequency) {
            max_frequency = frequencies[i].frequency;
        }
    }

    // Print header
    printf("Word\tFrequency\n");

    // Print chart
    for (i = 0; i < num_words; i++) {
        printf("%-20s\t%d\n", frequencies[i].word, frequencies[i].frequency);
        if (frequencies[i].frequency == max_frequency) {
            printf("\t\t(max frequency)");
        }
    }
}

// Function to check if word is already in the list
int contains(word_frequency_t *frequencies, const char *word) {
    int i = 0;

    for (; i < sizeof(frequencies) / sizeof(word_frequency_t); i++) {
        if (strcmp(word, frequencies[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Load text file
    char text[MAX_FILE_SIZE];
    FILE *file = fopen("example.txt", "r");
    fread(text, 1, MAX_FILE_SIZE, file);
    fclose(file);

    // Calculate word frequency
    word_frequency_t frequencies[MAX_WORD_LEN];
    calculate_word_frequency(text, frequencies);

    // Display chart
    display_chart(frequencies, strcspn(text, "\n"));

    return 0;
}