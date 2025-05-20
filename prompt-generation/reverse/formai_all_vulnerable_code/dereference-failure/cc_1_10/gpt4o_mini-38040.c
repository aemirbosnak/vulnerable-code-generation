//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

// Function to compute the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **matrix = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        matrix[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len_s1; i++) {
        matrix[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_s2; j++) {
        matrix[0][j] = j; // Insertion
    }

    // Populate the matrix
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,    // Deletion
                               matrix[i][j - 1] + 1,    // Insertion
                               matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = matrix[len_s1][len_s2];

    // Clean up memory
    for (int i = 0; i <= len_s1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *s1 = argv[1];
    const char *s2 = argv[2];

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);
    
    return EXIT_SUCCESS;
}