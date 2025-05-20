//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute minimum of three integers
int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

// Function to calculate the Levenshtein Distance
int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a matrix to store distances
    int **distanceMatrix = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distanceMatrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    
    // Initialize the matrix
    for (int i = 0; i <= len1; i++) {
        distanceMatrix[i][0] = i; // Deleting all characters from str1
    }
    for (int j = 0; j <= len2; j++) {
        distanceMatrix[0][j] = j; // Inserting all characters to str2
    }
    
    // Compute the distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distanceMatrix[i][j] = min(
                distanceMatrix[i - 1][j] + 1, // Deletion
                distanceMatrix[i][j - 1] + 1, // Insertion
                distanceMatrix[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    int result = distanceMatrix[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(distanceMatrix[i]);
    }
    free(distanceMatrix);

    return result;
}

// Function to get user input
void getStringInput(char *buffer, size_t size, const char *prompt) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove the newline character
        buffer[strcspn(buffer, "\n")] = 0;
    }
}

// Main function
int main() {
    // Buffer sizes for input strings
    const size_t maxSize = 100;
    char str1[maxSize];
    char str2[maxSize];

    // Getting input from the user
    getStringInput(str1, maxSize, "Enter the first string: ");
    getStringInput(str2, maxSize, "Enter the second string: ");

    // Calculate the Levenshtein distance
    int distance = levenshteinDistance(str1, str2);
    
    // Output the result
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    return 0;
}