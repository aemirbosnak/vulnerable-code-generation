//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate minimum of three integers
int min(int a, int b, int c) {
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

// Function to compute Levenshtein distance
int levenshtein(const char *s, const char *t) {
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);

    // Special case for empty strings
    if (len_s == 0) return len_t;
    if (len_t == 0) return len_s;

    // Create a distance matrix
    int *column = (int *)malloc(sizeof(int) * (len_t + 1));
    int *lastcolumn = (int *)malloc(sizeof(int) * (len_t + 1));
    
    // Initialize the first row
    for (size_t i = 0; i <= len_t; i++) {
        column[i] = i; // First row: distance from empty to prefix of t
    }

    // Iterate over each character in s
    for (size_t i = 1; i <= len_s; i++) {
        lastcolumn[0] = i; // First column: distance from empty to prefix of s
        for (size_t j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            column[j] = min(lastcolumn[j] + 1,      // Deletion
                            column[j - 1] + 1,    // Insertion
                            lastcolumn[j - 1] + cost); // Substitution
        }
        // Swap the pointers for the next iteration
        int *temp = lastcolumn;
        lastcolumn = column;
        column = temp;
    }

    // Get the final value from the last computed column
    int distance = lastcolumn[len_t];

    // Free allocated memory
    free(column);
    free(lastcolumn);

    return distance;
}

// Function to display results nicely
void display_results(const char *s, const char *t, int distance) {
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s, t, distance);
}

// Main driver function
int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *string1 = argv[1];
    const char *string2 = argv[2];

    // Calculate the Levenshtein distance
    int distance = levenshtein(string1, string2);

    // Display the results
    display_results(string1, string2, distance);
    
    return EXIT_SUCCESS;
}