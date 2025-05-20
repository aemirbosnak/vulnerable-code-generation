//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int min(int a, int b, int c);
int levenshtein_distance(const char *s1, const char *s2);
void print_matrix(int **matrix, int rows, int cols);

int main() {
    char str1[100], str2[100];
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character

    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    return 0;
}

// Function to calculate the minimum of three values
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    }
    return (b < c) ? b : c;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **matrix = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        matrix[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the first row and column
    for (int i = 0; i <= len_s1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len_s2; j++) {
        matrix[0][j] = j;
    }
    
    // Calculate the distance
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, // deletion
                               matrix[i][j - 1] + 1, // insertion
                               matrix[i - 1][j - 1] + cost); // substitution
        }
    }
    
    // Uncomment to print the matrix for debugging purposes
    // print_matrix(matrix, len_s1 + 1, len_s2 + 1);
    
    int distance = matrix[len_s1][len_s2];
    
    // Free the allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Function to print the distance matrix (for debugging)
void print_matrix(int **matrix, int rows, int cols) {
    printf("Distance Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}