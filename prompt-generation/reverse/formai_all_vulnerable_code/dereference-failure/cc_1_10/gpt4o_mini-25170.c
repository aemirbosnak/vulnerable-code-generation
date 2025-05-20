//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    int **matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (size_t i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for (size_t i = 0; i <= len1; i++) {
        for (size_t j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j; // Deletion cost
            } else if (j == 0) {
                matrix[i][j] = i; // Insertion cost
            } else {
                int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1; // Substitution cost
                matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, // Deletion
                                           matrix[i][j - 1] + 1), // Insertion
                                           matrix[i - 1][j - 1] + cost); // Substitution
            }
        }
    }
    
    int distance = matrix[len1][len2];

    // Free up the allocated memory
    for (size_t i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Function to get user input for strings
void get_input(char *str1, size_t size1, char *str2, size_t size2) {
    printf("Enter the first string (max %zu characters): ", size1 - 1);
    fgets(str1, size1, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Enter the second string (max %zu characters): ", size2 - 1);
    fgets(str2, size2, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character
}

// Main function
int main() {
    const size_t max_length = 100;
    char str1[max_length];
    char str2[max_length];

    // Get input strings from the user
    get_input(str1, max_length, str2, max_length);

    // Calculate the Levenshtein Distance
    int distance = levenshtein_distance(str1, str2);

    // Print the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}