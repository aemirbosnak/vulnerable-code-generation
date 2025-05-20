//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Create a 2D array to hold distances
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize distance array
    for (size_t i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deletion
    }
    for (size_t j = 0; j <= len2; j++) {
        distance[0][j] = j; // Insertion
    }

    // Calculate the distances
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1, // Deletion
                                 distance[i][j - 1] + 1, // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    // The distance is in the cell distance[len1][len2]
    int result = distance[len1][len2];

    // Free allocated memory (always a must-do in paranoid programming)
    for (size_t i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Main function with paranoid checks
int main(int argc, char **argv) {
    // Check if the program was provided the right number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE; // Exit with failure flag for paranoia
    }

    // Sanitize inputs (not that we trust no one, but we trust less)
    for (size_t i = 0; i < strlen(argv[1]); i++) {
        if (argv[1][i] < 32 || argv[1][i] > 126) {
            fprintf(stderr, "Invalid character in input string 1.\n");
            return EXIT_FAILURE; // Exit on error
        }
    }
    
    for (size_t j = 0; j < strlen(argv[2]); j++) {
        if (argv[2][j] < 32 || argv[2][j] > 126) {
            fprintf(stderr, "Invalid character in input string 2.\n");
            return EXIT_FAILURE; // Exit on error
        }
    }

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(argv[1], argv[2]);

    // Output the result
    printf("Levenshtein distance between \"%s\" and \"%s\" is: %d\n", argv[1], argv[2], distance);

    return EXIT_SUCCESS; // Exit successfully
}