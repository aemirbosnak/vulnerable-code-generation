//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_WORD_LENGTH 20
#define MAX_LOG_LENGTH 1000

// Structure to store word frequency information
typedef struct {
    char *word;
    int count;
} word_frequency_t;

// Function to parse log file and count word frequencies
void parse_log(const char *log_file, word_frequency_t *frequencies) {
    FILE *log_file_ptr = fopen(log_file, "r");
    assert(log_file_ptr != NULL);

    char line[MAX_LOG_LENGTH];
    while (fgets(line, MAX_LOG_LENGTH, log_file_ptr) != NULL) {
        // Tokenize line into words
        char *token = strtok(line, " ");
        while (token != NULL && token[0] != '\0') {
            // Check if word is already in the frequency list
            int i = 0;
            while (i < sizeof(frequencies) / sizeof(frequencies[0])) {
                if (strcmp(token, frequencies[i].word) == 0) {
                    // Increment word frequency
                    frequencies[i].count++;
                    break;
                }
                i++;
            }
            // If word is not in the list, add it
            if (i >= sizeof(frequencies) / sizeof(frequencies[0])) {
                frequencies[i].word = token;
                frequencies[i].count = 1;
                i++;
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(log_file_ptr);
}

// Function to print summary of word frequencies
void print_summary(word_frequency_t *frequencies) {
    int i = 0;
    printf("Word Frequencies:\n");
    while (i < sizeof(frequencies) / sizeof(frequencies[0])) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    word_frequency_t frequencies[10];
    parse_log(argv[1], frequencies);
    print_summary(frequencies);

    return 0;
}