//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_LENGTH 20
#define MAX_LOG_LINES 1000

// Structure to store a word and its frequency count
typedef struct {
    char *word;
    int frequency;
} word_frequency;

// Function to tokenize a log line and count the frequency of each word
void tokenize_log_line(char *line, word_frequency *frequencies) {
    char *token;
    int i = 0;

    // Tokenize the line into individual words
    while ((token = strtok(line, " ")) != NULL) {
        // Ignore empty tokens
        if (strlen(token) == 0) {
            continue;
        }

        // Add the token to the frequency list
        frequencies[i].word = token;
        frequencies[i].frequency = 1;

        // Increment the index for the next token
        i++;
    }
}

// Function to calculate the top 10 most frequent words in the log
void calculate_top_10(word_frequency *frequencies, int num_frequencies) {
    int i, j;
    int top_10_frequencies[10];

    // Initialize the top 10 frequencies to 0
    for (i = 0; i < 10; i++) {
        top_10_frequencies[i] = 0;
    }

    // Iterate over the frequency list and calculate the top 10
    for (i = 0; i < num_frequencies; i++) {
        // Check if the current frequency is in the top 10
        for (j = 0; j < 10; j++) {
            if (frequencies[i].frequency > top_10_frequencies[j]) {
                // Update the top 10 frequencies
                for (; j < 10; j++) {
                    top_10_frequencies[j] = top_10_frequencies[j + 1];
                }
                top_10_frequencies[j] = frequencies[i].frequency;
                break;
            }
        }
    }

    // Print the top 10 most frequent words
    for (i = 0; i < 10; i++) {
        printf("%d. %s (%d)\n", i + 1, top_10_frequencies[i], top_10_frequencies[i]);
    }
}

int main(int argc, char **argv) {
    // Load the log file
    FILE *log_file = fopen(argv[1], "r");

    // Tokenize the log lines and count the frequency of each word
    word_frequency frequencies[MAX_LOG_LINES];
    int num_frequencies = 0;
    char line[MAX_WORD_LENGTH];

    while (fgets(line, MAX_WORD_LENGTH, log_file) != NULL) {
        tokenize_log_line(line, frequencies);
        num_frequencies++;
    }

    // Calculate the top 10 most frequent words
    calculate_top_10(frequencies, num_frequencies);

    // Print the top 10 most frequent words
    calculate_top_10(frequencies, num_frequencies);

    // Close the log file
    fclose(log_file);

    return 0;
}