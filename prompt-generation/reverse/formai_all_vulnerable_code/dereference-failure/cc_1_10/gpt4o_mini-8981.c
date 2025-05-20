//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    
    for (size_t i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }

    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = i; // Deletion cost
    }

    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = j; // Insertion cost
    }

    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1,    // Deletion
                                      matrix[i][j - 1] + 1),   // Insertion
                                      matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = matrix[len1][len2];

    for (size_t i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Function to read a string input safely
void read_string(char *str, size_t length) {
    if (fgets(str, length, stdin) != NULL) {
        str[strcspn(str, "\n")] = 0; // Remove newline character
    }
}

// Main function
int main() {
    const size_t max_length = 100;
    char str1[max_length], str2[max_length];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Enter the first string (max %zu characters): ", max_length - 1);
    read_string(str1, max_length);

    printf("Enter the second string (max %zu characters): ", max_length - 1);
    read_string(str2, max_length);

    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}