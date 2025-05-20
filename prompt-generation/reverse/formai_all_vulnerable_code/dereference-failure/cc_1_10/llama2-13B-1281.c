//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_COUNT 64

// Function to split a line into words
char** split_line(char* line) {
    char** words = malloc(sizeof(char*) * (strcspn(line, " ") + 1));
    char* word = strtok(line, " ");
    int i = 0;

    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }

    return words;
}

// Function to join words back into a line
char* join_words(char** words) {
    char* line = malloc(sizeof(char) * (strlen(words[0]) + 1));
    int i = 0;

    for (; i < MAX_WORD_COUNT; i++) {
        if (words[i] != NULL) {
            strcat(line, words[i]);
            strcat(line, " ");
        }
    }

    return line;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char** words = NULL;

    // Read a line from the user
    printf("Enter a line: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Split the line into words
    words = split_line(line);

    // Join the words back into a line
    char* joined_line = join_words(words);

    // Print the joined line
    printf("Joined line: %s\n", joined_line);

    // Free memory
    free(joined_line);
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}