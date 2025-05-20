//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    } else {
        return b < c ? b : c;
    }
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2, int len1, int len2) {
    int **matrix;
    matrix = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j; // Insertion
    }

    // Fill the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, // Deletion
                               matrix[i][j - 1] + 1, // Insertion
                               matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = matrix[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Utility function to get input strings
void get_input_strings(char **s1, char **s2) {
    size_t buffer_size = 256;
    *s1 = (char *)malloc(buffer_size * sizeof(char));
    *s2 = (char *)malloc(buffer_size * sizeof(char));

    printf("Enter the first string: ");
    getline(s1, &buffer_size, stdin);
    (*s1)[strcspn(*s1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    getline(s2, &buffer_size, stdin);
    (*s2)[strcspn(*s2, "\n")] = 0; // Remove newline character
}

// Main function to run the program
int main() {
    char *string1;
    char *string2;

    // Prompt user for input strings
    get_input_strings(&string1, &string2);

    // Calculate lengths of strings
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(string1, string2, len1, len2);

    // Output the result
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", string1, string2, distance);

    // Clean-up allocated memory
    free(string1);
    free(string2);

    return 0;
}