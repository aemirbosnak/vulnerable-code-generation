//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings.
int levenshtein(char *s1, char *s2) {
    // Create a matrix to store the Levenshtein distances.
    int **distances = (int **)malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i < strlen(s1) + 1; i++) {
        distances[i] = (int *)malloc((strlen(s2) + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i < strlen(s1) + 1; i++) {
        distances[i][0] = i;
    }
    for (int j = 0; j < strlen(s2) + 1; j++) {
        distances[0][j] = j;
    }

    // Calculate the Levenshtein distances for the rest of the matrix.
    for (int i = 1; i < strlen(s1) + 1; i++) {
        for (int j = 1; j < strlen(s2) + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                distances[i][j] = distances[i - 1][j - 1];
            } else {
                distances[i][j] = 1 + fmin(distances[i - 1][j], fmin(distances[i][j - 1], distances[i - 1][j - 1]));
            }
        }
    }

    // Return the Levenshtein distance between the two strings.
    return distances[strlen(s1)][strlen(s2)];
}

// Free the memory allocated for the Levenshtein distance matrix.
void free_distances(int **distances, int size) {
    for (int i = 0; i < size; i++) {
        free(distances[i]);
    }
    free(distances);
}

// Print the Levenshtein distance between two strings.
void print_levenshtein(char *s1, char *s2) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, levenshtein(s1, s2));
}

// Main function.
int main() {
    // Print the Levenshtein distance between two strings.
    print_levenshtein("hello", "world");
    print_levenshtein("kitten", "sitting");
    print_levenshtein("Levenshtein", "distance");

    return 0;
}