//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int x, int y, int z) {
    int min_val = x;
    if (y < min_val) min_val = y;
    if (z < min_val) min_val = z;
    return min_val;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a 2D array to hold the distances
    int **distance_matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distance_matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    
    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        distance_matrix[i][0] = i; // deletion
    }
    for (int j = 0; j <= len2; j++) {
        distance_matrix[0][j] = j; // insertion
    }

    // Compute the Levenshtein distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance_matrix[i][j] = min(
                distance_matrix[i - 1][j] + 1,   // deletion
                distance_matrix[i][j - 1] + 1,   // insertion
                distance_matrix[i - 1][j - 1] + cost // substitution
            );
        }
    }

    // Retrieve the calculated distance
    int distance = distance_matrix[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);

    // Return the Levenshtein distance
    return distance;
}

int main() {
    char str1[256], str2[256];

    // Prompt the user for two strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the newline character

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Present the result to the user 
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    // End of the program
    return 0;
}