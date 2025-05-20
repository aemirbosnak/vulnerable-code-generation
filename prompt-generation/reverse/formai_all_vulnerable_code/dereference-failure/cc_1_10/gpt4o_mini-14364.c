//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a matrix to store distances
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

    // Compute the distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,     // Deletion
                             dist[i][j - 1] + 1,     // Insertion
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

// Function to read a string from user input
char *read_string() {
    char *buffer = NULL;
    size_t size = 0;

    printf("Enter a string: ");
    getline(&buffer, &size, stdin);

    // Remove the newline character from the string, if present
    buffer[strcspn(buffer, "\n")] = 0;

    return buffer;
}

// Main function
int main() {
    printf("Levenshtein Distance Calculator\n");

    char *str1 = read_string();
    char *str2 = read_string();

    int distance = levenshtein_distance(str1, str2);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    // Free dynamically allocated memory for strings
    free(str1);
    free(str2);

    return 0;
}