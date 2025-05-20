//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to calculate the minimum of three integers
int minimum(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// A function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    // Create a distance matrix
    int **matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    
    // Initialize the matrix
    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = i; // Deletion costs
    }
    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = j; // Insertion costs
    }
    
    // Fill the matrix
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = minimum(
                matrix[i - 1][j] + 1,        // Deletion
                matrix[i][j - 1] + 1,        // Insertion
                matrix[i - 1][j - 1] + cost   // Substitution
            );
        }
    }
    
    // Capture the distance
    int distance = matrix[len1][len2];

    // Free up the allocated memory
    for (size_t i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return distance;
}

// A function to get user input
void get_input_strings(char *str1, char *str2) {
    printf("Enter first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character

    printf("Enter second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the newline character
}

// The main function to execute the Levenshtein distance calculator
int main() {
    char str1[100], str2[100];
    
    printf("Welcome to the Enchanted Levenshtein Distance Calculator!\n");
    printf("Prepare to measure the distance between two mystical strings.\n\n");
    
    // Get input strings from the user
    get_input_strings(str1, str2);
    
    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    
    // Display the result
    printf("\nThe Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    printf("May your strings always find harmony!\n");

    return 0;
}