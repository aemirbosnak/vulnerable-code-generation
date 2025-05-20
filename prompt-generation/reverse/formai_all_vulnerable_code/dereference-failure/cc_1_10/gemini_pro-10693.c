//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A sample text to process
char *text = "The quick brown fox jumps over the lazy dog.";

// A function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    char *word = strtok(str, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// A function to count the number of characters in a string
int count_characters(char *str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

// A function to count the number of lines in a string
int count_lines(char *str) {
    int count = 0;
    char *line = strtok(str, "\n");
    while (line != NULL) {
        count++;
        line = strtok(NULL, "\n");
    }
    return count;
}

// A function to count the number of sentences in a string
int count_sentences(char *str) {
    int count = 0;
    char *sentence = strtok(str, ".");
    while (sentence != NULL) {
        count++;
        sentence = strtok(NULL, ".");
    }
    return count;
}

// A function to print the statistics of a string
void print_statistics(char *str) {
    printf("Number of words: %d\n", count_words(str));
    printf("Number of characters: %d\n", count_characters(str));
    printf("Number of lines: %d\n", count_lines(str));
    printf("Number of sentences: %d\n", count_sentences(str));
}

int main() {
    // Print the original text
    printf("Original text:\n%s\n", text);

    // Print the statistics of the text
    print_statistics(text);

    return 0;
}