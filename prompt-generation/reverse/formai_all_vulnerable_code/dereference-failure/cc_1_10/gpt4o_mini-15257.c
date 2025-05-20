//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a 2D array
int** create2DArray(int rows, int cols) {
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }
    return array;
}

// Function to free the allocated memory for a 2D array
void free2DArray(int **array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

// Function to calculate the Levenshtein distance
int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a 2D array to store distances
    int **dist = create2DArray(len1 + 1, len2 + 1);

    // Initialize the distance array
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j; // Insertion cost
    }

    // Fill the distance array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            dist[i][j] = fmin(
                fmin(dist[i - 1][j] + 1, dist[i][j - 1] + 1), // Deletion and Insertion
                dist[i - 1][j - 1] + cost                       // Substitution
            );
        }
    }

    int distance = dist[len1][len2];
    free2DArray(dist, len1 + 1); // Free the allocated memory
    return distance;
}

// Function to get user input for strings
void getInputStrings(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the trailing newline

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the trailing newline
}

// Main function
int main() {
    char str1[100];
    char str2[100];

    // Get user input
    getInputStrings(str1, str2);

    // Calculate Levenshtein distance
    int distance = levenshteinDistance(str1, str2);

    // Output the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}