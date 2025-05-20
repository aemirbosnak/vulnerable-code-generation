//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshtein_distance(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    int** distance_matrix = (int**)malloc((len1 + 1) * sizeof(int*));
    for (size_t i = 0; i <= len1; i++) {
        distance_matrix[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (size_t i = 0; i <= len1; i++) {
        distance_matrix[i][0] = i; // Deleting all characters from str1
    }
    for (size_t j = 0; j <= len2; j++) {
        distance_matrix[0][j] = j; // Inserting all characters from str2
    }

    // Calculate distances
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance_matrix[i][j] = min(
                distance_matrix[i - 1][j] + 1,     // Deletion
                distance_matrix[i][j - 1] + 1,     // Insertion
                distance_matrix[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    // Store the final distance and free memory
    int distance = distance_matrix[len1][len2];
    for (size_t i = 0; i <= len1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);

    return distance;
}

// Main function to interact with the user and perform distance calculations
int main() {
    char str1[100], str2[100];

    printf("Levenshtein Distance Calculator\n");
    printf("---------------------------------\n");

    // Input first string
    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) != NULL) {
        str1[strcspn(str1, "\n")] = 0; // Remove newline character
    }

    // Input second string
    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) != NULL) {
        str2[strcspn(str2, "\n")] = 0; // Remove newline character
    }

    // Calculate the distance
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}