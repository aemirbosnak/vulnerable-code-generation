//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to compute the Levenshtein distance
int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deletion from str1
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Insertion to str1
    }

    // Calculate Levenshtein distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,      // Deletion
                                 distance[i][j - 1] + 1,      // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = distance[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Function to read a string from standard input
void readString(char *buffer, size_t size) {
    printf("Enter a string (max %zu characters): ", size - 1);
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove newline character
        }
    }
}

// Main function
int main() {
    const size_t MAX_STRING_LENGTH = 100;
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];

    printf("Levenshtein Distance Calculator\n");
    printf("===============================\n");

    readString(str1, MAX_STRING_LENGTH);
    readString(str2, MAX_STRING_LENGTH);
    
    int distance = levenshteinDistance(str1, str2);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    return 0;
}