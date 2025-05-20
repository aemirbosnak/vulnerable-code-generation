//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    // Create a 2D array to store the distances
    int **distance = (int **)malloc((len_s + 1) * sizeof(int *));
    for (int i = 0; i <= len_s; i++) {
        distance[i] = (int *)malloc((len_t + 1) * sizeof(int));
    }

    // Initialize the distance array
    for (int i = 0; i <= len_s; i++) {
        distance[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_t; j++) {
        distance[0][j] = j; // Insertion
    }

    // Compute the distances
    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            distance[i][j] = min(
                distance[i - 1][j] + 1,       // Deletion
                distance[i][j - 1] + 1,       // Insertion
                distance[i - 1][j - 1] + cost  // Substitution
            );
        }
    }
    
    // The distance is in the bottom-right cell
    int result = distance[len_s][len_t];

    // Free the allocated memory
    for (int i = 0; i <= len_s; i++) {
        free(distance[i]);
    }
    free(distance);
    
    return result;
}

// Main function to test the Levenshtein Distance
int main() {
    char string1[100], string2[100];
    
    printf("Enter first string: ");
    if (!fgets(string1, sizeof(string1), stdin)) {
        fprintf(stderr, "Error reading first string.\n");
        return EXIT_FAILURE;
    }
    string1[strcspn(string1, "\n")] = 0; // Remove newline character

    printf("Enter second string: ");
    if (!fgets(string2, sizeof(string2), stdin)) {
        fprintf(stderr, "Error reading second string.\n");
        return EXIT_FAILURE;
    }
    string2[strcspn(string2, "\n")] = 0; // Remove newline character

    int distance = levenshtein_distance(string1, string2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", string1, string2, distance);

    return EXIT_SUCCESS;
}