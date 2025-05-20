//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to compute the Levenshtein Distance using dynamic programming
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a distance matrix
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j; // Insertion
    }

    // Fill the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Cost for substitution
            dist[i][j] = fmin(fmin(dist[i - 1][j] + 1,       // Deletion
                                   dist[i][j - 1] + 1),      // Insertion
                                   dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Get the Levenshtein distance
    int distance = dist[len1][len2];

    // Free the distance matrix
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Function to read input strings from the user
void get_input_strings(char *str1, char *str2) {
    printf("Enter first string (max length %d): ", MAX_LEN);
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove trailing newline

    printf("Enter second string (max length %d): ", MAX_LEN);
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove trailing newline
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    // Get user input
    get_input_strings(str1, str2);

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Display the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}