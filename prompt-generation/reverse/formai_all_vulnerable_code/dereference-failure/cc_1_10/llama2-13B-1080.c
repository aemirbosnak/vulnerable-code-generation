//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_OF_PATTERNS 5

// Structure to store pattern information
typedef struct {
    char *pattern;
    int num_of_matches;
} pattern_t;

// Function to generate random patterns
void generate_patterns(pattern_t *patterns, int num_of_patterns) {
    int i, j, k;
    char *pattern;

    for (i = 0; i < num_of_patterns; i++) {
        // Generate a random string of length 10
        pattern = (char *)malloc(10 * sizeof(char));
        for (j = 0; j < 10; j++) {
            pattern[j] = 'a' + (rand() % 26);
        }

        // Generate a random number of matches
        patterns[i].num_of_matches = rand() % 10 + 1;

        // Print the pattern and its number of matches
        printf("Pattern %d: %s (%d matches)\n", i + 1, pattern, patterns[i].num_of_matches);
    }
}

// Function to find all occurrences of a pattern in a string
int find_all_occurrences(char *haystack, char *needle, int *matches) {
    int i, j, k;

    // Initialize the number of matches to 0
    *matches = 0;

    // Loop through the haystack string
    for (i = 0; haystack[i] != '\0'; i++) {
        // If the current character is the start of a match
        if (haystack[i] == needle[0]) {
            // Find the length of the match
            j = 1;
            while (j < strlen(needle) && haystack[i + j] == needle[j]) {
                j++;
            }

            // If the match is valid, increment the number of matches
            if (j == strlen(needle)) {
                *matches += 1;
            }

            // Skip over the match
            i += j - 1;
        }
    }

    return *matches;
}

int main() {
    // Define the number of patterns and the maximum string length
    int num_of_patterns = 5;
    int max_string_length = 100;

    // Allocate memory for the patterns and the haystack
    pattern_t patterns[num_of_patterns];
    char haystack[max_string_length];

    // Generate the patterns and print them
    generate_patterns(patterns, num_of_patterns);

    // Read a string from the user and find all occurrences of the patterns
    printf("Enter a string: ");
    fgets(haystack, max_string_length, stdin);

    int matches[num_of_patterns];
    for (int i = 0; i < num_of_patterns; i++) {
        matches[i] = find_all_occurrences(haystack, patterns[i].pattern, &matches[i]);
    }

    // Print the number of matches for each pattern
    for (int i = 0; i < num_of_patterns; i++) {
        printf("Pattern %d: %d match(es)\n", i + 1, matches[i]);
    }

    return 0;
}