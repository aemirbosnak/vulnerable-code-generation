//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int min(int a, int b, int c);
int levenshtein_distance(const char *s1, const char *s2);
void print_distance_matrix(int **matrix, int rows, int cols);

int main() {
    char str1[100], str2[100];

    // Setting the scene for our adventure
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove trailing newline

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove trailing newline

    // Calculate the distance
    int distance = levenshtein_distance(str1, str2);
    printf("The mystifying Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    return 0;
}

// The minutiae of the minimum function
int min(int a, int b, int c) {
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

// The almighty Levenshtein distance function
int levenshtein_distance(const char *s1, const char *s2) {
    // Sizes of the strings
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Creating distance matrix
    int **matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++)
        matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));

    // Initializing the matrix like a crafting artisan
    for (int i = 0; i <= len1; i++)
        matrix[i][0] = i; // Cost of deletions
    for (int j = 0; j <= len2; j++)
        matrix[0][j] = j; // Cost of insertions

    // Filling the matrix with spells of transformation
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,    // Deletion
                               matrix[i][j - 1] + 1,    // Insertion
                               matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Print the crafted distance matrix for the curious souls
    print_distance_matrix(matrix, len1 + 1, len2 + 1);

    // The magic number, the distance!
    int result = matrix[len1][len2];

    // Cleaning the used memory
    for (int i = 0; i <= len1; i++)
        free(matrix[i]);
    free(matrix);
    
    return result;
}

// A dazzling display of matrix for the learned eye
void print_distance_matrix(int **matrix, int rows, int cols) {
    printf("\nDistance Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}