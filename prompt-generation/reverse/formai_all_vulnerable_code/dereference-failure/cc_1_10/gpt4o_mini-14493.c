//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a matrix to hold distances
    int **distance_matrix = (int **) malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        distance_matrix[i] = (int *) malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len_s1; i++) {
        distance_matrix[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len_s2; j++) {
        distance_matrix[0][j] = j; // Insertion cost
    }

    // Populate the distance matrix
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            // Cost for substitution
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; 
            distance_matrix[i][j] = min(
                distance_matrix[i - 1][j] + 1,       // Deletion
                distance_matrix[i][j - 1] + 1,       // Insertion
                distance_matrix[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    // Get the final Levenshtein distance
    int distance = distance_matrix[len_s1][len_s2];

    // Free allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);

    return distance;
}

// Helper function to get user input
void get_user_input(char *s1, char *s2) {
    printf("Enter the first string: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = 0;  // Remove newline character

    printf("Enter the second string: ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = 0;  // Remove newline character
}

// Main function to run the program
int main() {
    char str1[100], str2[100];

    // Get user input for the strings
    get_user_input(str1, str2);

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Output the result
    printf("Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);
    
    return 0;
}