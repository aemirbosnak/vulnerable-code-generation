//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a matrix to hold the distances
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j; // Insertion
    }

    // Fill the distance matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            dist[i][j] = min(
                dist[i-1][j] + 1,      // Deletion
                dist[i][j-1] + 1,      // Insertion
                dist[i-1][j-1] + cost  // Substitution
            );
        }
    }

    // Retrieve the Levenshtein distance
    int distance = dist[len1][len2];

    // Clean up the memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Function to read a string from user
void read_string(char *str, int maxLength) {
    printf("Enter a string (max %d characters): ", maxLength);
    fgets(str, maxLength, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character
}

// Main function
int main() {
    const int MAX_LENGTH = 100;
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    read_string(str1, MAX_LENGTH);
    read_string(str2, MAX_LENGTH);

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between:\n");
    printf("  '%s'\n", str1);
    printf("  '%s'\n", str2);
    printf("is: %d\n", distance);

    return 0;
}