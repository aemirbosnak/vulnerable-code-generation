//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int **initializeMatrix(int len1, int len2);
void freeMatrix(int **matrix, int len1);
int levenshteinDistance(const char *str1, const char *str2);
void displayResult(const char *str1, const char *str2, int distance);

int main() {
    char str1[100], str2[100];
    
    // User input
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character
    
    int distance = levenshteinDistance(str1, str2);
    displayResult(str1, str2, distance);
    
    return 0;
}

// Function to initialize a matrix for computing distances
int **initializeMatrix(int len1, int len2) {
    int **matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i; // Cost of deletions
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j; // Cost of insertions
    }

    return matrix;
}

// Function to free the allocated matrix
void freeMatrix(int **matrix, int len1) {
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to compute the Levenshtein Distance
int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix = initializeMatrix(len1, len2);

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1; // If characters are equal, cost is 0
            matrix[i][j] = min(matrix[i - 1][j] + 1,              // Deletion
                               matrix[i][j - 1] + 1,              // Insertion
                               matrix[i - 1][j - 1] + cost);  // Substitution
        }
    }
    
    int distance = matrix[len1][len2];
    freeMatrix(matrix, len1);
    return distance;
}

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c; // If a is the smallest
    } else {
        return (b < c) ? b : c; // If b is the smallest
    }
}

// Function to display the result
void displayResult(const char *str1, const char *str2, int distance) {
    printf("Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);
}