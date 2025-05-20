//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to compute the Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a 2D array to store distances
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j; // Insertion cost
    }

    // Compute the rest of the distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1; // Replacement cost
            dist[i][j] = min(dist[i - 1][j] + 1,         // Deletion
                             dist[i][j - 1] + 1,         // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dist[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Function to display usage instructions
void display_help() {
    printf("=== Levenshtein Distance Calculator ===\n");
    printf("Usage:\n");
    printf("  ./levenshtein <string1> <string2>\n");
    printf("Example:\n");
    printf("  ./levenshtein hello world\n");
    printf("========================================\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        display_help();
        return EXIT_FAILURE;
    }

    // Calculate the Levenshtein distance
    const char *string1 = argv[1];
    const char *string2 = argv[2];

    int distance = levenshtein_distance(string1, string2);
    
    // Print the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n",
           string1, string2, distance);

    return EXIT_SUCCESS;
}