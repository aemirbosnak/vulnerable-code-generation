//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate minimum of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// Function to calculate Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a matrix to store the distances
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j; // Insertion cost
    }

    // Compute the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Cost of substitution
            d[i][j] = min(d[i - 1][j] + 1,     // Deletion
                           d[i][j - 1] + 1,     // Insertion
                           d[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Store the result
    int distance = d[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to read a string from standard input
void read_string(char *buffer, int size) {
    printf("Enter a string (max %d characters): ", size - 1);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
    } else {
        fprintf(stderr, "Error reading string.\n");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    const int max_length = 100;

    // Allocate buffers for input strings
    char *str1 = (char *)malloc(max_length * sizeof(char));
    char *str2 = (char *)malloc(max_length * sizeof(char));

    // Read first string
    read_string(str1, max_length);

    // Read second string
    read_string(str2, max_length);

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Display result
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    // Free allocated memory
    free(str1);
    free(str2);

    return 0;
}