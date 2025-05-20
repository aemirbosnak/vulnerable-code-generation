//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 1000

// Global variables
int word_count = 0;
int line_count = 0;
char words[MAX_WORD_LEN][MAX_LINE_LEN];

// Function to get a line from the user
char *get_line() {
    char line[MAX_LINE_LEN];
    printf("Enter a line: ");
    fgets(line, MAX_LINE_LEN, stdin);
    return line;
}

// Function to count words in a line
void count_words(char *line) {
    char *word = strtok(line, " ");
    while (word != NULL && word[0] != '\0') {
        word_count++;
        word = strtok(NULL, " ");
    }
}

// Main function
int main() {
    // Initialize variables
    word_count = 0;
    line_count = 0;

    // Get the first line from the user
    char *line = get_line();
    count_words(line);

    // Get more lines from the user until they enter "done"
    while (strcmp(line, "done") != 0) {
        line = get_line();
        count_words(line);
    }

    // Print the results
    printf("Word count: %d\n", word_count);
    printf("Line count: %d\n", line_count);

    // Wait for user input before closing
    getchar();
    return 0;
}