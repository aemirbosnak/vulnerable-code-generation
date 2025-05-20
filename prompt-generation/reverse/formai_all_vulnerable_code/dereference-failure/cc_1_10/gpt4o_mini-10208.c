//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int minimum = a;
    if (b < minimum)
        minimum = b;
    if (c < minimum)
        minimum = c;
    return minimum;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    
    // Create a matrix to store distances
    int **matrix = (int **)malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++)
        matrix[i] = (int *)malloc((len_str2 + 1) * sizeof(int));

    // Initialize the matrix
    for (int i = 0; i <= len_str1; i++)
        matrix[i][0] = i;

    for (int j = 0; j <= len_str2; j++)
        matrix[0][j] = j;

    // Populate the matrix
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            matrix[i][j] = min(
                matrix[i - 1][j] + 1,      // Deletion
                matrix[i][j - 1] + 1,      // Insertion
                matrix[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    // Store the final Levenshtein distance
    int distance = matrix[len_str1][len_str2];

    // Free allocated memory
    for (int i = 0; i <= len_str1; i++)
        free(matrix[i]);
    free(matrix);

    return distance;
}

// Function to display the result
void display_result(const char *str1, const char *str2, int distance) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
}

// Main function to execute the program
int main() {
    // Example strings to test the Levenshtein distance calculation
    const char *stringA = "kitten";
    const char *stringB = "sitting";

    // Calculate the distance
    int distance = levenshtein_distance(stringA, stringB);

    // Display the result
    display_result(stringA, stringB, distance);

    // Optional: take user input for further examples
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    distance = levenshtein_distance(str1, str2);
    display_result(str1, str2, distance);
    
    return 0;
}