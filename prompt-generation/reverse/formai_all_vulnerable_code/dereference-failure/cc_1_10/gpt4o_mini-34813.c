//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    // Create a matrix to store distances
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (size_t i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deletion cost
    }
    for (size_t j = 0; j <= len2; j++) {
        distance[0][j] = j; // Insertion cost
    }

    // Compute the distances
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(
                distance[i - 1][j] + 1,       // Deletion
                distance[i][j - 1] + 1,       // Insertion
                distance[i - 1][j - 1] + cost  // Substitution
            );
        }
    }

    int result = distance[len1][len2];

    // Free the allocated memory
    for (size_t i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Function to read strings from the user
void read_input(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, 256, stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, 256, stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character
}

// Main execution function
int main() {
    char str1[256];
    char str2[256];

    read_input(str1, str2);

    int distance = levenshtein(str1, str2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}