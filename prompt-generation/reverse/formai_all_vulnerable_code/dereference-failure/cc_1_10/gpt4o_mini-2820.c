//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three integers.
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to calculate the Levenshtein distance between two strings.
int levenshtein_distance(const char* str1, const char* str2) {
    // Get the lengths of the two strings.
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a distance matrix of size (len1 + 1) x (len2 + 1).
    int **distance = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the distance matrix.
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // Set the cost of deletions.
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Set the cost of insertions.
    }

    // Fill in the rest of the distance matrix.
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // Calculate substitution cost: 0 if the characters are the same; 1 otherwise.
            int substitution_cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            // Determine the value at distance[i][j].
            distance[i][j] = min(
                distance[i - 1][j] + 1, // Deletion
                distance[i][j - 1] + 1, // Insertion
                distance[i - 1][j - 1] + substitution_cost // Substitution
            );
        }
    }

    // Retrieve the final distance value.
    int result = distance[len1][len2];

    // Free allocated memory for the distance matrix.
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

int main() {
    // Declare variables for the two strings.
    char str1[100], str2[100];

    // Prompt user for the first string.
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove the newline character.

    // Prompt user for the second string.
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove the newline character.

    // Calculate the Levenshtein distance.
    int distance = levenshtein_distance(str1, str2);

    // Print the computed distance.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}