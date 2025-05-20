//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    }
    return b < c ? b : c;
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    // Create a matrix to store distances
    int **distance = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        distance[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len_s1; i++) {
        distance[i][0] = i;  // Deletion cost
    }
    for (int j = 0; j <= len_s2; j++) {
        distance[0][j] = j;  // Insertion cost
    }

    // Calculate the distance
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;  // Substitution cost
            distance[i][j] = min(distance[i - 1][j] + 1,     // Deletion
                                 distance[i][j - 1] + 1,     // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Get the final distance value
    int result = distance[len_s1][len_s2];

    // Free allocated memory for distance matrix
    for (int i = 0; i <= len_s1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Function to read input strings and validate
void readInput(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove the newline character

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove the newline character
}

int main() {
    char str1[100], str2[100];

    // Read input strings from user
    readInput(str1, str2);

    // Calculate Levenshtein Distance
    int distance = levenshteinDistance(str1, str2);

    // Provide the results to the user
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    return 0;
}