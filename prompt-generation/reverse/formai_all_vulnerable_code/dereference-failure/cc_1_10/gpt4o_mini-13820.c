//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **distance = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        distance[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_s1; i++) {
        distance[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_s2; j++) {
        distance[0][j] = j; // Insertion
    }

    // Compute the distance
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Substitution cost
            distance[i][j] = min(distance[i - 1][j] + 1,      // Deletion
                                 distance[i][j - 1] + 1,      // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Result is in the bottom-right corner of the matrix
    int lev_distance = distance[len_s1][len_s2];

    // Free allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(distance[i]);
    }
    free(distance);

    return lev_distance;
}

// Main function to demonstrate the Levenshtein Distance calculation
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    const char *str1 = argv[1];
    const char *str2 = argv[2];

    printf("Calculating Levenshtein Distance between:\n");
    printf("'%s' and '%s'\n", str1, str2);

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}