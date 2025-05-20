//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MIN_WORDS 5
#define MAX_WORDS 10

int main() {
    char *line;
    size_t line_length;
    int words_found = 0;

    printf("Welcome to the C Log Analysis Program!\n");

    while (1) {
        // Read a line from the user
        printf("Enter a line of text: ");
        line = malloc(MAX_LINE_LENGTH);
        fgets(line, MAX_LINE_LENGTH, stdin);
        line_length = strlen(line);

        // Check if the line is empty or too long
        if (line_length == 0 || line_length > MAX_LINE_LENGTH) {
            continue;
        }

        // Count the number of words in the line
        words_found = count_words(line);

        // Check if the line contains the minimum number of words
        if (words_found < MIN_WORDS) {
            printf("Line too short (%d words)...\n", words_found);
            continue;
        }

        // Check if the line contains the maximum number of words
        if (words_found > MAX_WORDS) {
            printf("Line too long (%d words)...\n", words_found);
            continue;
        }

        // Print the line and its word count
        printf("Line: %s (%d words)\n", line, words_found);
    }

    return 0;
}

// Count the number of words in a line
int count_words(char *line) {
    int words = 0;
    char *token;

    // Tokenize the line into individual words
    token = strtok(line, " ");

    while (token != NULL) {
        words++;
        token = strtok(NULL, " ");
    }

    return words;
}