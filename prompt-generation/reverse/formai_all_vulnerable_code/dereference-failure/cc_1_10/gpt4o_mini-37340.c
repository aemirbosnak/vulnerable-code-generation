//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int minimum = a < b ? a : b; // Start with a as minimum.
    return minimum < c ? minimum : c; // Compare with c to find the overall minimum.
}

int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    
    // Create a 2D array to hold distances.
    int **distance = malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        distance[i] = malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize the distance array.
    for (int i = 0; i <= len_str1; i++) {
        distance[i][0] = i; // Cost of deletions.
    }
    for (int j = 0; j <= len_str2; j++) {
        distance[0][j] = j; // Cost of insertions.
    }

    // Calculate distances.
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1]; // No cost if characters are equal.
            } else {
                distance[i][j] = min(distance[i - 1][j] + 1,    // Deletion
                                     distance[i][j - 1] + 1,    // Insertion
                                     distance[i - 1][j - 1] + 1); // Substitution
            }
        }
    }

    // Capture the final distance result.
    int result = distance[len_str1][len_str2];

    // Free the allocated memory.
    for (int i = 0; i <= len_str1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result; // Return the computed distance.
}

int main() {
    // Let us interact with the user.
    char str1[100], str2[100];
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character.

    printf("Now enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the newline character.

    // Here the profound moment transpired as we unveil the edit distance.
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    // We leave the user with insight and knowledge gained.
    printf("Thank you for using the Levenshtein Distance Calculator! Have a great day!\n");

    return 0;
}