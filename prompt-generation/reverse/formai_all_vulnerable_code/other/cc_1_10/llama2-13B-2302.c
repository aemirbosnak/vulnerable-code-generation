//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX_WORD_LEN 20
#define MAX_LOG_LEN 10000

// Structure to store word frequency information
typedef struct {
    char *word;
    int freq;
} word_freq_t;

// Function to parse log file and count word frequencies
void count_word_frequencies(char *log_file) {
    // Open log file and read line by line
    FILE *file = fopen(log_file, "r");
    assert(file != NULL);

    // Initialize word frequency information
    word_freq_t *word_freqs = calloc(1, sizeof(word_freq_t));

    // Read each line of the log file
    char line[MAX_LOG_LEN];
    while (fgets(line, MAX_LOG_LEN, file) != NULL) {
        // Tokenize the line and count the frequency of each word
        char *token = strtok(line, " ");
        while (token != NULL) {
            int word_len = strcspn(token, " ");
            char *word = token;
            word_freqs[word_len - 1].word = word;
            word_freqs[word_len - 1].freq++;
            token = strtok(NULL, " ");
        }
    }

    // Print the top 5 most frequent words and their frequencies
    int top_5_freqs[5];
    for (int i = 0; i < 5; i++) {
        top_5_freqs[i] = 0;
    }
    for (int i = 0; i < sizeof(word_freqs) / sizeof(word_freqs[0]); i++) {
        if (word_freqs[i].freq > top_5_freqs[4]) {
            top_5_freqs[4] = word_freqs[i].freq;
            top_5_freqs[3] = word_freqs[i].word;
        }
        if (word_freqs[i].freq > top_5_freqs[3]) {
            top_5_freqs[3] = word_freqs[i].freq;
            top_5_freqs[2] = word_freqs[i].word;
        }
        if (word_freqs[i].freq > top_5_freqs[2]) {
            top_5_freqs[2] = word_freqs[i].freq;
            top_5_freqs[1] = word_freqs[i].word;
        }
        if (word_freqs[i].freq > top_5_freqs[1]) {
            top_5_freqs[1] = word_freqs[i].freq;
            top_5_freqs[0] = word_freqs[i].word;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d. %s (%d times)\n", i + 1, top_5_freqs[i], top_5_freqs[i]);
    }

    // Free memory
    free(word_freqs);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s log_file\n", argv[0]);
        return 1;
    }
    char *log_file = argv[1];
    count_word_frequencies(log_file);
    return 0;
}