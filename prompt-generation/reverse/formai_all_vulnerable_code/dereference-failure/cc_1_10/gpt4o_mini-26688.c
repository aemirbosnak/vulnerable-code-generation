//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype definitions
int min(int a, int b, int c);
int levenshtein_distance(const char *s, const char *t);
void print_matrix(int **matrix, int length_s, int length_t);
void free_matrix(int **matrix, int length_s);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *string1 = argv[1];
    const char *string2 = argv[2];

    int distance = levenshtein_distance(string1, string2);
    printf("Levenshtein Distance between \"%s\" and \"%s\": %d\n", 
            string1, string2, distance);

    return EXIT_SUCCESS;
}

// Function to compute the Levenshtein distance
int levenshtein_distance(const char *s, const char *t) {
    int length_s = strlen(s);
    int length_t = strlen(t);

    // Create a 2D array (matrix) for dynamic programming
    int **matrix = (int **)malloc((length_s + 1) * sizeof(int *));
    for (int i = 0; i <= length_s; i++) {
        matrix[i] = (int *)malloc((length_t + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= length_s; i++) {
        matrix[i][0] = i; // Deleting characters
    }
    for (int j = 0; j <= length_t; j++) {
        matrix[0][j] = j; // Inserting characters
    }

    // Compute distances
    for (int i = 1; i <= length_s; i++) {
        for (int j = 1; j <= length_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,    // Deletion
                               matrix[i][j - 1] + 1,    // Insertion
                               matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Print the constructed distance matrix
    print_matrix(matrix, length_s, length_t);
    
    // Get the final distance
    int distance = matrix[length_s][length_t];

    // Free the allocated memory
    free_matrix(matrix, length_s);

    return distance;
}

// Function to find minimum of three integers
int min(int a, int b, int c) {
    int minimum = a < b ? a : b;
    return minimum < c ? minimum : c;
}

// Function to print the matrix
void print_matrix(int **matrix, int length_s, int length_t) {
    printf("Distance Matrix:\n");
    for (int i = 0; i <= length_s; i++) {
        for (int j = 0; j <= length_t; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to free the memory allocated for the matrix
void free_matrix(int **matrix, int length_s) {
    for (int i = 0; i <= length_s; i++) {
        free(matrix[i]);
    }
    free(matrix);
}