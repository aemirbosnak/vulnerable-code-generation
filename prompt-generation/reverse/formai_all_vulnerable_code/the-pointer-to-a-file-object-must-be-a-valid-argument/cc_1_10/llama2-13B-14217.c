//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} word_t;

int main(void) {
    // Initialize the word list
    word_t *words = calloc(MAX_WORDS, sizeof(word_t));

    // Open the log file
    FILE *log_file = fopen("peaceful_log.txt", "r");

    // Loop through the log file and count the occurrences of each word
    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, log_file)) {
        // Tokenize the line into words
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            // Check if the word is already in the list
            int i = 0;
            while (words[i].word != NULL) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
                i++;
            }
            if (words[i].word == NULL) {
                // Add the word to the list
                words[i].word = token;
                words[i].count = 1;
            }
            token = strtok(NULL, " ");
        }
    }

    // Print out the log analysis
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word != NULL) {
            printf("Peaceful word: %s (%d times)\n", words[i].word, words[i].count);
        }
    }

    // Close the log file
    fclose(log_file);

    // Free the word list
    free(words);

    return 0;
}