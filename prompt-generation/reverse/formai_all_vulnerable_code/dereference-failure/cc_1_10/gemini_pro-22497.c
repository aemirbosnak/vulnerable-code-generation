//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            count++;
        }
        ptr++;
    }
    return count + 1;
}

// Function to count the number of characters in a string
int count_characters(char *str) {
    int count = 0;
    char *ptr = str;
    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    return count;
}

// Function to count the number of lines in a string
int count_lines(char *str) {
    int count = 0;
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr == '\n') {
            count++;
        }
        ptr++;
    }
    return count + 1;
}

// Function to count the number of words, characters, and lines in a string
int *count_all(char *str) {
    int *counts = malloc(3 * sizeof(int));
    counts[0] = count_words(str);
    counts[1] = count_characters(str);
    counts[2] = count_lines(str);
    return counts;
}

int main() {
    char *str = "This is a test string.";
    int *counts = count_all(str);
    printf("Number of words: %d\n", counts[0]);
    printf("Number of characters: %d\n", counts[1]);
    printf("Number of lines: %d\n", counts[2]);
    free(counts);
    return 0;
}