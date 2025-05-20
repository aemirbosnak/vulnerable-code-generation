//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_COUNT 100

// Function to split a line into words
void split_line(char *line, char **words) {
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL && i < MAX_WORD_COUNT) {
        words[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
}

// Function to remove duplicates from a list of words
void remove_duplicates(char **words) {
    int i = 0;
    int j = 0;
    while (i < MAX_WORD_COUNT) {
        if (strcmp(words[i], words[j]) != 0) {
            words[j++] = words[i];
        }
        i++;
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char words[MAX_WORD_COUNT][MAX_LINE_LENGTH];
    int num_lines = 0;

    // Read input from standard input
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        // Split the line into words
        split_line(line, words);

        // Remove duplicates from the list of words
        remove_duplicates(words);

        // Print the unique words
        for (int i = 0; i < MAX_WORD_COUNT; i++) {
            printf("%s ", words[i]);
        }
        printf("\n");

        num_lines++;
    }

    return 0;
}