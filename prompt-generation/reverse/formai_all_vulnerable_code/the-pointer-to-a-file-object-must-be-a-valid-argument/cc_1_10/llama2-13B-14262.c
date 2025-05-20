//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_WORD_LENGTH 20
#define MAX_LOG_LINES 10000

// Structure to store word frequency data
typedef struct {
    char *word;
    int frequency;
} word_frequency_t;

// Function to parse log file and count word frequencies
void parse_log(char *log_file, word_frequency_t *frequencies) {
    FILE *file = fopen(log_file, "r");
    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Tokenize line and count word frequencies
        char *token = strtok(line, " ");
        while (token != NULL) {
            if (i < MAX_WORD_LENGTH) {
                frequencies[i].word = token;
                frequencies[i].frequency++;
            }
            token = strtok(NULL, " ");
            i++;
        }
    }
    fclose(file);
}

// Function to generate report on top 10 most frequent words
void generate_report(word_frequency_t *frequencies) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d. %s (%d)\n", i + 1, frequencies[i].word, frequencies[i].frequency);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    // Load log file and count word frequencies
    word_frequency_t frequencies[MAX_WORD_LENGTH];
    parse_log(argv[1], frequencies);

    // Generate report on top 10 most frequent words
    generate_report(frequencies);

    return 0;
}