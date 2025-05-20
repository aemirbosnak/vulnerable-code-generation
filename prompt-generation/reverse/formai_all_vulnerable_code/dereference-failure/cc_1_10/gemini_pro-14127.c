//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * This program searches for a pattern in a text file using a modified version of the Knuth-Morris-Pratt algorithm.
 * The original KMP algorithm is designed to find a single pattern in a single text.
 * This modified version can find multiple patterns in a single text.
 *
 * The algorithm works by pre-processing the pattern to create a failure function.
 * The failure function is an array of integers that stores the length of the longest prefix of the pattern that is also a suffix of the pattern.
 * This information is used to skip over characters in the text that are not part of the pattern.
 *
 * The algorithm then starts at the beginning of the text and compares the pattern to the text.
 * If the current character in the pattern matches the current character in the text, the algorithm moves on to the next character in both the pattern and the text.
 * If the current character in the pattern does not match the current character in the text, the algorithm uses the failure function to skip over characters in the text that are not part of the pattern.
 *
 * The algorithm continues until either the pattern is found in the text or the end of the text is reached.
 * If the pattern is found, the algorithm prints the starting index of the pattern in the text.
 * If the pattern is not found, the algorithm prints a message to that effect.
 */

int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments.
    if (argc < 3) {
        printf("Usage: %s pattern text\n", argv[0]);
        return 1;
    }

    // Get the pattern and text from the command line arguments.
    char *pattern = argv[1];
    char *text = argv[2];

    // Create the failure function.
    int *failure = malloc(strlen(pattern) * sizeof(int));
    failure[0] = 0;
    int i = 1;
    int j = 0;
    while (i < strlen(pattern)) {
        if (pattern[i] == pattern[j]) {
            failure[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = failure[j - 1];
        } else {
            failure[i] = 0;
            i++;
        }
    }

    // Search for the pattern in the text.
    i = 0;
    j = 0;
    while (i < strlen(text)) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        } else if (j > 0) {
            j = failure[j - 1];
        } else {
            i++;
        }
        if (j == strlen(pattern)) {
            printf("Pattern found at index %d\n", i - j);
            j = failure[j - 1];
        }
    }

    // Free the memory allocated for the failure function.
    free(failure);

    return 0;
}