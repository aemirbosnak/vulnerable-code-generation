//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LEN 20
#define MAX_LOG_LEN 1000

// Structure to hold information about a word and its frequency
typedef struct {
    char *word;
    int frequency;
} word_info;

// Function to read a log file and count the frequency of each word
void count_words(char *log_file) {
    // Open the log file and read its contents
    FILE *file = fopen(log_file, "r");
    char line[MAX_LOG_LEN];
    word_info *words = calloc(1, sizeof(word_info));

    // Initialize the word frequency array
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        words[i].frequency = 0;
    }

    // Read each line of the log file
    while (fgets(line, MAX_LOG_LEN, file)) {
        // Ignore empty lines and comments
        if (isspace(line[0]) || line[0] == '#') {
            continue;
        }

        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Check if the word is not already in the frequency array
            int index = 0;
            for (; index < MAX_WORD_LEN; index++) {
                if (strcmp(words[index].word, token) == 0) {
                    break;
                }
            }

            // If the word is not in the array, add it and increment its frequency
            if (index == MAX_WORD_LEN) {
                words = realloc(words, (index + 1) * sizeof(word_info));
                words[index].word = token;
                words[index].frequency = 1;
            } else {
                words[index].frequency++;
            }

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Print the summary of the most frequent words
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        if (words[i].frequency > 0) {
            printf("%d. %s (%d)\n", i + 1, words[i].word, words[i].frequency);
        }
    }

    // Free memory
    free(words);
    fclose(file);
}

int main() {
    // Open the log file
    char *log_file = "example.log";
    count_words(log_file);
    return 0;
}