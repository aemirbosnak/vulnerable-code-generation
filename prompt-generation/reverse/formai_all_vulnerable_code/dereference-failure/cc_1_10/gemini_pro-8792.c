//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    // Get the lengths of the strings
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Create a matrix to store the Levenshtein distances
    int matrix[len1 + 1][len2 + 1];

    // Initialize the first row and column of the matrix
    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + fmin(matrix[i - 1][j], fmin(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }

    // Return the Levenshtein distance
    return matrix[len1][len2];
}

// Print a welcome message
void print_welcome_message() {
    printf("Welcome to the Levenshtein distance calculator!\n");
    printf("This program calculates the Levenshtein distance between two strings.\n");
    printf("The Levenshtein distance is a measure of the similarity between two strings.\n");
    printf("It is the minimum number of edits (insertions, deletions, or substitutions) required to transform one string into the other.\n");
}

// Get the input strings from the user
void get_input_strings(char **s1, char **s2) {
    printf("Enter the first string: ");
    *s1 = malloc(1024);
    scanf("%s", *s1);

    printf("Enter the second string: ");
    *s2 = malloc(1024);
    scanf("%s", *s2);
}

// Print the Levenshtein distance
void print_levenshtein_distance(int distance) {
    printf("The Levenshtein distance between the two strings is %d.\n", distance);
}

// Main function
int main() {
    // Print a welcome message
    print_welcome_message();

    // Get the input strings from the user
    char *s1, *s2;
    get_input_strings(&s1, &s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    print_levenshtein_distance(distance);

    // Free the allocated memory
    free(s1);
    free(s2);

    return 0;
}